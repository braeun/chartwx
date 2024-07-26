#ifndef CHARTWX_CHARTOBJECT_H
#define CHARTWX_CHARTOBJECT_H

#include "wx/dc.h"

namespace chartwx {

class Range;
class Scale;

class ChartObject
{
public:
  ChartObject();

  const wxRect GetArea() const;

  void SetArea(const wxRect& r);

  void SetArea(int x, int y, int w, int h);

  /**
   * @brief The first layout pass used to calculate desired size of the object.
   * @param dc
   * @param xrange
   * @param yrange
   */
  virtual void LayoutPass1(wxDC& dc, const Range& xrange, const Range& yrange);

  /**
   * @brief The second layout pass used to layout object as all sizes are defined now..
   * @param dc
   * @param xrange
   * @param yrange
   */
  virtual void LayoutPass2(wxDC& dc, const Range& xrange, const Range& yrange);

  virtual wxSize GetSizeHint() const;

  virtual void Paint(wxDC& dc, const Scale* xtrans, const Scale* ytrans) const = 0;

protected:
  wxRect area;

};

} // namespace chartwx

#endif // CHARTWX_CHARTOBJECT_H
