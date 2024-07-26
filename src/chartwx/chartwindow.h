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

  virtual void AddChart(std::shared_ptr<Chart>& chart);

  virtual bool Layout() override;

  void Replot();

protected:
  void OnPaint(wxPaintEvent& event);

  std::vector<std::shared_ptr<Chart>> charts;
};

} // namespace chartwx

#endif // CHARTWX_CHARTWINDOW_H
