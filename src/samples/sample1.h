#ifndef SAMPLE1_H
#define SAMPLE1_H

#include <wx/app.h>
#include <wx/frame.h>

class Sample1: public wxApp
{
public:
  Sample1();

  bool OnInit();

private:
  wxFrame* frame;

};

#endif // SAMPLE1_H
