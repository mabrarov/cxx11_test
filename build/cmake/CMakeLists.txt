# 
# Copyright (c) 2015 Marat Abrarov (abrarov@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

cmake_minimum_required(VERSION 2.8)
project(cxx11_test)

# Set additional options for Windows targets
if(WIN32)
    add_definitions(
        -DWIN32
        -DWIN32_LEAN_AND_MEAN
        -D_UNICODE
        -DUNICODE
        -DWINVER=0x0500
        -D_WIN32_WINNT=0x0500)
endif()

# Turn on support of C++11 if it's available
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    set(CMAKE_CXX_FLAGS "/Qstd=c++0x ${CMAKE_CXX_FLAGS}")    
endif()

# Turn on Unicode support for MinGW for main function
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-municode ${CMAKE_EXE_LINKER_FLAGS}")
endif()

add_subdirectory(move_support)
