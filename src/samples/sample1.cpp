/********************************************************************************
 *                                                                              *
 * chartwx - simple sample program                                              *
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

#include "sample1.h"
#include <chartwx/chartwindow.h>
#include <chartwx/chart.h>
#include <chartwx/style.h>
#include <chartwx/axis/numericaxis.h>
#include <chartwx/data/defaultdoubledataset.h>
#include <chartwx/renderer/xychartrenderer.h>
#include <wx/sizer.h>
#include <wx/dcclient.h>
#include <iostream>

Sample1::Sample1()
{
}

bool Sample1::OnInit()
{
  frame = new wxFrame(nullptr,wxID_ANY,"Sample 1");
//  chartwx::Style style = chartwx::Style::GetDefaultStyle();
//  wxClientDC dc(frame);
//  style.copyFromDC(dc);
//  chartwx::Style::SetDefaultStyle(style);
  std::vector<double> xvalues{1,2,3,4};
  std::vector<double> yvalues{1,4,9,16};
  std::shared_ptr<chartwx::DataSet> ds = std::make_shared<chartwx::DefaultDoubleDataSet>("Test",xvalues,yvalues);
  auto renderer = std::make_shared<chartwx::XYChartRenderer>();
  renderer->AddDataSet(ds);
  auto xaxis = std::make_shared<chartwx::LinearAxis>(chartwx::Side::Bottom,"x axis [arb units]");
  auto yaxis = std::make_shared<chartwx::LinearAxis>(chartwx::Side::Left,"Value [arb units]");
  auto chart = std::make_shared<chartwx::Chart>(xaxis,yaxis);
  chart->AddRenderer(renderer);
  auto w = new chartwx::ChartWindow(frame,wxID_ANY);
  w->AddChart(chart);
  wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
  frame->SetSizer(boxSizer);
  boxSizer->Add(w,1,wxALL|wxEXPAND);
  frame->Show();
  SetTopWindow(frame);
  return true;
}




wxIMPLEMENT_APP(Sample1);

