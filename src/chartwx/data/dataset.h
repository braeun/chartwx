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

#ifndef CHARTWX_DATASET_H
#define CHARTWX_DATASET_H

#include "range.h"
#include <string>

namespace chartwx {

class DataSet
{
public:
  DataSet();
  DataSet(const std::string& name);
  virtual ~DataSet();

  const std::string& GetName() const;

  void SetName(const std::string& n);

  virtual bool IsEmpty() const;

  virtual size_t GetSize() const = 0;

  virtual double GetX(size_t index) const = 0;

  virtual double GetY(size_t index) const = 0;

  virtual Range GetXRange() const;

  virtual Range GetYRange() const;

protected:
  std::string name;
};

} // namespace chartwx

#endif // CHARTWX_DATASET_H
