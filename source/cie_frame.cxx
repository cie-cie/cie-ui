#include "cie_frame.h"

CieFrame::CieFrame() : title(""), wxFrame(nullptr, wxID_ANY, "")
{
}

CieApp *CieFrame::getApp()
{
    return reinterpret_cast<CieApp *>(wxTheApp);
}

void CieFrame::executeBuild()
{
    return build(this);
}