#if !defined(CIEUI_LAYOUT)
#define CIEUI_LAYOUT

#include <wx/wx.h>
#include <utility>

class CieLayout : public wxWindow
{
public:
    CieLayout(wxWindow *parent);
    virtual std::pair<wxPoint, wxSize> calculateChildPositionAndSize(wxWindow *, wxPoint suggestedPosition, wxSize suggestedSize) = 0;
};

#endif // CIEUI_LAYOUT
