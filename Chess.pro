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
    board.cpp \
    queen.cpp \
    pawn.cpp \
    knight.cpp \
    bishop.cpp \
    rook.cpp \
    piece.cpp \
    igraphicscontroller.cpp \
    boardwidget.cpp \
    game.cpp \
    igamecontroller.cpp \
    pawntransformationdialog.cpp \
    piecevisitor.cpp

HEADERS  += mainwindow.h \
    piece.h \
    king.h \
    board.h \
    queen.h \
    pawn.h \
    knight.h \
    bishop.h \
    rook.h \
    igraphicscontroller.h \
    pieces_title.h \
    boardwidget.h \
    game.h \
    igamecontroller.h \
    pawntransformationdialog.h \
    ivisitor.h \
    piecevisitor.h

FORMS    += mainwindow.ui



#------------------------------------
#by myself
CONFIG += c++11
#------------------------------------
