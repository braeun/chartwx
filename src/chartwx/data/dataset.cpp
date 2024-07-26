/********************************************************************************
 *                                                                              *
 * chartwx - data set base class                                                *
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

#include "dataset.h"

namespace chartwx {

DataSet::DataSet()
{
}

DataSet::DataSet(const std::string& name):
  name(name)
{
}

DataSet::~DataSet()
{
}

const std::string& DataSet::GetName() const
{
  return name;
}

void DataSet::SetName(const std::string& n)
{
  name = n;
}

bool DataSet::IsEmpty() const
{
  return GetSize() == 0;
}

Range DataSet::GetXRange() const
{
  Range r;
  for (size_t i=0;i<GetSize();i++)
  {
    r.Add(GetX(i));
  }
  return r;
}

Range DataSet::GetYRange() const
{
  Range r;
  for (size_t i=0;i<GetSize();i++)
  {
    r.Add(GetY(i));
  }
  return r;
}


} // namespace chartwx
