#include "chartrenderer.h"

namespace chartwx {

ChartRenderer::ChartRenderer()
{
}

ChartRenderer::~ChartRenderer()
{
}

void ChartRenderer::Clear()
{
  datasets.clear();
  xrange = Range();
  yrange = Range();
}

void ChartRenderer::AddDataSet(std::shared_ptr<DataSet>& ds)
{
  datasets.push_back(ds);
  xrange.Add(ds->GetXRange());
  yrange.Add(ds->GetYRange());
}

Range ChartRenderer::GetXRange() const
{
  return xrange;
}

Range ChartRenderer::GetYRange() const
{
  return yrange;
}


} // namespace chartwx
