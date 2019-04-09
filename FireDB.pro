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
    singleform.cpp \
    trainingform.cpp \
    unuccountingfireform.cpp

HEADERS  += mainwindow.h \
    dbcreator.h \
    subtableview.h \
    singleform.h \
    trainingform.h \
    unuccountingfireform.h

FORMS    += mainwindow.ui \
    subtableview.ui \
    singleform.ui \
    trainingform.ui \
    unuccountingfireform.ui

RESOURCES += \
    firepdep.qrc
