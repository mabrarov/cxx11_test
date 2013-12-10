#
# Copyright (c) 2010-2013 Marat Abrarov (abrarov@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

TEMPLATE  = app
QT       -= core gui
TARGET    = move_support
CONFIG   += console thread
CONFIG   -= app_bundle

# Common project configuration
include(../config.pri)

SOURCES  += ../../../src/move_support/main.cpp

INCLUDEPATH += $${BOOST_INCLUDE} \
               ../../../include

win32:DEFINES += WINVER=0x0500 \
                 _WIN32_WINNT=0x0500
