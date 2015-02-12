# 
# Copyright (c) 2015 Marat Abrarov (abrarov@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

cmake_minimum_required(VERSION 2.8)
project(cxx11_test)

include(compiler_options.cmake)
include(linker_options.cmake)

# Set additional preprocessor definitions for Windows targets
if(WIN32)
    add_definitions(
        -DWIN32
        -DWIN32_LEAN_AND_MEAN
        -D_UNICODE
        -DUNICODE
        -DWINVER=0x0500
        -D_WIN32_WINNT=0x0500)
endif()

add_subdirectory(move_support)
