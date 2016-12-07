#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T22:56:16
# Created by Nipuna Cooray
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraceUI
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_videoio


SOURCES += main.cpp\
        mainwindow.cpp \
    setupform.cpp \
    runform.cpp \
    savestyleform.cpp \
    loadstyleform.cpp \
    slaverunform.cpp \
    slavesetupform.cpp \
    keyboard.cpp \
    styledata.cpp \
    global.cpp \
    edgedetect.cpp \
    serialreadwrite.cpp \
    player.cpp \
    objecttracker.cpp \
    edgedetectnew.cpp


HEADERS  += mainwindow.h \
    setupform.h \
    runform.h \
    savestyleform.h \
    loadstyleform.h \
    slaverunform.h \
    slavesetupform.h \
    ui_keyboard.h \
    keyboard.h \
    styledata.h \
    global.h \
    edgedetect.h \
    serialreadwrite.h \
    player.h \
    objecttracker.h \
    edgedetectnew.h


FORMS    += mainwindow.ui \
    setupform.ui \
    runform.ui \
    savestyleform.ui \
    loadstyleform.ui \
    slaverunform.ui \
    slavesetupform.ui \
    keyboard.ui

CONFIG += c++11
