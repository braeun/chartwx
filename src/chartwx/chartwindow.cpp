#include "chartwindow.h"
#include "chart.h"
#include <wx/dcclient.h>

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

void ChartWindow::AddChart(std::shared_ptr<Chart>& chart)
{
  charts.push_back(chart);
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
