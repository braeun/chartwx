#include "valueformatter.h"
#include <wx/dcmemory.h>
#include <cstdio>

namespace chartwx {

ValueFormatter::ValueFormatter() {}

ValueFormatter::~ValueFormatter()
{
}

wxBitmap ValueFormatter::Draw(const wxDC& dc, double v) const
{
  std::string s = Format(v);
  if (s.empty()) return wxNullBitmap;
  wxSize size = dc.GetTextExtent(s);
  wxBitmap bitmap(size);
  wxMemoryDC bdc(bitmap);
  bdc.CopyAttributes(dc);
  bdc.Clear();
  bdc.DrawText(s,0,0);
  return bitmap;
}

DefaultValueFormatter::DefaultValueFormatter(const std::string& format):
  pattern(format)
{
}

DefaultValueFormatter::~DefaultValueFormatter()
{
}

std::string DefaultValueFormatter::Format(double v) const
{
  static char buffer[128];
  snprintf(buffer,sizeof(buffer),pattern.c_str(),v);
  return buffer;
}


} // namespace chartwx
