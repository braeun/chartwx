/********************************************************************************
 *                                                                              *
 * chartwx - axis tick class                                                    *
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

#ifndef CHARTWX_TICK_H
#define CHARTWX_TICK_H

#include "../chartobject.h"
#include "../enums.h"
#include <wx/bitmap.h>
#include <string>

namespace chartwx {

enum class TickType { Major, Minor };

struct TickValue
{
  TickType type;
  double v;
};

class Tick: public ChartObject
{
public:
  Tick();
  Tick(Side side, const TickValue& v, const std::string& txt, const wxBitmap& txtBitmap);

  inline double GetValue() const;

  inline const std::string& GetText() const;

  inline wxBitmap GetTextBitmap() const;

  inline wxSize GetTextSize() const;

  virtual wxSize GetSizeHint() const;

  /**
   * @brief Paint the tick.
   *
   * This method assumes, that the origin is at the point, where the tick line meets the axis line.
   * @param dc
   * @param xtrans
   * @param ytrans
   */
  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const override;

private:
  Side side;
  TickType type;
  double v;
  std::string txt;
  wxBitmap txtBitmap;

};


double Tick::GetValue() const
{
  return v;
}

const std::string& Tick::GetText() const
{
  return txt;
}

wxBitmap Tick::GetTextBitmap() const
{
  return txtBitmap;
}

wxSize Tick::GetTextSize() const
{
  return txtBitmap.GetSize();
}


} // namespace chartwx

#endif // CHARTWX_TICK_H
