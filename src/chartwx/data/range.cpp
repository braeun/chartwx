/********************************************************************************
 *                                                                              *
 * chartwx - range                                                              *
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

#include "range.h"
#include <algorithm>
#include <limits>

namespace chartwx {

Range::Range():
  min(std::numeric_limits<double>::max()),
  max(-std::numeric_limits<double>::max())
{
}

Range::Range(double min, double max):
  min(min),
  max(max)
{
}

double Range::GetMin() const
{
  return min;
}

double Range::GetMax() const
{
  return max;
}

void Range::Add(double v)
{
  min = std::min(min,v);
  max = std::max(max,v);
}

void Range::Add(const Range& range)
{
  if (range)
  {
    min = std::min(min,range.min);
    max = std::max(max,range.min);
    min = std::min(min,range.max);
    max = std::max(max,range.max);
  }
}

} // namespace chartwx
