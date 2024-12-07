#include "cie_column.h"

CieColumn::CieColumn(wxWindow *parent) : wxPanel(parent, wxID_ANY)
{
    sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);
}

CieColumn *CieColumn::New(wxWindow *parent)
{
    return new CieColumn(parent);
}

CieColumn *CieColumn::children(std::function<std::vector<wxWindow *>(wxWindow *)> builder)
{
    std::vector<wxWindow *> lChildren = builder(this);

    for (wxWindow *child : lChildren)
    {
        mChildren.push_back(child);
        sizer->Add(child, 0, wxEXPAND);
    }

    return this;
}