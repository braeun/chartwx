#include "chartobject.h"

namespace chartwx {

ChartObject::ChartObject()
{
}

const wxRect ChartObject::GetArea() const
{
  return area;
}

void ChartObject::SetArea(const wxRect& r)
{
  area = r;
}

void ChartObject::SetArea(int x, int y, int w, int h)
{
  area = wxRect(x,y,w,h);
}


void ChartObject::LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange)
{
}

void ChartObject::LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange)
{
}

wxSize ChartObject::GetSizeHint() const
{
  return wxSize(-1,-1);
}

} // namespace chartwx
