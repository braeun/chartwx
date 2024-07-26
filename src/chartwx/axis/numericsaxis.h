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

#ifndef CHARTWX_NUMERICSAXIS_H
#define CHARTWX_NUMERICSAXIS_H

#include "axis.h"
#include "tick.h"
#include "../data/range.h"
#include <memory>

namespace chartwx {

class NumericScale;

class NumericsAxis: public Axis
{
public:
  NumericsAxis(Side side, const std::string& label="");

  void SetScale(std::unique_ptr<NumericScale>&& scale);

  virtual void LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange) override;

  virtual void LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange) override;

  virtual wxSize GetSizeHint() const override;

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const override;

protected:
  void PaintHorizontal(wxDC& dc) const;
  void PaintVertical(wxDC& dc) const;

  Range range;
  std::vector<Tick> ticks;
  wxSize maxTickSize;
  wxSize sizeHint;
};



class LinearAxis: public NumericsAxis
{
public:
  LinearAxis(Side side, const std::string& label="");

};


class LogarithmicAxis: public NumericsAxis
{
public:
  LogarithmicAxis(Side side, const std::string& label="");

};



} // namespace chartwx

#endif // CHARTWX_NUMERICSAXIS_H
