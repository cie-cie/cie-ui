#if !defined(CIEUI_FRAME)
#define CIEUI_FRAME

#include <wx/wx.h>

class CieFrame : public wxFrame
{
public:
    CieFrame(wxWindow *parent);
    CieFrame *title(wxString title);
};

#endif // CIEUI_FRAME
