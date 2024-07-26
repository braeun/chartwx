#include "dataset.h"

namespace chartwx {

DataSet::DataSet()
{
}

DataSet::DataSet(const std::string& name):
  name(name)
{
}

DataSet::~DataSet()
{
}

const std::string& DataSet::GetName() const
{
  return name;
}

void DataSet::SetName(const std::string& n)
{
  name = n;
}

bool DataSet::IsEmpty() const
{
  return GetSize() == 0;
}

Range DataSet::GetXRange() const
{
  Range r;
  for (size_t i=0;i<GetSize();i++)
  {
    r.Add(GetX(i));
  }
  return r;
}

Range DataSet::GetYRange() const
{
  Range r;
  for (size_t i=0;i<GetSize();i++)
  {
    r.Add(GetY(i));
  }
  return r;
}


} // namespace chartwx
