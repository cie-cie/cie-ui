cmake_minimum_required(VERSION 3.11)

project(cieui)

add_library(cieui
    source/cie_frame.cxx
    source/cie_column.cxx
)
target_include_directories(cieui PUBLIC ${CMAKE_SOURCE_DIR}/include)

find_package(wxWidgets REQUIRED)
target_include_directories(cieui PUBLIC 
    ${wxWidgets_INCLUDE_DIRS}
)
target_link_libraries(cieui PUBLIC
    ${wxWidgets_LIBRARIES}
)
target_compile_definitions(cieui PUBLIC
    ${wxWidgets_DEFINITIONS}
)

option(ENABLE_TEST "Build and run tests" OFF)
if(ENABLE_TEST) 
    message(STATUS "Build test: ON")
    add_subdirectory(test)
else()
    message(STATUS "Build test: OFF")
endif()