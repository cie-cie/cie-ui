#if !defined(CIEUI_COLUMN)
#define CIEUI_COLUMN

#include "layout.h"
#include <functional>

class CieColumn : public CieLayout
{
public:
    CieColumn(wxWindow *parent);

    static CieColumn *New(wxWindow *parent);

    CieColumn *children(std::function<std::vector<wxWindow *>(wxWindow *)> builder);
    std::pair<wxPoint, wxSize> calculateChildPositionAndSize(wxWindow *child, wxPoint suggestedPosition, wxSize suggestedSize) override;

private:
    std::vector<std::tuple<wxWindow *, wxPoint, wxSize>> mChildren;
};

#endif // CIEUI_COLUMN
