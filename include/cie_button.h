#if !defined(CIEUI_BUTTON)
#define CIEUI_BUTTON

#include <wx/wx.h>

class CieButton : public wxControl
{
public:
    CieButton(wxWindow *parent);

    static CieButton *New(wxWindow *parent);

    CieButton *text(wxString text);

private:
    wxColor baseBackgroundColor;
    wxColor baseForegroundColor;
    wxColor hoverBackgroundColor;
    wxColor hoverForegroundColor;

    int paddingTop;
    int paddingRight;
    int paddingBottom;
    int paddingLeft;

    void mouseEnterListener(wxMouseEvent &e);
    void mouseLeaveListener(wxMouseEvent &e);
    void onPaint(wxPaintEvent &e);
};

#endif // CIEUI_BUTTON
