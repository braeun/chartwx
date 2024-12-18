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

#include "scale.h"
#include <cmath>

namespace chartwx {

Scale::Scale(Direction dir):
  dir(dir),
  pixels(0)
{
}

Scale::~Scale()
{
}

Direction Scale::GetDirection() const
{
  return dir;
}

void Scale::UpdatePixels(int p)
{
  pixels = p;
}

std::vector<TickValue> Scale::GetTicks() const
{
  return std::vector<TickValue>();
}




NumericScale::NumericScale(Direction dir):Scale(dir)
{
}

NumericScale::~NumericScale()
{
}

void NumericScale::UpdateRange(Range r)
{
  range = r;
}

const Range& NumericScale::GetRange() const
{
  return range;
}




LinearScale::LinearScale(Direction dir):NumericScale(dir),
    scale(1.0)
{
}

LinearScale::~LinearScale()
{
}

int LinearScale::ToScreen(double v) const
{
  int p = std::round((v - range.GetMin()) * scale);
  if (dir == Direction::Vertical) p = pixels - p;
  return p;
}

void LinearScale::UpdateRange(Range r)
{
  NumericScale::UpdateRange(r);
  if (r && pixels > 0)
  {
    scale = pixels / (r.GetMax() - r.GetMin());
  }
}

void LinearScale::UpdatePixels(int p)
{
  Scale::UpdatePixels(p);
  if (range && pixels > 0)
  {
    scale = pixels / (range.GetMax() - range.GetMin());
  }
}

std::vector<TickValue> LinearScale::GetTicks() const
{
  std::vector<TickValue> ticks;
  if (range)
  {
    double delta = GetMajorTickStep(range);
    double v = 0;
    if (range.GetMin() >= 0)
    {
      while (v < range.GetMin()) v += delta;
    }
    else
    {
      while (v >= range.GetMin()) v -= delta;
      v += delta;
    }
    while (v <= range.GetMax())
    {
      TickValue tv;
      tv.type = TickType::Major;
      tv.v = v;
      ticks.push_back(tv);
      v += delta;
    }
  }
  return ticks;
}

double LinearScale::GetMajorTickStep(const Range &r) const
{
  if (!r) return 1;
  double d = (r.GetMax() - r.GetMin()) / 10;
  double logd =std::log10(d);
  int e = std::floor(logd);
  double a = d - std::pow(10,e);
  double delta = 5;
  if (a < 2)
    delta = 1;
  else if (a < 4)
    delta = 2.5;
  double step = delta * std::pow(10,e);
  if ((r.GetMax() - r.GetMin()) / step > 12)
  {
    delta *= 2;
    if (delta == 2) delta = 2.5;
    step = delta * std::pow(10,e);
  }
  else if ((r.GetMax() - r.GetMin()) / step < 3)
  {
    if (delta == 1)
      delta = 0.5;
    else if (delta == 2.5)
      delta = 1;
    else
      delta = 2.5;
    step = delta * std::pow(10,e);
  }
  return step;
}





LogarithmicScale::LogarithmicScale(Direction dir):NumericScale(dir),
    scale(1.0)
{
}

LogarithmicScale::~LogarithmicScale()
{
}

int LogarithmicScale::ToScreen(double v) const
{
  if (v <= 0) v = range.GetMin() / 10.0;
  int p = std::round((std::log10(v) - std::log10(range.GetMin())) * scale);
  if (dir == Direction::Vertical) p = pixels - p;
  return p;
}

void LogarithmicScale::UpdateRange(Range r)
{
  if (r && pixels > 0)
  {
    if (r.GetMax() <= 0)
    {
      r = Range(1.0E-6,1.0);
    }
    else if (r.GetMin() <= 0)
    {
      r = Range(r.GetMax()/1.0E6,r.GetMax());
    }
    NumericScale::UpdateRange(r);
    scale = pixels / (std::log10(r.GetMax()) - std::log10(r.GetMin()));
  }
}

void LogarithmicScale::UpdatePixels(int p)
{
  Scale::UpdatePixels(p);
  if (range && pixels > 0)
  {
    scale = pixels / (std::log10(range.GetMax()) - std::log10(range.GetMin()));
  }
}

std::vector<TickValue> LogarithmicScale::GetTicks() const
{
  std::vector<TickValue> ticks;
  int lmin = std::ceil(std::log10(range.GetMin()));
  int lmax = std::floor(std::log10(range.GetMax()));
  double v = std::pow(10,lmin);
  TickValue tv;
  tv.type = TickType::Major;
  tv.v = v;
  ticks.push_back(tv);
  lmin++;
  while (lmin <= lmax)
  {
    v *= 10;
    TickValue tv;
    tv.type = TickType::Major;
    tv.v = v;
    ticks.push_back(tv);
    lmin++;
  }
  return ticks;
}



} // namespace chartwx
