#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T00:59:54
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FutebolCampo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GLPanel.cpp \
    GeometricObjects.cpp

HEADERS  += mainwindow.h \
    GLPanel.h \
    GeometricObjects.h

FORMS    += mainwindow.ui
