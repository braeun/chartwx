#ifndef CHARTWX_XYCHARTRENDERER_H
#define CHARTWX_XYCHARTRENDERER_H

#include "chartrenderer.h"

namespace chartwx {

class XYChartRenderer: public ChartRenderer
{
public:
  XYChartRenderer();

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const override;

};

} // namespace chartwx

#endif // CHARTWX_XYCHARTRENDERER_H
