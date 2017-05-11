TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=-L /usr/lib -lcurses
LIBS+=-L /usr/lib -lpthread

SOURCES += main.cpp \
    ValueItem.cpp \
    Item.cpp \
    BoolItem.cpp \
    SubmenuItem.cpp \
    Menu.cpp \
    IndexMenu.cpp \
    Submenu.cpp \
    MenuHistory.cpp \
    Controlller.cpp \
    Object.cpp \
    InstructionGetter.cpp \
    KeyboardInstructionGetter.cpp \
    FIFOInstructionGetter.cpp \
    ExitItem.cpp \
    InputItem.cpp

HEADERS += \
    ValueItem.h \
    Item.h \
    Object.h \
    BoolItem.h \
    SubmenuItem.h \
    Menu.h \
    IndexMenu.h \
    Submenu.h \
    MenuHistory.h \
    Controller.h \
    Parameter.h \
    InstructionGetter.h \
    KeyboardInstructionGetter.h \
    FIFOInstructionGetter.h \
    ExitItem.h \
    InputItem.h

