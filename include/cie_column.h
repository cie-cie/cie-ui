#if !defined(CIEUI_COLUMN)
#define CIEUI_COLUMN

#include <wx/wx.h>
#include <functional>

class CieColumn : public wxPanel
{
public:
    CieColumn(wxWindow *parent);

    static CieColumn *New(wxWindow *parent);

    CieColumn *children(std::function<std::vector<wxWindow *>(wxWindow *)> builder);

private:
    std::vector<wxWindow *> mChildren;
    wxBoxSizer *sizer;
};

#endif // CIEUI_COLUMN
