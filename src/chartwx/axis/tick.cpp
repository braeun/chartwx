/********************************************************************************
 *                                                                              *
 * chartwx - axis tick class                                                    *
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

#include "tick.h"

namespace chartwx {

const int ticklength = 5;

Tick::Tick() {}

Tick::Tick(Side side, const TickValue& v, const std::string& txt, const wxBitmap& txtBitmap):
  side(side),
  type(v.type),
  v(v.v),
  txt(txt),
  txtBitmap(txtBitmap)
{
  area = wxRect(txtBitmap.GetSize());
  switch (side)
  {
    case Side::Left:
    case Side::Right:
      area.SetWidth(area.GetWidth()+ticklength);
      break;
    case Side::Bottom:
    case Side::Top:
      area.SetHeight(area.GetHeight()+ticklength);
      break;
  }
}

wxSize Tick::GetSizeHint() const
{
  return area.GetSize();
}

void Tick::Paint(wxDC& dc, const Scale* /*xtrans*/, const Scale* /*ytrans*/) const
{
  if (side == Side::Left)
  {
    dc.DrawLine(-ticklength,0,0,0);
    dc.DrawBitmap(txtBitmap,-txtBitmap.GetWidth()-ticklength,-txtBitmap.GetHeight()/2);
  }
  else if (side == Side::Left)
  {
    dc.DrawLine(0,0,ticklength,0);
    dc.DrawBitmap(txtBitmap,ticklength,-txtBitmap.GetHeight()/2);
  }
  else if (side == Side::Bottom)
  {
    dc.DrawLine(0,0,0,ticklength);
    dc.DrawBitmap(txtBitmap,-txtBitmap.GetWidth()/2,ticklength);
  }
  else if (side == Side::Top)
  {
    dc.DrawLine(0,0,0,-ticklength);
    dc.DrawBitmap(txtBitmap,-txtBitmap.GetWidth()/2,-ticklength-txtBitmap.GetHeight());
  }
}

} // namespace chartwx

