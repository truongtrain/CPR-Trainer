#-------------------------------------------------
#
# Project created by QtCreator 2018-11-21T21:26:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPRGame
TEMPLATE = app

CONFIG += console c++11

unix:!macx: LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
unix:!macx: INCLUDEPATH += ../Box2D
LIBS += -L"../Box2D/Build/bin/x86_64/Debug"
LIBS += -lBox2D # TODO: Figure out why this crashes the compile.  Worked on the 'WelcomeScreen' branch.

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        gamewindow.cpp \
    welcomescreen.cpp \
    mainbackup.cpp \
    spritesheetparser.cpp

HEADERS += \
        gamewindow.h \
    welcomescreen.h \
    spritesheetparser.h

FORMS += \
        gamewindow.ui \
    welcomescreen.ui

RESOURCES += \
    resources.qrc
