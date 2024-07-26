/********************************************************************************
 *                                                                              *
 * chartwx - value formatters                                                   *
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

#ifndef CHARTWX_VALUEFORMATTER_H
#define CHARTWX_VALUEFORMATTER_H

#include <wx/bitmap.h>
#include <wx/dc.h>
#include <string>

namespace chartwx {

class ValueFormatter
{
public:
  ValueFormatter();
  virtual ~ValueFormatter();

  virtual std::string Format(double v) const = 0;

  virtual wxBitmap Draw(const wxDC& dc, double v) const;
};


class DefaultValueFormatter: public ValueFormatter
{
public:
  DefaultValueFormatter(const std::string& format="%.4G");
  virtual ~DefaultValueFormatter();

  virtual std::string Format(double v) const override;

protected:
  std::string pattern;

};



} // namespace chartwx

#endif // CHARTWX_VALUEFORMATTER_H
