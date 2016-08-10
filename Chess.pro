#-------------------------------------------------
#
# Project created by QtCreator 2016-08-09T11:30:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    king.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    piece.h \
    king.h \
    board.h

FORMS    += mainwindow.ui
