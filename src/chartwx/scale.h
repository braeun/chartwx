#ifndef CHARTWX_TRANSFORM_H
#define CHARTWX_TRANSFORM_H

#include "enums.h"
#include "axis/tick.h"
#include "data/range.h"


namespace chartwx {

class Scale
{
public:
  Scale(Direction dir);
  virtual ~Scale();

  Direction GetDirection() const;

  virtual int ToScreen(double v) const = 0;

  virtual void UpdatePixels(int p);

  virtual std::vector<TickValue> GetTicks() const;

protected:
  Direction dir;
  unsigned int pixels;
};


class NumericScale: public Scale
{
public:
  NumericScale(Direction dir);
  virtual ~NumericScale();

  virtual void UpdateRange(Range r);

  const Range& GetRange() const;

protected:
  Range range;

};


class LinearScale: public NumericScale
{
public:
  LinearScale(Direction dir);
  virtual ~LinearScale();

  virtual int ToScreen(double v) const override;

  virtual void UpdateRange(Range r) override;

  virtual void UpdatePixels(int p) override;

  virtual std::vector<TickValue> GetTicks() const override;

private:
  double GetMajorTickStep(const Range& r) const;

  double scale;
};



class LogarithmicScale: public NumericScale
{
public:
  LogarithmicScale(Direction dir);
  virtual ~LogarithmicScale();

  virtual int ToScreen(double v) const override;

  virtual void UpdateRange(Range r) override;

  virtual void UpdatePixels(int p) override;

  virtual std::vector<TickValue> GetTicks() const override;

private:
  double scale;
};

} // namespace chartwx

#endif // CHARTWX_TRANSFORM_H
