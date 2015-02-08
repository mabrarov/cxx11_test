cmake_minimum_required(VERSION 2.8)
project(cxx11_test)

# Set additional options for Windows targets
if(WIN32)
    add_definitions(
        -DWIN32_LEAN_AND_MEAN
        -D_UNICODE
        -DUNICODE
        -DWINVER=0x0500
        -D_WIN32_WINNT=0x0500)
endif()

add_subdirectory(move_support)
