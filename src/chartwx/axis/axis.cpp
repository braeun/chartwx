/********************************************************************************
 *                                                                              *
 * chartwx - axis base class                                                    *
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

#include "axis.h"
#include "../scale.h"

namespace chartwx {

Axis::Axis(Side side, const std::string& label):
  side(side),
  label(label)
{
  valueFormatter = std::make_unique<DefaultValueFormatter>();
}

Axis::~Axis()
{
}

Side Axis::GetSide() const
{
  return side;
}

Scale* Axis::GetScale() const
{
  return scale.get();
}

ValueFormatter* Axis::GetValueFormatter() const
{
  return valueFormatter.get();
}

void Axis::SetValueFormatter(std::unique_ptr<ValueFormatter>&& fmt)
{
  valueFormatter = std::move(fmt);
}

} // namespace chartwx
