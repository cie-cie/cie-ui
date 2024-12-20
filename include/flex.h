#if !defined(CIEUI_COLUMN)
#define CIEUI_COLUMN

#include "layout.h"
#include <functional>

class CieFlex : public CieLayout
{
public:
    CieFlex(wxWindow *parent);

    static CieFlex *New(wxWindow *parent);

    CieFlex *children(std::function<std::vector<wxWindow *>(wxWindow *)> builder);
    std::pair<wxPoint, wxSize> calculateChildPositionAndSize(wxWindow *child, wxPoint suggestedPosition, wxSize suggestedSize) override;

private:
    std::vector<std::tuple<wxWindow *, wxPoint, wxSize>> mChildren;
};

#endif // CIEUI_COLUMN
