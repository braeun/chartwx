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

#include "defaultdoubledataset.h"
#include <stdexcept>

namespace chartwx {

DefaultDoubleDataSet::DefaultDoubleDataSet()
{
}

DefaultDoubleDataSet::DefaultDoubleDataSet(const std::string& name):DataSet(name)
{
}

DefaultDoubleDataSet::DefaultDoubleDataSet(const std::string& name,const std::vector<double>& xvalues, const std::vector<double>& yvalues):DataSet(name)
{
  Set(xvalues,yvalues);
}

DefaultDoubleDataSet::~DefaultDoubleDataSet()
{
}

void DefaultDoubleDataSet::Clear()
{
  x.clear();
  y.clear();
  xrange = Range();
  yrange = Range();
}

void DefaultDoubleDataSet::Set(const std::vector<double>& xvalues, const std::vector<double>& yvalues)
{
  if (xvalues.size() != yvalues.size())
  {
    throw std::runtime_error("size mismatch in x and y values vector");
  }
  x = xvalues;
  y = yvalues;
  xrange = Range();
  for (double v : x) xrange.Add(v);
  yrange = Range();
  for (double v : y) yrange.Add(v);
}

void DefaultDoubleDataSet::Add(double xvalue, double yvalue)
{
  x.push_back(xvalue);
  y.push_back(yvalue);
  xrange.Add(xvalue);
  yrange.Add(yvalue);
}

size_t DefaultDoubleDataSet::GetSize() const
{
  return x.size();
}

double DefaultDoubleDataSet::GetX(size_t index) const
{
  return x[index];
}

double DefaultDoubleDataSet::GetY(size_t index) const
{
  return y[index];
}

Range DefaultDoubleDataSet::GetXRange() const
{
  return xrange;
}

Range DefaultDoubleDataSet::GetYRange() const
{
  return yrange;
}

} // namespace chartwx
