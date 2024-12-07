#if !defined(CIEUI_MACRO)
#define CIEUI_MACRO

#define CIE_START_MAIN_FRAME(MainFrame)         \
    class ImplCieApp : public CieApp            \
    {                                           \
    public:                                     \
        bool OnInit() override;                 \
    };                                          \
    bool ImplCieApp::OnInit()                   \
    {                                           \
        MainFrame *mainFrame = new MainFrame(); \
        mainFrame->executeBuild();              \
        mainFrame->Show();                      \
        return true;                            \
    }                                           \
    wxIMPLEMENT_APP(ImplCieApp);

#endif // CIEUI_MACRO
