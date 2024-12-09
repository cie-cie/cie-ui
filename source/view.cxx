#include "view.h"

enum HorizontalAlign
{
    HALIGN_LEFT = 0,
    HALIGN_CENTER,
    HALIGN_RIGHT
};

enum VerticalAlign
{
    VALIGN_TOP = 0,
    VALIGN_MIDDLE,
    VALIGN_BOTTOM
};

CieView::CieView(wxWindow *parent) : wxWindow(parent, wxID_ANY)
{
}

wxPoint CieView::calculateContentPosition(CieAlign &align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize)
{
    int x;
    int y;

    switch (align)
    {
    case CieAlign::TOP_LEFT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_LEFT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_TOP, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::TOP_CENTER:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_CENTER, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_TOP, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::TOP_RIGHT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_RIGHT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_TOP, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::MIDDLE_LEFT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_LEFT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_MIDDLE, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::CENTER:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_CENTER, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_MIDDLE, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::MIDDLE_RIGHT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_RIGHT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_MIDDLE, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::BOTTOM_LEFT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_LEFT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_BOTTOM, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::BOTTOM_CENTER:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_CENTER, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_BOTTOM, margin, padding, actualSize, contentSize);
        break;
    case CieAlign::BOTTOM_RIGHT:
        x = calculateContentHorizontalPosition(HorizontalAlign::HALIGN_RIGHT, margin, padding, actualSize, contentSize);
        y = calculateContentVerticalPosition(VerticalAlign::VALIGN_BOTTOM, margin, padding, actualSize, contentSize);
        break;
    }

    return wxPoint(x, y);
}

int CieView::calculateContentHorizontalPosition(int align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize)
{
    HorizontalAlign horizAlign = static_cast<HorizontalAlign>(align);

    switch (horizAlign)
    {
    case HALIGN_LEFT:
        return padding.left + margin.left;
    case HALIGN_CENTER:
        return padding.left + margin.left + ((actualSize.GetWidth() - padding.left - padding.right - margin.left - margin.right) / 2) - (contentSize.GetWidth() / 2);
    case HALIGN_RIGHT:
        return actualSize.GetWidth() - padding.right - margin.right - contentSize.GetWidth();
    }

    return -1;
}

int CieView::calculateContentVerticalPosition(int align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize)
{
    VerticalAlign vertAlign = static_cast<VerticalAlign>(align);

    switch (vertAlign)
    {
    case VALIGN_TOP:
        return padding.top + margin.top;
    case VALIGN_MIDDLE:
        return padding.top + margin.top + ((actualSize.GetHeight() - padding.top - padding.bottom - margin.top - margin.bottom) / 2) - (contentSize.GetHeight() / 2);
    case VALIGN_BOTTOM:
        return actualSize.GetHeight() - padding.bottom - margin.bottom - contentSize.GetHeight();
    }

    return -1;
}