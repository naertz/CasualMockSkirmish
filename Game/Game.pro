QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attack.cpp \
    print.cpp \
    skirmish.cpp \
    start.cpp \
    user_input.cpp \
    warrior.cpp \
    warrior/bandit.cpp \
    warrior/basilisk.cpp \
    warrior/dragon.cpp \
    warrior/dwarf.cpp \
    warrior/ghost.cpp \
    warrior/goblin.cpp \
    warrior/grunt.cpp \
    warrior/knight.cpp \
    warrior/mammoth.cpp \
    warrior/ogre.cpp \
    warrior/serpent.cpp \
    warrior/snowman.cpp \
    warrior/sorcerer.cpp \
    warrior/troll.cpp \
    warrior/witch.cpp \
    warrior/wolf.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    attack.h \
    entity.h \
    print.h \
    skirmish.h \
    user_input.h \
    warrior.h \
    warrior/bandit.h \
    warrior/basilisk.h \
    warrior/dragon.h \
    warrior/dwarf.h \
    warrior/ghost.h \
    warrior/goblin.h \
    warrior/grunt.h \
    warrior/knight.h \
    warrior/mammoth.h \
    warrior/ogre.h \
    warrior/serpent.h \
    warrior/snowman.h \
    warrior/sorcerer.h \
    warrior/troll.h \
    warrior/witch.h \
    warrior/wolf.h

DISTFILES += \
    Makefile \
    README.md
