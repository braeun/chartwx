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

#include "valueformatter.h"
#include <wx/dcmemory.h>
#include <cstdio>

namespace chartwx {

ValueFormatter::ValueFormatter() {}

ValueFormatter::~ValueFormatter()
{
}

wxBitmap ValueFormatter::Draw(const wxDC& dc, double v) const
{
  std::string s = Format(v);
  if (s.empty()) return wxNullBitmap;
  wxSize size = dc.GetTextExtent(s);
  wxBitmap bitmap(size);
  wxMemoryDC bdc(bitmap);
  bdc.CopyAttributes(dc);
  bdc.Clear();
  bdc.DrawText(s,0,0);
  return bitmap;
}

DefaultValueFormatter::DefaultValueFormatter(const std::string& format):
  pattern(format)
{
}

DefaultValueFormatter::~DefaultValueFormatter()
{
}

std::string DefaultValueFormatter::Format(double v) const
{
  static char buffer[128];
  snprintf(buffer,sizeof(buffer),pattern.c_str(),v);
  return buffer;
}


} // namespace chartwx
