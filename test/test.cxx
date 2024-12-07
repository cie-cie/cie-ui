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
    SetTitle("Test Frame");

    CieColumn::New(parent)->children( //
        [](wxWindow *parent)
        {
            std::vector<wxWindow *> children = {
                CieButton::New(parent)->text("Button 1"),
            };
            return children;
            //
        });
}

CIE_START_MAIN_FRAME(TestFrame);