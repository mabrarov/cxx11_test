# 
# Copyright (c) 2015 Marat Abrarov (abrarov@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

cmake_minimum_required(VERSION 3.0)
project(move_support)

set(project_base_dir "${PROJECT_SOURCE_DIR}")
set(cxx_headers_dir  "${project_base_dir}/include")
set(cxx_sources_dir  "${project_base_dir}/src")

set(cxx_headers )
set(cxx_sources )

ma_config_public_compile_options(cxx_public_compile_options)
ma_config_public_compile_definitions(cxx_public_compile_definitions)
set(cxx_public_libraries )

ma_config_private_compile_options(cxx_private_compile_options)
ma_config_private_compile_definitions(cxx_private_compile_definitions)
set(cxx_private_libraries )

list(APPEND cxx_sources
    "${cxx_sources_dir}/main.cpp")

find_package(Boost REQUIRED)
list(APPEND cxx_private_libraries
    ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME}
    ${cxx_headers}
    ${cxx_sources})
target_compile_options(${PROJECT_NAME}
    PUBLIC
    ${cxx_public_compile_options}
    PRIVATE
    ${cxx_private_compile_options})
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
    ${cxx_public_compile_definitions}
    PRIVATE
    ${cxx_private_compile_definitions})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${cxx_headers_dir})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${cxx_public_libraries}
    PRIVATE
    ${cxx_private_libraries})