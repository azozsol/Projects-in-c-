TEMPLATE = lib

CONFIG -= qt
CONFIG += staticlib

include(../../config.pri)

SOURCES += \
        Game.cpp \
        Marble.cpp \
        Observable.cpp \
        Position.cpp \
        main.cpp

HEADERS += \
    Direction.h \
    Game.h \
    GameStatus.h \
    Marble.h \
    Model.h \
    Observable.h \
    Observer.h \
    Player.h \
    Position.h

DISTFILES += \
    abalonecore.pri
