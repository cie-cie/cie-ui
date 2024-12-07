#include "wx/wx.h"
#include "ui.h"

class MyApp : public wxApp
{
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    CieFrame *mainFrame = new CieFrame(nullptr);
    mainFrame->Show();
    return true;
}