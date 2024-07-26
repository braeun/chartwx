#include "axis.h"
#include "../scale.h"

namespace chartwx {

Axis::Axis(Side side, const std::string& label):
  side(side),
  label(label)
{
  valueFormatter = std::make_unique<DefaultValueFormatter>();
}

Axis::~Axis()
{
}

Side Axis::GetSide() const
{
  return side;
}

Scale* Axis::GetScale() const
{
  return scale.get();
}

ValueFormatter* Axis::GetValueFormatter() const
{
  return valueFormatter.get();
}

void Axis::SetValueFormatter(std::unique_ptr<ValueFormatter>&& fmt)
{
  valueFormatter = std::move(fmt);
}

} // namespace chartwx
