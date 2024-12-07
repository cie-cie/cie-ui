#if !defined(CIEUI_WINDOW)
#define CIEUI_WINDOW

#include <wx/wx.h>
#include "cie_app.h"

class CieFrame : public wxFrame
{
public:
    CieFrame();
    virtual void build(wxWindow *parent) = 0;
    CieApp *getApp();

    void executeBuild();

protected:
    wxString title;
};

#endif // CIEUI_WINDOW
