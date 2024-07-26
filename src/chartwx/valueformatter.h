#ifndef CHARTWX_VALUEFORMATTER_H
#define CHARTWX_VALUEFORMATTER_H

#include <wx/bitmap.h>
#include <wx/dc.h>
#include <string>

namespace chartwx {

class ValueFormatter
{
public:
  ValueFormatter();
  virtual ~ValueFormatter();

  virtual std::string Format(double v) const = 0;

  virtual wxBitmap Draw(const wxDC& dc, double v) const;
};


class DefaultValueFormatter: public ValueFormatter
{
public:
  DefaultValueFormatter(const std::string& format="%.4G");
  virtual ~DefaultValueFormatter();

  virtual std::string Format(double v) const override;

protected:
  std::string pattern;

};



} // namespace chartwx

#endif // CHARTWX_VALUEFORMATTER_H
