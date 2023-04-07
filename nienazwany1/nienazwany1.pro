QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle
#QMAKE_CXXFLAGS += -O2
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


######################################################################################
#WINDOWS
# put SFML file in the same location as project
LIBS += -L"C:\Users\sebaj\Documents\SFML-2.5.1\lib" #change this
LIBS += -L"C:\Users\sebaj\Documents\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "C:\Users\sebaj\Documents\SFML-2.5.1\include" #change this
DEPENDPATH += "C:\Users\sebaj\Documents\SFML-2.5.1\include" #change this
#####################################################################################



SOURCES += \
        Entity.cpp \
        Game.cpp \
        Levels.cpp \
        MainMenu.cpp \
        Player.cpp \
        WindowHandler.cpp \
        main.cpp \
        map.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Entity.h \
    Game.h \
    Levels.h \
    MainMenu.h \
    Player.h \
    WindowHandler.h \
    map.h
