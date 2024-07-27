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

#include "style.h"
#include <wx/dcscreen.h>
#include <wx/settings.h>
#include <iostream>

namespace chartwx {

std::unique_ptr<Style> Style::defaultStyle;

Style::Style()
{
  auto color = wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT);
  textForeground = color;
  axisline = wxPen(color);
  tickline = wxPen(color);
  palette.push_back(wxPen(*wxBLUE_PEN));
  palette.push_back(wxPen(*wxRED_PEN));
  palette.push_back(wxPen(*wxGREEN_PEN));
}

Style::Style(const Style& style):
  textForeground(style.textForeground),
  axisline(style.axisline),
  tickline(style.tickline),
  palette(style.palette)
{
}

void Style::SetTextColor(const wxColour& c)
{
  textForeground = c;
}

const wxColour& Style::GetTextColour() const
{
  return textForeground;
}

void Style::SetAxisLinePen(const wxPen& pen)
{
  axisline = pen;
}

const wxPen& Style::GetAxisLinePen() const
{
  return axisline;
}

void Style::SetTickLinePen(const wxPen& pen)
{
  tickline = pen;
}

const wxPen& Style::GetTickLinePen() const
{
  return tickline;
}

void Style::copyFromDC(const wxDC& dc)
{
  textForeground = dc.GetTextForeground();
  axisline = wxPen(dc.GetTextForeground());
  tickline = wxPen(dc.GetTextForeground());
}

void Style::SetPalette(const std::vector<wxPen>& p)
{
  palette = p;
}

const std::vector<wxPen> Style::GetPalette() const
{
  return palette;
}


void Style::SetDefaultStyle(const Style& style)
{
  defaultStyle.reset(new Style(style));
}


const Style& Style::GetDefaultStyle()
{
  if (!defaultStyle)
  {
    defaultStyle.reset(new Style());
  }
  return *defaultStyle;
}

} // namespace chartwx

