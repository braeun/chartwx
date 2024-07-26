#include "range.h"
#include <algorithm>
#include <limits>

namespace chartwx {

Range::Range():
  min(std::numeric_limits<double>::max()),
  max(-std::numeric_limits<double>::max())
{
}

Range::Range(double min, double max):
  min(min),
  max(max)
{
}

double Range::GetMin() const
{
  return min;
}

double Range::GetMax() const
{
  return max;
}

void Range::Add(double v)
{
  min = std::min(min,v);
  max = std::max(max,v);
}

void Range::Add(const Range& range)
{
  if (range)
  {
    min = std::min(min,range.min);
    max = std::max(max,range.min);
    min = std::min(min,range.max);
    max = std::max(max,range.max);
  }
}

} // namespace chartwx
