/********************************************************************************
 *                                                                              *
 * chartwx - main chart class                                                   *
 *                                                                              *
 * modified: 2024-07-27                                                         *
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

#include "chart.h"
#include "scale.h"
#include "axis/axis.h"
#include "renderer/chartrenderer.h"

namespace chartwx {

Chart::Chart(ChartObject* parent):ChartObject(parent),
  forceZeroInRange(false)
{
}

Chart::Chart(std::shared_ptr<Axis> axis1, std::shared_ptr<Axis> axis2,ChartObject* parent):ChartObject(parent),
  forceZeroInRange(false)
{
  axes.push_back(axis1);
  axes.push_back(axis2);
}

Chart::~Chart()
{
}

bool Chart::IsForceZeroInRange() const
{
  return forceZeroInRange;
}

void Chart::SetForceZeroInRange(bool flag)
{
  forceZeroInRange = flag;
}


size_t Chart::GetAxisCount(Side side) const
{
  size_t cnt = 0;
  for (const auto& a : axes)
  {
    if (a->GetSide() == side) ++cnt;
  }
  return cnt;
}

size_t Chart::GetAxisCount(Direction dir) const
{
  size_t cnt = 0;
  if (dir == Direction::Horizontal)
  {
    for (const auto& a : axes)
    {
      if (a->GetSide() == Side::Bottom || a->GetSide() == Side::Top) ++cnt;
    }
  }
  else
  {
    for (const auto& a : axes)
    {
      if (a->GetSide() == Side::Left || a->GetSide() == Side::Right) ++cnt;
    }
  }
  return cnt;
}

std::shared_ptr<Axis> Chart::GetAxis(Side side, size_t index) const
{
  for (const auto& a : axes)
  {
    if (a->GetSide() == side)
    {
      if (index == 0) return a;
      --index;
    }
  }
  return std::shared_ptr<Axis>();
}

std::shared_ptr<Axis> Chart::GetAxis(Direction dir, size_t index) const
{
  if (dir == Direction::Horizontal)
  {
    for (const auto& a : axes)
    {
      if (a->GetSide() == Side::Bottom || a->GetSide() == Side::Top)
      {
        if (index == 0) return a;
        --index;
      }
    }
  }
  else
  {
    for (const auto& a : axes)
    {
      if (a->GetSide() == Side::Left || a->GetSide() == Side::Right)
      {
        if (index == 0) return a;
        --index;
      }
    }
  }
  return std::shared_ptr<Axis>();
}

size_t Chart::GetRendererCount() const
{
  return renderers.size();
}

std::shared_ptr<ChartRenderer> Chart::GetRenderer(size_t index) const
{
  if (index < renderers.size()) return renderers[index];
  return std::shared_ptr<ChartRenderer>();
}

void Chart::AddAxis(const std::shared_ptr<Axis>& axis)
{
  axes.push_back(axis);
}

void Chart::AddRenderer(const std::shared_ptr<ChartRenderer>& renderer)
{
  renderers.push_back(renderer);
}

void Chart::Layout(wxDC& dc, const wxSize& size)
{
  Range xrange;
  Range yrange;
  for (const auto& r : renderers)
  {
    xrange.Add(r->GetXRange());
    yrange.Add(r->GetYRange());
  }
  if (forceZeroInRange)
  {
    xrange.Add(0);
    yrange.Add(0);
  }
  for (const auto& a : axes)
  {
    a->LayoutPass1(dc,xrange,yrange);
  }
  for (const auto& r : renderers)
  {
    r->LayoutPass1(dc,xrange,yrange);
  }
  int wleft = 0;
  int wright = 0;
  int htop = 0;
  int hbottom = 0;
  for (const auto& a : axes)
  {
    wxSize s = a->GetSizeHint();
    switch (a->GetSide())
    {
      case Side::Left:
        wleft += s.GetWidth();
        break;
      case Side::Right:
        wright += s.GetWidth();
        break;
      case Side::Bottom:
        hbottom += s.GetHeight();
        break;
      case Side::Top:
        htop += s.GetHeight();
        break;
    }
  }
  wxRect canvas(wleft,htop,size.GetWidth()-wleft-wright,size.GetHeight()-hbottom-htop);
  int xleft = canvas.GetLeft();
  int xright = canvas.GetRight();
  int ytop = canvas.GetTop();
  int ybottom = canvas.GetBottom();
  for (const auto& a : axes)
  {
    switch (a->GetSide())
    {
      case Side::Left:
        a->SetArea(xleft-a->GetSizeHint().GetWidth(),canvas.GetTop(),a->GetSizeHint().GetWidth(),canvas.GetHeight());
        xleft -= a->GetSizeHint().GetWidth();
        break;
      case Side::Right:
        a->SetArea(xright,canvas.GetTop(),a->GetSizeHint().GetWidth(),canvas.GetHeight());
        xright += a->GetSizeHint().GetWidth();
        break;
      case Side::Bottom:
        a->SetArea(canvas.GetLeft(),ybottom,canvas.GetWidth(),a->GetSizeHint().GetHeight());
        ybottom += a->GetSizeHint().GetHeight();
        break;
      case Side::Top:
        a->SetArea(canvas.GetLeft(),ytop-a->GetSizeHint().GetHeight(),canvas.GetWidth(),a->GetSizeHint().GetHeight());
        ytop -= a->GetSizeHint().GetHeight();
        break;
    }
  }
  for (const auto& r : renderers)
  {
    r->SetArea(canvas);
  }
  for (const auto& a : axes)
  {
    a->LayoutPass2(dc,xrange,yrange);
  }
  for (const auto& r : renderers)
  {
    r->LayoutPass2(dc,xrange,yrange);
  }
  auto ax = GetAxis(Direction::Horizontal);
  xscale = ax->GetScale();
  auto ay = GetAxis(Direction::Vertical);
  yscale = ay->GetScale();
}

void Chart::Paint(wxDC& dc, const Scale* /*xtrans*/, const Scale* /*ytrans*/) const
{
  auto tfm = dc.GetTransformMatrix();
  for (const auto& a : axes)
  {
    auto newtfm = tfm;
    newtfm.Translate(a->GetArea().GetLeft(),a->GetArea().GetTop());
    dc.SetTransformMatrix(newtfm);
    a->Paint(dc,xscale,yscale);
  }
  for (const auto& r : renderers)
  {
    auto newtfm = tfm;
    newtfm.Translate(r->GetArea().GetLeft(),r->GetArea().GetTop());
    dc.SetTransformMatrix(newtfm);
    r->Paint(dc,xscale,yscale);
  }
}

} // namespace chartwx
