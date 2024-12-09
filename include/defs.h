#if !defined(CIEUI_ALIGN)
#define CIEUI_ALIGN

enum CieAlign
{
    TOP_LEFT = 0,
    TOP_CENTER,
    TOP_RIGHT,
    MIDDLE_LEFT,
    CENTER,
    MIDDLE_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT
};

typedef struct CieMargin
{
    int top;
    int right;
    int bottom;
    int left;
} CieMargin;

typedef CieMargin CiePadding;

#endif // CIEUI_ALIGN
