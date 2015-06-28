#-------------------------------------------------
#
# Project created by QtCreator 2015-05-31T18:31:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CandyCrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    signaldialog.cpp \
    signalwindow.cpp

HEADERS  += mainwindow.h \
    signaldialog.h \
    signalwindow.h

FORMS    += mainwindow.ui \
    signaldialog.ui \
    signalwindow.ui

RESOURCES += \
    pics.qrc

SUBDIRS += \
    SignalTest.pro \
    SignalTest.pro
