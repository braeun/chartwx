/********************************************************************************
 *                                                                              *
 * chartwx - chart wxWindow                                                     *
 *                                                                              *
 * modified: 2024-11-06                                                         *
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

#ifndef CHARTWX_CHARTWINDOW_H
#define CHARTWX_CHARTWINDOW_H

#include <wx/window.h>
#include <memory>
#include <vector>

namespace chartwx {

class Chart;

class ChartWindow: public wxWindow
{
public:
  ChartWindow();
  ChartWindow(wxWindow *parent, wxWindowID id, const wxPoint &pos=wxDefaultPosition,
              const wxSize &size=wxDefaultSize, long style=0, const wxString &name=wxPanelNameStr);

  virtual size_t GetChartCount() const;

  virtual void AddChart(std::shared_ptr<Chart>& chart);

  virtual std::shared_ptr<Chart> GetChart(size_t index) const;

  virtual bool Layout() override;

  void Replot();

protected:
  void OnPaint(wxPaintEvent& event);

  std::vector<std::shared_ptr<Chart>> charts;
};

} // namespace chartwx

#endif // CHARTWX_CHARTWINDOW_H
