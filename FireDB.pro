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
    subtableview.cpp \
    singleform.cpp

HEADERS  += mainwindow.h \
    dbcreator.h \
    subtableview.h \
    singleform.h

FORMS    += mainwindow.ui \
    subtableview.ui \
    singleform.ui

RESOURCES += \
    firepdep.qrc
