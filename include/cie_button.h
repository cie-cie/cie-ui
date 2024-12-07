#if !defined(CIEUI_BUTTON)
#define CIEUI_BUTTON

#include <wx/wx.h>

class CieButton : public wxButton
{
public:
    CieButton(wxWindow *parent);

    static CieButton *New(wxWindow *parent);

    CieButton *text(wxString text);

private:
    static const wxSize DEFAULT_SIZE;

    wxColor baseBackgroundColor;
    wxColor baseForegroundColor;
    wxColor hoverBackgroundColor;
    wxColor hoverForegroundColor;

    void mouseEnterListener(wxMouseEvent &e);
    void mouseLeaveListener(wxMouseEvent &e);
};

#endif // CIEUI_BUTTON
