#include "wx/wx.h"
#include "ui.h"

class TestFrame : public CieFrame
{
public:
    TestFrame();
    void build(wxWindow *parent) override;
};

TestFrame::TestFrame() : CieFrame()
{
}

void TestFrame::build(wxWindow *parent)
{
    new wxButton(parent, wxID_ANY, "Testing");
}

CIE_START_MAIN_FRAME(TestFrame);