#include "xychartrenderer.h"
#include "../scale.h"

namespace chartwx {

XYChartRenderer::XYChartRenderer()
{

}

void XYChartRenderer::Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const
{
  if (!xtrans || ! ytrans) return;
//  dc.SetPen(*wxBLACK_PEN);
  for (const auto& ds : datasets)
  {
    if (ds->IsEmpty()) continue;
    std::vector<wxPoint> points(ds->GetSize());
    for (size_t index=0;index<ds->GetSize();++index)
    {
      wxPoint p;
      p.x = xtrans->ToScreen(ds->GetX(index));
      p.y = ytrans->ToScreen(ds->GetY(index));
      points.push_back(p);
    }
    dc.DrawLines(points.size(),points.data());
  }
}

} // namespace chartwx


