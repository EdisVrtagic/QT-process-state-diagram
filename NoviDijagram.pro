#-------------------------------------------------
#
# Project created by QtCreator 2022-05-27T11:15:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoviDijagram
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    stanje.cpp \
    tranzicija.cpp

HEADERS  += dialog.h \
    stanje.h \
    tranzicija.h

FORMS    += dialog.ui
