TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

unix:!macx: LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
unix:!macx: INCLUDEPATH += ../Box2D
LIBS += -L"../Box2D/Build/bin/x86_64/Debug"
LIBS += -lBox2D
