#ifndef CHARTWX_DEFAULTDOUBLEDATASET_H
#define CHARTWX_DEFAULTDOUBLEDATASET_H

#include "dataset.h"
#include <vector>

namespace chartwx {

class DefaultDoubleDataSet: public DataSet
{
public:
  DefaultDoubleDataSet();
  DefaultDoubleDataSet(const std::string& name);
  DefaultDoubleDataSet(const std::string& name,const std::vector<double>& xvalues, const std::vector<double>& yvalues);
  virtual ~DefaultDoubleDataSet();

  void Clear();

  void Set(const std::vector<double>& xvalues, const std::vector<double>& yvalues);

  void Add(double xvalue, double yvalue);

  virtual size_t GetSize() const override;

  virtual double GetX(size_t index) const override;

  virtual double GetY(size_t index) const override;

  virtual Range GetXRange() const override;

  virtual Range GetYRange() const override;

protected:
  std::vector<double> x;
  std::vector<double> y;
  Range xrange;
  Range yrange;
};

} // namespace chartwx

#endif // CHARTWX_DEFAULTDOUBLEDATASET_H
