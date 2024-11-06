/********************************************************************************
 *                                                                              *
 * chartwx - classes for numeric axes                                           *
 *                                                                              *
 * modified: 2024-07-26                                                         *
 *                                                                              *
 ********************************************************************************
 * Copyright (C) Harald Braeuning                                               *
 ********************************************************************************
 * This file is part of 'chartwx'.                                              *
 * 'chartwx' is free software: you can redistribute it and/or modify it         *
 * under the terms of the GNU General Public License as published by the Free   *
 * Software Foundation, either version 3 of the License, or (at your option)    *
 * any later version.                                                           *
 * 'chartwx' is distributed in the hope that it will be useful, but             *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY   *
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for  *
 * more details.                                                                *
 * You should have received a copy of the GNU General Public License along with *
 * imca. If not, see <https://www.gnu.org/licenses/>.                           *
 ********************************************************************************/

#include "numericaxis.h"
#include "../scale.h"
#include <stdexcept>

namespace chartwx {

NumericsAxis::NumericsAxis(Side side, const std::string& label, ChartObject* parent):Axis(side,label,parent)
{
}

void NumericsAxis::SetScale(std::unique_ptr<NumericScale>&& scl)
{
  if (side == Side::Left || side == Side::Right)
  {
    if (scl->GetDirection() != Direction::Vertical) throw std::runtime_error("Axis requires a vertical scale");
  }
  else
  {
    if (scl->GetDirection() != Direction::Horizontal) throw std::runtime_error("Axis requires a horizontal scale");
  }
  scale = std::move(scl);
}

void NumericsAxis::LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange)
{
  const Range& r = (side == Side::Left || side == Side::Right) ? yrange : xrange;
  NumericScale* numscale = dynamic_cast<NumericScale*>(scale.get());
  numscale->UpdateRange(r);
  auto tickvalues = numscale->GetTicks();
  dc.SetTextForeground(GetStyle().GetTextColour());
  ticks.clear();
  for (const auto& tv : tickvalues)
  {
    Tick tick(side,tv,valueFormatter->Format(tv.v),valueFormatter->Draw(dc,tv.v),this);
    ticks.push_back(tick);
    maxTickSize.IncTo(tick.GetSizeHint());
  }
  if (side == Side::Left || side == Side::Right)
  {
    int w = maxTickSize.GetWidth();
    if (!label.empty()) w += dc.GetFontMetrics().height;
    sizeHint = wxSize(w,-1);
  }
  else
  {
    int h = maxTickSize.GetHeight();
    if (!label.empty()) h += dc.GetFontMetrics().height;
    sizeHint = wxSize(-1,h);
  }
}

void NumericsAxis::LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange)
{
  if (side == Side::Left || side == Side::Right)
    scale->UpdatePixels(area.GetHeight());
  else
    scale->UpdatePixels(area.GetWidth());
}

wxSize NumericsAxis::GetSizeHint() const
{
  return sizeHint;
}

// std::unique_ptr<Scale> NumericsAxis::calculateScale(const Range& r, unsigned int pixels)
// {
//   range = r;
//   if (side == Side::Left || side == Side::Right)
//     return std::make_unique<LinearScale>(Direction::Vertical,r,pixels);
//   return std::make_unique<LinearScale>(Direction::Horizontal,r,pixels);
// }

void NumericsAxis::Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const
{
  switch (side)
  {
    case Side::Left:
    case Side::Right:
      PaintVertical(dc);
      break;
    case Side::Bottom:
    case Side::Top:
      PaintHorizontal(dc);
      break;
  }
}

void NumericsAxis::PaintHorizontal(wxDC& dc) const
{
  int y = 0;
  if (side == Side::Top) y = GetArea().GetHeight();
  int w = GetArea().GetWidth();
  //  int h = GetArea().GetHeight();
  dc.SetPen(GetStyle().GetAxisLinePen());
  dc.DrawLine(0,y,w,y);
  auto save = dc.GetTransformMatrix();
  for (const Tick& t : ticks)
  {
    int xs = scale->ToScreen(t.GetValue());
    auto tfm = save;
    tfm.Translate(xs,y);
    dc.SetTransformMatrix(tfm);
    t.Paint(dc,scale.get(),scale.get());
    // dc.DrawLine(xs,y,xs,y+majorTickLength);
    // wxBitmap bmp = t.GetTextBitmap();
    // dc.DrawBitmap(bmp,xs-bmp.GetWidth()/2,y0);
    //    dc.DrawText(t.txt,xs-dc.GetTextExtent(t.txt).GetWidth()/2,y0);
  }
  dc.SetTransformMatrix(save);
  if (!label.empty())
  {
    dc.SetTextForeground(GetStyle().GetTextColour());
    int y0 = (side == Side::Bottom) ? maxTickSize.GetHeight() : -maxTickSize.GetHeight();
    dc.DrawText(label,(GetArea().GetWidth()-dc.GetTextExtent(label).GetWidth())/2,y0);
  }
}

void NumericsAxis::PaintVertical(wxDC& dc) const
{
  int x = 0;
  if (side == Side::Left) x = GetArea().GetWidth();
  //  int w = GetArea().GetWidth();
  int h = GetArea().GetHeight();
  dc.SetPen(GetStyle().GetAxisLinePen());
  dc.DrawLine(x,0,x,h);
  auto save = dc.GetTransformMatrix();
  for (const Tick& t : ticks)
  {
    int ys = scale->ToScreen(t.GetValue());
    auto tfm = save;
    tfm.Translate(x,ys);
    dc.SetTransformMatrix(tfm);
    t.Paint(dc,scale.get(),scale.get());
    // dc.DrawLine(x,ys,x+majorTickLength,ys);
    // wxBitmap bmp = t.GetTextBitmap();
    // int x0 = (side == Side::Left) ? x - bmp.GetWidth() : x + majorTickLength;
    // dc.DrawBitmap(bmp,x0,ys-bmp.GetHeight()/2);
    //    dc.DrawText(t.txt,x0,ys-dc.GetFontMetrics().height/2);
  }
  dc.SetTransformMatrix(save);
  if (!label.empty())
  {
    int xl = (side == Side::Left) ? x-maxTickSize.GetWidth()-dc.GetFontMetrics().height : maxTickSize.GetWidth();
    dc.SetTextForeground(GetStyle().GetTextColour());
    dc.DrawRotatedText(label,xl,(GetArea().GetHeight()+dc.GetTextExtent(label).GetWidth())/2,90);
  }
}



LinearAxis::LinearAxis(Side side, const std::string& label, ChartObject* parent):NumericsAxis(side,label,parent)
{
  if (side == Side::Left || side == Side::Right)
    scale = std::make_unique<LinearScale>(Direction::Vertical);
  else
    scale = std::make_unique<LinearScale>(Direction::Horizontal);
}



LogarithmicAxis::LogarithmicAxis(Side side, const std::string& label, ChartObject* parent):NumericsAxis(side,label,parent)
{
  if (side == Side::Left || side == Side::Right)
    scale = std::make_unique<LogarithmicScale>(Direction::Vertical);
  else
    scale = std::make_unique<LogarithmicScale>(Direction::Horizontal);
}



} // namespace chartwx
