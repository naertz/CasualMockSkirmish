QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dragon.cpp \
    dwarf.cpp \
    goblin.cpp \
    grunt.cpp \
    ogre.cpp \
    print.cpp \
    skirmish.cpp \
    start.cpp \
    troll.cpp \
    user_input.cpp \
    warrior.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    dragon.h \
    dwarf.h \
    entity.h \
    goblin.h \
    grunt.h \
    ogre.h \
    print.h \
    skirmish.h \
    troll.h \
    user_input.h \
    warrior.h

DISTFILES += \
    README.md
