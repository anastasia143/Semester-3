#-------------------------------------------------
#
# Project created by QtCreator 2013-09-09T16:47:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = localNetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
    computer.cpp

HEADERS  += mainWindow.h \
    computer.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    networkMatrix.txt
