#-------------------------------------------------
#
# Project created by QtCreator 2013-09-09T16:47:05
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = localNetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
    computer.cpp \
    computers/windows.cpp \
    computers/mac.cpp \
    computers/linux.cpp \
    network.cpp

HEADERS  += mainWindow.h \
    computer.h \
    computers/windows.h \
    computers/mac.h \
    computers/linux.h \
    network.h \
    logicTest.h \
    computerClassTest.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    networkMatrix.txt
