#ifndef CHARTWX_CHART_H
#define CHARTWX_CHART_H

#include "enums.h"
#include "chartobject.h"
#include "scale.h"
#include <memory>
#include <vector>

namespace chartwx {

class Axis;
class ChartRenderer;
class Scale;

class Chart: public ChartObject
{
public:
  Chart();
  Chart(std::shared_ptr<Axis> axis1, std::shared_ptr<Axis> axis2);
  virtual ~Chart();

  bool IsForceZeroInRange() const;

  void SetForceZeroInRange(bool flag);

  size_t GetAxisCount(Side side) const;

  size_t GetAxisCount(Direction dir) const;

  std::shared_ptr<Axis> GetAxis(Side side, size_t index=0) const;

  std::shared_ptr<Axis> GetAxis(Direction dir, size_t index=0) const;

  size_t GetRendererCount() const;

  std::shared_ptr<ChartRenderer> GetRenderer(size_t index=0) const;

  virtual void AddAxis(const std::shared_ptr<Axis>& axis);

  virtual void AddRenderer(const std::shared_ptr<ChartRenderer>& renderer);

  virtual void Layout(wxDC& dc, const wxSize& size);

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const override;

protected:
  Scale* xscale;
  Scale* yscale;
  std::vector<std::shared_ptr<Axis>> axes;
  std::vector<std::shared_ptr<ChartRenderer>> renderers;
  bool forceZeroInRange;

};

} // namespace chartwx

#endif // CHARTWX_CHART_H
