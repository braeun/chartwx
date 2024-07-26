#ifndef CHARTWX_AXIS_H
#define CHARTWX_AXIS_H

#include "../chartobject.h"
#include "../enums.h"
#include "../valueformatter.h"
#include <memory>

namespace chartwx {

class Range;

class Axis: public ChartObject
{
public:
  Axis(Side side, const std::string& label="");
  virtual ~Axis();

  Side GetSide() const;

  Scale* GetScale() const;

  ValueFormatter* GetValueFormatter() const;

  void SetValueFormatter(std::unique_ptr<ValueFormatter>&& fmt);

protected:
  Side side;
  std::string label;
  std::unique_ptr<ValueFormatter> valueFormatter;
  std::unique_ptr<Scale> scale;

};

} // namespace chartwx

#endif // CHARTWX_AXIS_H
