#include "cie_button.h"
#include "default_theme.h"

const wxSize CieButton::DEFAULT_SIZE = wxSize(-1, 48);

CieButton::CieButton(wxWindow *parent) : wxButton(parent, wxID_ANY, "", wxDefaultPosition, CieButton::DEFAULT_SIZE)
{
    this->baseBackgroundColor = default_theme::ACCENT_COLOR;
    this->baseForegroundColor = default_theme::ON_ACCENT_COLOR;
    this->hoverBackgroundColor = default_theme::ACCENT_HOVER_COLOR;
    this->hoverForegroundColor = default_theme::ON_ACCENT_HOVER_COLOR;

    SetBackgroundColour(baseBackgroundColor);
    SetForegroundColour(baseForegroundColor);

    Bind(wxEVT_ENTER_WINDOW, &CieButton::mouseEnterListener, this);
    Bind(wxEVT_LEAVE_WINDOW, &CieButton::mouseLeaveListener, this);
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