#-------------------------------------------------
#
# Project created by QtCreator 2015-07-28T14:12:30
#
#-------------------------------------------------

QT       += core gui
#QT       += core

#QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello


#CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp\
    metier/plateau.cpp \
    metier/jeton.cpp \
    metier/othello.cpp \
    pattern/sujetdobservation.cpp \
    vue/mainwindow.cpp \
    vue/vuetexte.cpp \
    vue/vuegraphique.cpp

HEADERS  += \
    metier/plateau.h \
    metier/Couleur.h \
    metier/jeton.h \
    metier/othello.h \
    pattern/observateur.h \
    pattern/sujetdobservation.h \
    vue/mainwindow.h \
    vue/vuetexte.h \
    vue/vuegraphique.h

FORMS    += \
    vue/mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors

RESOURCES += \
    imageOthello/imageothello.qrc




