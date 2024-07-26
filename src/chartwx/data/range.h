#ifndef CHARTWX_RANGE_H
#define CHARTWX_RANGE_H

namespace chartwx {

class Range
{
public:
  Range();
  Range(double min, double max);

  double GetMin() const;

  double GetMax() const;

  void Add(double v);

  void Add(const Range& range);

  explicit operator bool() const { return max > min; }

private:
  double min;
  double max;
};

} // namespace chartwx

#endif // CHARTWX_RANGE_H
