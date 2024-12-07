#include "cie_frame.h"

CieFrame::CieFrame(wxWindow *parent) : wxFrame(parent, wxID_ANY, "")
{
}

CieFrame *CieFrame::title(wxString title)
{
    SetTitle(title);
}