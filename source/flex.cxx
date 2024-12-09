#include "flex.h"

CieFlex::CieFlex(wxWindow *parent) : CieLayout(parent)
{
}

CieFlex *CieFlex::New(wxWindow *parent)
{
    return new CieFlex(parent);
}

CieFlex *CieFlex::children(std::function<std::vector<wxWindow *>(wxWindow *)> builder)
{
    std::vector<wxWindow *> lChildren = builder(this);

    for (wxWindow *child : lChildren)
    {
        mChildren.push_back(std::tuple<wxWindow *, wxPoint, wxSize>(child, wxDefaultPosition, wxDefaultSize));
    }

    return this;
}

std::pair<wxPoint, wxSize> CieFlex::calculateChildPositionAndSize(wxWindow *pChild, wxPoint suggestedPosition, wxSize suggestedSize)
{
    // find index
    int index = -1;
    for (int i = 0; i < mChildren.size(); i++)
    {
        std::tuple<wxWindow *, wxPoint, wxSize> child = mChildren[i];

        wxWindow *childWindow = std::get<0>(child);
        if (childWindow == pChild)
        {
            index = i;
            break;
        }
    }

    if (index > -1)
    {
        wxPoint position;
        wxSize size;

        if (index == 0)
        {
            position = wxPoint(0, 0);
            size = suggestedSize;
        }
        else
        {
            std::tuple<wxWindow *, wxPoint, wxSize> childBefore = mChildren[index - 1];
            wxPoint childPositionBefore = std::get<1>(childBefore);
            wxSize childSizeBefore = std::get<2>(childBefore);

            position = wxPoint(0, childPositionBefore.y + childSizeBefore.y);
            size = suggestedSize;
        }

        std::get<1>(mChildren[index]) = position;
        std::get<2>(mChildren[index]) = size;

        return std::pair<wxPoint, wxSize>(position, size);
    }
    else
    {
        return std::pair<wxPoint, wxSize>(wxPoint(-1, -1), wxSize(0, 0));
    }
}