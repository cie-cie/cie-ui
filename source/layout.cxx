#include "layout.h"

CieLayout::CieLayout(wxWindow *parent) : wxWindow(parent, wxID_ANY)
{
}

std::pair<wxPoint, wxSize> CieLayout::calculateChildPositionAndSize(wxWindow *, wxPoint suggestedPosition, wxSize suggestedSize)
{
    return std::pair<wxPoint, wxSize>(suggestedPosition, suggestedSize);
}