/********************************************************************************
 *                                                                              *
 * chartwx - XY renderer                                                        *
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

#include "xychartrenderer.h"
#include "../scale.h"

namespace chartwx {

XYChartRenderer::XYChartRenderer(ChartObject* parent):ChartRenderer(parent)
{
}

void XYChartRenderer::Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const
{
  if (!xtrans || ! ytrans) return;
  size_t n = 0;
  for (const auto& ds : datasets)
  {
    if (ds->IsEmpty() || ds->GetSize() < 2) continue;
    size_t index = n % GetStyle().GetPalette().size();
    dc.SetPen(GetStyle().GetPalette()[index]);
    std::vector<wxPoint> points;
    for (size_t index=0;index<ds->GetSize();++index)
    {
      wxPoint p;
      p.x = xtrans->ToScreen(ds->GetX(index));
      p.y = ytrans->ToScreen(ds->GetY(index));
      points.push_back(p);
    }
    dc.DrawLines(points.size(),points.data());
  }
}

} // namespace chartwx


