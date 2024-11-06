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

#include "chartwindow.h"
#include "chart.h"
#include <wx/dcclient.h>
#include <stdexcept>

namespace chartwx {

ChartWindow::ChartWindow()
{
}

ChartWindow::ChartWindow(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name):
    wxWindow(parent,id,pos,size,style,name)
{
  SetAutoLayout(true);
  Bind(wxEVT_PAINT,&ChartWindow::OnPaint,this);
}

size_t ChartWindow::GetChartCount() const
{
  return charts.size();
}

void ChartWindow::AddChart(std::shared_ptr<Chart>& chart)
{
  charts.push_back(chart);
}

std::shared_ptr<Chart> ChartWindow::GetChart(size_t index) const
{
  if (index >= charts.size()) throw std::runtime_error("ChartWindow::GetChart - INdex out of bounds");
  return charts[index];
}

bool ChartWindow::Layout()
{
  wxClientDC dc(this);
  for (const auto& chart : charts)
  {
    chart->Layout(dc,GetSize());
  }
  return true;
}

void ChartWindow::Replot()
{
  Layout();
  Refresh();
}



void ChartWindow::OnPaint(wxPaintEvent &event)
{
  wxPaintDC dc(this);
  for (const auto& chart : charts)
  {
    chart->Paint(dc,nullptr,nullptr);
  }
}

} // namespace chartwx
