/********************************************************************************
 *                                                                              *
 * chartwx - axis base class                                                    *
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

#ifndef CHARTWX_AXIS_H
#define CHARTWX_AXIS_H

#include "../chartobject.h"
#include "../enums.h"
#include "../valueformatter.h"
#include <memory>

namespace chartwx {

class Range;

class Axis: public ChartObject
{
public:
  Axis(Side side, const std::string& label="", ChartObject* parent=nullptr);
  virtual ~Axis();

  Side GetSide() const;

  Scale* GetScale() const;

  const std::string& GetLabel() const;

  void SetLabel(const std::string& lbl);

  ValueFormatter* GetValueFormatter() const;

  void SetValueFormatter(std::unique_ptr<ValueFormatter>&& fmt);

protected:
  Side side;
  std::string label;
  std::unique_ptr<ValueFormatter> valueFormatter;
  std::unique_ptr<Scale> scale;

};

} // namespace chartwx

#endif // CHARTWX_AXIS_H
