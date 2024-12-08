#include "cie_button.h"
#include "default_theme.h"

CieButton::CieButton(wxWindow *parent) : wxControl(parent, wxID_ANY)
{
    this->baseBackgroundColor = default_theme::ACCENT_COLOR;
    this->baseForegroundColor = default_theme::ON_ACCENT_COLOR;
    this->hoverBackgroundColor = default_theme::ACCENT_HOVER_COLOR;
    this->hoverForegroundColor = default_theme::ON_ACCENT_HOVER_COLOR;

    SetBackgroundColour(baseBackgroundColor);
    SetForegroundColour(baseForegroundColor);

    // set default padding
    paddingLeft = paddingRight = 24;
    paddingTop = paddingBottom = 12;

    Bind(wxEVT_ENTER_WINDOW, &CieButton::mouseEnterListener, this);
    Bind(wxEVT_LEAVE_WINDOW, &CieButton::mouseLeaveListener, this);
    Bind(wxEVT_PAINT, &CieButton::onPaint, this);
}

CieButton *CieButton::New(wxWindow *parent)
{
    return new CieButton(parent);
}

CieButton *CieButton::text(wxString text)
{
    SetLabel(text);
    return this;
}

void CieButton::mouseEnterListener(wxMouseEvent &e)
{
    SetCursor(wxCURSOR_HAND);

    SetBackgroundColour(hoverBackgroundColor);
    SetForegroundColour(hoverForegroundColor);

    e.Skip();
}

void CieButton::mouseLeaveListener(wxMouseEvent &e)
{
    SetCursor(wxCURSOR_ARROW);

    SetBackgroundColour(baseBackgroundColor);
    SetForegroundColour(baseForegroundColor);

    e.Skip();
}

void CieButton::onPaint(wxPaintEvent &e)
{
    wxPaintDC dc(this);
    dc.Clear();

    wxSize size = GetSize();

    int textWidth;
    int textHeight;
    dc.GetTextExtent(GetLabel(), &textWidth, &textHeight);

    // get required width and height
    int requiredWidth;
    int requiredHeight;

    requiredWidth = textWidth + paddingLeft + paddingRight;
    requiredHeight = textHeight + paddingTop + paddingBottom;

    if (size.GetWidth() < requiredWidth || size.GetHeight() < requiredHeight)
    {
        SetSize(
            wxMax(requiredWidth, size.GetWidth()),
            wxMax(requiredHeight, size.GetHeight()) //
        );
    }

    size = GetSize();

    // draw background
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.SetBrush(wxBrush(GetBackgroundColour()));
    dc.DrawRectangle(0, 0, size.GetWidth(), size.GetHeight());

    // draw text
    dc.DrawText(
        GetLabel(),
        (size.GetWidth() - textWidth) / 2,
        (size.GetHeight() - textHeight) / 2 //
    );
}