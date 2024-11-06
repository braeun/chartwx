/********************************************************************************
 *                                                                              *
 * chartwx - main chart class                                                   *
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

#ifndef CHARTWX_CHART_H
#define CHARTWX_CHART_H

#include "enums.h"
#include "chartobject.h"
#include "scale.h"
#include <memory>
#include <vector>

namespace chartwx {

class Axis;
class ChartRenderer;
class Scale;

class Chart: public ChartObject
{
public:
  /**
   * @brief Create a chart with a linear x and y axis.
   * @param parent
   */
  Chart(ChartObject* parent=nullptr);

  Chart(std::shared_ptr<Axis> axis1, std::shared_ptr<Axis> axis2,ChartObject* parent=nullptr);
  virtual ~Chart();

  bool IsForceZeroInRange() const;

  void SetForceZeroInRange(bool flag);

  size_t GetAxisCount(Side side) const;

  size_t GetAxisCount(Direction dir) const;

  std::shared_ptr<Axis> GetAxis(Side side, size_t index=0) const;

  std::shared_ptr<Axis> GetAxis(Direction dir, size_t index=0) const;

  size_t GetRendererCount() const;

  std::shared_ptr<ChartRenderer> GetRenderer(size_t index=0) const;

  virtual void AddAxis(const std::shared_ptr<Axis>& axis);

  virtual void AddRenderer(const std::shared_ptr<ChartRenderer>& renderer);

  virtual void Layout(wxDC& dc, const wxSize& size);

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const override;

protected:
  Scale* xscale;
  Scale* yscale;
  std::vector<std::shared_ptr<Axis>> axes;
  std::vector<std::shared_ptr<ChartRenderer>> renderers;
  bool forceZeroInRange;

};

} // namespace chartwx

#endif // CHARTWX_CHART_H
