TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    optionvalue.cpp \
    filesystem.cpp \
    file.cpp \
    iomethod.cpp \
    optioninstance.cpp \
    encoding.cpp \
    blockbuffer.cpp

HEADERS += \
    optionvalue.h \
    filesystem.h \
    file.h \
    iomethod.h \
    optioninstance.h \
    encoding.h \
    blockbuffer.h
