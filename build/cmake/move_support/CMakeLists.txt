cmake_minimum_required(VERSION 2.8)
project(move_support)

find_package(Boost REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++0x -Wstrict-aliasing ${CMAKE_CXX_FLAGS}")
endif()

set(HEADERS_DIR "${PROJECT_SOURCE_DIR}/../../../include")
set(SOURCES_DIR "${PROJECT_SOURCE_DIR}/../../../src")

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${HEADERS_DIR})

set(SOURCES 
    "${SOURCES_DIR}/move_support/main.cpp"
)

add_executable(move_support ${SOURCES})
