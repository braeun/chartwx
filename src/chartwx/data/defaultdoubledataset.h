/********************************************************************************
 *                                                                              *
 * chartwx - generic data set based on vectors of doubles                       *
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

#ifndef CHARTWX_DEFAULTDOUBLEDATASET_H
#define CHARTWX_DEFAULTDOUBLEDATASET_H

#include "dataset.h"
#include <vector>

namespace chartwx {

class DefaultDoubleDataSet: public DataSet
{
public:
  DefaultDoubleDataSet();
  DefaultDoubleDataSet(const std::string& name);
  DefaultDoubleDataSet(const std::string& name,const std::vector<double>& xvalues, const std::vector<double>& yvalues);
  virtual ~DefaultDoubleDataSet();

  void Clear();

  void Set(const std::vector<double>& xvalues, const std::vector<double>& yvalues);

  void Add(double xvalue, double yvalue);

  virtual size_t GetSize() const override;

  virtual double GetX(size_t index) const override;

  virtual double GetY(size_t index) const override;

  virtual Range GetXRange() const override;

  virtual Range GetYRange() const override;

protected:
  std::vector<double> x;
  std::vector<double> y;
  Range xrange;
  Range yrange;
};

} // namespace chartwx

#endif // CHARTWX_DEFAULTDOUBLEDATASET_H
