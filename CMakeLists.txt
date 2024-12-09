cmake_minimum_required(VERSION 3.11)

project(cieui VERSION 0.0.1)

add_library(cieui
    source/cie_frame.cxx
    source/cie_column.cxx
    source/cie_button.cxx
    source/layout.cxx
    source/default_theme.cxx
)
target_include_directories(cieui PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/cieui>
)

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

install(TARGETS cieui 
    EXPORT cieuiTargets
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include/cieui)

# Configure CMake exports
install(EXPORT cieuiTargets
    FILE cieuiTargets.cmake
    DESTINATION lib/cmake/cieui
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/cieuiConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

configure_file(cieuiConfig.cmake.in cieuiConfig.cmake @ONLY)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cieuiConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cieuiConfigVersion.cmake"
    DESTINATION lib/cmake/cieui
)