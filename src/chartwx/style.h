/********************************************************************************
 *                                                                              *
 * chartwx - style definition                                                   *
 *                                                                              *
 * modified: 2024-07-27                                                         *
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

#ifndef STYLE_H
#define STYLE_H

#include <wx/colour.h>
#include <wx/pen.h>
#include <memory>
#include <vector>

namespace chartwx {

class Style
{
public:
//  Style(const Style& style);

  void SetTextColor(const wxColour& c);

  const wxColour& GetTextColour() const;

  void SetAxisLinePen(const wxPen& pen);

  const wxPen& GetAxisLinePen() const;

  void SetTickLinePen(const wxPen& pen);

  const wxPen& GetTickLinePen() const;

  void SetPalette(const std::vector<wxPen>& p);

  const std::vector<wxPen> GetPalette() const;

  void copyFromDC(const wxDC& dc);

  static void SetDefaultStyle(const Style& style);

  static const Style& GetDefaultStyle();

private:
  Style();

  wxColour textForeground;
  wxPen axisline;
  wxPen tickline;
  std::vector<wxPen> palette;

  static std::unique_ptr<Style> defaultStyle;
};

} // namespace chartwx

#endif // STYLE_H
