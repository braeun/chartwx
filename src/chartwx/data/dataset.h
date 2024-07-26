#ifndef CHARTWX_DATASET_H
#define CHARTWX_DATASET_H

#include "range.h"
#include <string>

namespace chartwx {

class DataSet
{
public:
  DataSet();
  DataSet(const std::string& name);
  virtual ~DataSet();

  const std::string& GetName() const;

  void SetName(const std::string& n);

  virtual bool IsEmpty() const;

  virtual size_t GetSize() const = 0;

  virtual double GetX(size_t index) const = 0;

  virtual double GetY(size_t index) const = 0;

  virtual Range GetXRange() const;

  virtual Range GetYRange() const;

protected:
  std::string name;
};

} // namespace chartwx

#endif // CHARTWX_DATASET_H
