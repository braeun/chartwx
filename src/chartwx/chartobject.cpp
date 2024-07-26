/********************************************************************************
 *                                                                              *
 * chartwx - chart object base class                                            *
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

#include "chartobject.h"

namespace chartwx {

ChartObject::ChartObject()
{
}

const wxRect ChartObject::GetArea() const
{
  return area;
}

void ChartObject::SetArea(const wxRect& r)
{
  area = r;
}

void ChartObject::SetArea(int x, int y, int w, int h)
{
  area = wxRect(x,y,w,h);
}


void ChartObject::LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange)
{
}

void ChartObject::LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange)
{
}

wxSize ChartObject::GetSizeHint() const
{
  return wxSize(-1,-1);
}

} // namespace chartwx
