/********************************************************************************
 *                                                                              *
 * chartwx - renderer base class                                                *
 *                                                                              *
 * modified: 2024-11-06                                                          *
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
}

void ChartRenderer::AddDataSet(std::shared_ptr<DataSet> ds)
{
  datasets.push_back(ds);
}

Range ChartRenderer::GetXRange() const
{
  Range range;
  for (const auto& ds : datasets)
  {
    range.Add(ds->GetXRange());
  }
  return range;
}

Range ChartRenderer::GetYRange() const
{
  Range range;
  for (const auto& ds : datasets)
  {
    range.Add(ds->GetYRange());
  }
  return range;
}


} // namespace chartwx
