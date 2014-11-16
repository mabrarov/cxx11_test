cmake_minimum_required(VERSION 2.8)
project(cxx11_test)

# Help FindBoost to find Boost C++ Libraries
set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../../boost_1_57_0")
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
  set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib/amd64")
elseif("${CMAKE_SIZEOF_VOID_P}" EQUAL "4")
  set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib/x86")
endif()
set(Boost_NO_SYSTEM_PATHS ON)

if(WIN32)
  add_definitions(
    -DWIN32_LEAN_AND_MEAN
    -D_UNICODE
    -DUNICODE
    -DWINVER=0x0500
    -D_WIN32_WINNT=0x0500)
endif()

add_subdirectory(move_support)
