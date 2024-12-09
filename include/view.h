#if !defined(CIEUI_VIEW)
#define CIEUI_VIEW

#include <wx/wx.h>
#include "defs.h"

class CieView : public wxWindow
{
public:
    CieView(wxWindow *parent);

protected:
    wxPoint calculateContentPosition(CieAlign &align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize);

private:
    int calculateContentHorizontalPosition(int align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize);
    int calculateContentVerticalPosition(int align, CieMargin &margin, CiePadding &padding, wxSize &actualSize, wxSize &contentSize);
};

#endif // CIEUI_VIEW
