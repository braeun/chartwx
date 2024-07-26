#include "sample1.h"
#include <chartwx/chartwindow.h>
#include <chartwx/chart.h>
#include <chartwx/axis/numericsaxis.h>
#include <chartwx/data/defaultdoubledataset.h>
#include <chartwx/renderer/xychartrenderer.h>
#include <wx/sizer.h>

Sample1::Sample1()
{
}

bool Sample1::OnInit()
{
  frame = new wxFrame(nullptr,wxID_ANY,"Sample 1");
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

