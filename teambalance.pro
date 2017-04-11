#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T19:52:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teambalance
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    balancer.cpp \
    player.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    balancer.h \
    player.h \
    matrix.h

FORMS    += mainwindow.ui
CONFIG+= c++11
CONFIG+= -static

RESOURCES += \
    resource.qrc
