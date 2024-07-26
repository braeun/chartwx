/********************************************************************************
 *                                                                              *
 * chartwx - scales transforming world <-> screen coordinates                   *
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

#ifndef CHARTWX_TRANSFORM_H
#define CHARTWX_TRANSFORM_H

#include "enums.h"
#include "axis/tick.h"
#include "data/range.h"


namespace chartwx {

class Scale
{
public:
  Scale(Direction dir);
  virtual ~Scale();

  Direction GetDirection() const;

  virtual int ToScreen(double v) const = 0;

  virtual void UpdatePixels(int p);

  virtual std::vector<TickValue> GetTicks() const;

protected:
  Direction dir;
  unsigned int pixels;
};


class NumericScale: public Scale
{
public:
  NumericScale(Direction dir);
  virtual ~NumericScale();

  virtual void UpdateRange(Range r);

  const Range& GetRange() const;

protected:
  Range range;

};


class LinearScale: public NumericScale
{
public:
  LinearScale(Direction dir);
  virtual ~LinearScale();

  virtual int ToScreen(double v) const override;

  virtual void UpdateRange(Range r) override;

  virtual void UpdatePixels(int p) override;

  virtual std::vector<TickValue> GetTicks() const override;

private:
  double GetMajorTickStep(const Range& r) const;

  double scale;
};



class LogarithmicScale: public NumericScale
{
public:
  LogarithmicScale(Direction dir);
  virtual ~LogarithmicScale();

  virtual int ToScreen(double v) const override;

  virtual void UpdateRange(Range r) override;

  virtual void UpdatePixels(int p) override;

  virtual std::vector<TickValue> GetTicks() const override;

private:
  double scale;
};

} // namespace chartwx

#endif // CHARTWX_TRANSFORM_H
