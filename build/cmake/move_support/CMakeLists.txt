# 
# Copyright (c) 2015 Marat Abrarov (abrarov@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

cmake_minimum_required(VERSION 2.8)
project(move_support)

find_package(Boost REQUIRED)

set(HEADERS_DIR "${PROJECT_SOURCE_DIR}/../../../include")
set(SOURCES_DIR "${PROJECT_SOURCE_DIR}/../../../src")

set(SOURCES 
    "${SOURCES_DIR}/move_support/main.cpp"
)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${HEADERS_DIR})
add_executable(move_support ${SOURCES})
target_link_libraries(move_support ${Boost_LIBRARIES})
