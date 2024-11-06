/********************************************************************************
 *                                                                              *
 * chartwx - renderer base class                                                *
 *                                                                              *
 * modified: 2024-11-06                                                         *
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

#ifndef CHARTWX_PLOTRENDERER_H
#define CHARTWX_PLOTRENDERER_H

#include "../chartobject.h"
#include "../data/dataset.h"
#include <wx/dc.h>
#include <memory>
#include <vector>

namespace chartwx {

class ChartRenderer: public ChartObject
{
public:
  ChartRenderer(ChartObject* parent=nullptr);
  virtual ~ChartRenderer();

  virtual void Clear();

  virtual void AddDataSet(std::shared_ptr<DataSet> ds);

  virtual Range GetXRange() const;

  virtual Range GetYRange() const;

protected:
  std::vector<std::shared_ptr<DataSet>> datasets;
};

} // namespace chartwx

#endif // CHARTWX_PLOTRENDERER_H
