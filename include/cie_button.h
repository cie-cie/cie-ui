#if !defined(CIEUI_BUTTON)
#define CIEUI_BUTTON

#include "view.h"

class CieButton : public CieView
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

    CieButton *borderRadius(double radius);

    bool SetBackgroundColour(const wxColour &colour) override;

private:
    wxWindow *parent;

    bool hovered;

    wxColor baseBackgroundColor;
    wxColor baseForegroundColor;
    wxColor hoverBackgroundColor;
    wxColor hoverForegroundColor;

    CiePadding mPadding;
    CieMargin mMargin;

    double mBorderRadius;

    CieAlign mTextAlign;

    void mouseEnterListener(wxMouseEvent &e);
    void mouseLeaveListener(wxMouseEvent &e);
    void onPaint(wxPaintEvent &e);
};

#endif // CIEUI_BUTTON
