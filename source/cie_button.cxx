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

    // set default margin
    mMarginLeft = mMarginRight = mMarginTop = mMarginBottom = 0;

    // set default text align
    mTextAlign = CieAlign::CENTER;

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

    requiredWidth = textWidth + paddingLeft + paddingRight + mMarginLeft + mMarginRight;
    requiredHeight = textHeight + paddingTop + paddingBottom + mMarginTop + mMarginBottom;

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
    dc.DrawRectangle(mMarginLeft, mMarginTop, size.GetWidth() - mMarginRight, size.GetHeight() - mMarginBottom);

    // draw text
    int textXPos;
    int textYPos;

    switch (mTextAlign)
    {
    case CieAlign::TOP_LEFT:
        textXPos = paddingLeft;
        textYPos = paddingTop;
        break;
    case CieAlign::TOP_CENTER:
        textXPos = paddingLeft + ((size.GetWidth() - paddingLeft - paddingRight) / 2) - (textWidth / 2);
        textYPos = paddingTop;
        break;
    case CieAlign::TOP_RIGHT:
        textXPos = size.GetWidth() - paddingRight - textWidth;
        textYPos = paddingTop;
        break;
    case CieAlign::MIDDLE_LEFT:
        textXPos = paddingLeft;
        textYPos = paddingTop + ((size.GetHeight() - paddingTop - paddingBottom) / 2) - (textHeight / 2);
        break;
    case CieAlign::CENTER:
        textXPos = paddingLeft + ((size.GetWidth() - paddingLeft - paddingRight) / 2) - (textWidth / 2);
        textYPos = paddingTop + ((size.GetHeight() - paddingTop - paddingBottom) / 2) - (textHeight / 2);
        break;
    case CieAlign::MIDDLE_RIGHT:
        textXPos = size.GetWidth() - paddingRight - textWidth;
        textYPos = paddingTop + ((size.GetHeight() - paddingTop - paddingBottom) / 2) - (textHeight / 2);
        break;
    case CieAlign::BOTTOM_LEFT:
        textXPos = paddingLeft;
        textYPos = size.GetHeight() - paddingBottom - textHeight;
        break;
    case CieAlign::BOTTOM_CENTER:
        textXPos = paddingLeft + ((size.GetWidth() - paddingLeft - paddingRight) / 2) - (textWidth / 2);
        textYPos = size.GetHeight() - paddingBottom - textHeight;
        break;
    case CieAlign::BOTTOM_RIGHT:
        textXPos = size.GetWidth() - paddingRight - textWidth;
        textYPos = size.GetHeight() - paddingBottom - textHeight;
        break;
    }

    dc.DrawText(
        GetLabel(),
        textXPos,
        textYPos //
    );
}

CieButton *CieButton::padding(int all)
{
    return padding(all, all, all, all);
}

CieButton *CieButton::padding(int topBottom, int leftRight)
{
    return padding(topBottom, leftRight, topBottom, leftRight);
}

CieButton *CieButton::padding(int top, int right, int bottom, int left)
{
    paddingTop = top;
    paddingBottom = bottom;
    paddingLeft = left;
    paddingRight = right;

    Refresh();

    return this;
}

CieButton *CieButton::textAlign(CieAlign align)
{
    mTextAlign = align;
    Refresh();

    return this;
}

CieButton *CieButton::size(int width, int height)
{
    SetSize(wxSize(width, height));

    return this;
}

CieButton *CieButton::margin(int all)
{
    return margin(all, all, all, all);
}

CieButton *CieButton::margin(int topBottom, int leftRight)
{
    return margin(topBottom, leftRight, topBottom, leftRight);
}

CieButton *CieButton::margin(int top, int right, int bottom, int left)
{
    mMarginTop = top;
    mMarginRight = right;
    mMarginBottom = bottom;
    mMarginLeft = left;

    Refresh();

    return this;
}