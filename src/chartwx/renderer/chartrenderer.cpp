/********************************************************************************
 *                                                                              *
 * chartwx - renderer base class                                                *
 *                                                                              *
 * modified: 2024-07-27                                                          *
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

#include "chartrenderer.h"

namespace chartwx {

ChartRenderer::ChartRenderer(ChartObject* parent):ChartObject(parent)
{
}

ChartRenderer::~ChartRenderer()
{
}

void ChartRenderer::Clear()
{
  datasets.clear();
  xrange = Range();
  yrange = Range();
}

void ChartRenderer::AddDataSet(std::shared_ptr<DataSet>& ds)
{
  datasets.push_back(ds);
  xrange.Add(ds->GetXRange());
  yrange.Add(ds->GetYRange());
}

Range ChartRenderer::GetXRange() const
{
  return xrange;
}

Range ChartRenderer::GetYRange() const
{
  return yrange;
}


} // namespace chartwx
