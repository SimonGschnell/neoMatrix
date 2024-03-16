cmake_minimum_required(VERSION 3.27)
project(neomatrix)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(neomatrix main.cpp
        MatrixCharacter.h
        MatrixCharacter.cpp
        helpers.cpp
        helpers.h)

target_link_libraries(neomatrix ${CURSES_LIBRARIES})
