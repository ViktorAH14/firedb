#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T19:37:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FireDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbcreator.cpp \
    signalingform.cpp

HEADERS  += mainwindow.h \
    dbcreator.h \
    signalingform.h

FORMS    += mainwindow.ui \
    signalingform.ui

RESOURCES += \
    firepdep.qrc
