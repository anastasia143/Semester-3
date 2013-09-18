#-------------------------------------------------
#
# Project created by QtCreator 2013-09-17T20:34:49
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT  += testlib


SOURCES += main.cpp \
    robotTask.cpp

OTHER_FILES += \
    graph1.txt \
    graph2.txt \
    graph3.txt \
    graph4.txt \
    graph5.txt

HEADERS += \
    robotTask.h \
    test.h
