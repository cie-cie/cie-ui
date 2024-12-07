add_executable(cieui_test
    test.cxx
)   

target_link_libraries(cieui_test PRIVATE
    cieui
)