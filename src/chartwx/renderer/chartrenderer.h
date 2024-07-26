#ifndef CHARTWX_PLOTRENDERER_H
#define CHARTWX_PLOTRENDERER_H

#include "../chartobject.h"
#include "../data/dataset.h"
#include <wx/dc.h>
#include <memory>
#include <vector>

namespace chartwx {

class ChartRenderer: public ChartObject
{
public:
  ChartRenderer();
  virtual ~ChartRenderer();

  virtual void Clear();

  virtual void AddDataSet(std::shared_ptr<DataSet>& ds);

  virtual Range GetXRange() const;

  virtual Range GetYRange() const;

protected:
  std::vector<std::shared_ptr<DataSet>> datasets;
  Range xrange;
  Range yrange;
};

} // namespace chartwx

#endif // CHARTWX_PLOTRENDERER_H
