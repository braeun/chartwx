/********************************************************************************
 *                                                                              *
 * chartwx - chart object base class                                            *
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

#ifndef CHARTWX_CHARTOBJECT_H
#define CHARTWX_CHARTOBJECT_H

#include "wx/dc.h"

namespace chartwx {

class Range;
class Scale;

class ChartObject
{
public:
  ChartObject();

  const wxRect GetArea() const;

  void SetArea(const wxRect& r);

  void SetArea(int x, int y, int w, int h);

  /**
   * @brief The first layout pass used to calculate desired size of the object.
   * @param dc
   * @param xrange
   * @param yrange
   */
  virtual void LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange);

  /**
   * @brief The second layout pass used to layout object as all sizes are defined now..
   * @param dc
   * @param xrange
   * @param yrange
   */
  virtual void LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange);

  virtual wxSize GetSizeHint() const;

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const = 0;

protected:
  wxRect area;

};

} // namespace chartwx

#endif // CHARTWX_CHARTOBJECT_H
