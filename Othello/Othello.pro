#-------------------------------------------------
#
# Project created by QtCreator 2015-07-28T14:12:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    metier/pion.cpp

HEADERS  += mainwindow.h \
    metier/pion.h \
    metier/Couleur.h

FORMS    += mainwindow.ui
