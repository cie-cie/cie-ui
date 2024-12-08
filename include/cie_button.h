#if !defined(CIEUI_BUTTON)
#define CIEUI_BUTTON

#include <wx/wx.h>
#include "cie_align.h"

class CieButton : public wxControl
{
public:
    CieButton(wxWindow *parent);

    static CieButton *New(wxWindow *parent);

    CieButton *text(wxString text);

    CieButton *padding(int all);
    CieButton *padding(int topBottom, int leftRight);
    CieButton *padding(int top, int right, int bottom, int left);

    CieButton *margin(int all);
    CieButton *margin(int topBottom, int leftRight);
    CieButton *margin(int top, int right, int bottom, int left);

    CieButton *textAlign(CieAlign align);

    CieButton *size(int width, int height);

private:
    wxColor baseBackgroundColor;
    wxColor baseForegroundColor;
    wxColor hoverBackgroundColor;
    wxColor hoverForegroundColor;

    int paddingTop;
    int paddingRight;
    int paddingBottom;
    int paddingLeft;

    int mMarginTop;
    int mMarginRight;
    int mMarginBottom;
    int mMarginLeft;

    CieAlign mTextAlign;

    void mouseEnterListener(wxMouseEvent &e);
    void mouseLeaveListener(wxMouseEvent &e);
    void onPaint(wxPaintEvent &e);
};

#endif // CIEUI_BUTTON
