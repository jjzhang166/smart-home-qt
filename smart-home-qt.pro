#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T17:44:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smart-home-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    envwindow.cpp \
    setwindow.cpp \
    ctlwindow.cpp \
    syswindow.cpp \
    globalval.cpp

HEADERS  += mainwindow.h \
    envwindow.h \
    setwindow.h \
    ctlwindow.h \
    syswindow.h \
    globalval.h

FORMS    += mainwindow.ui \
    envwindow.ui \
    setwindow.ui \
    ctlwindow.ui \
    syswindow.ui
