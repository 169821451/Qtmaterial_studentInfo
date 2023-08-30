#-------------------------------------------------
#
# Project created by QtCreator 2023-08-15T21:00:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = material_test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        framelessWidget.cpp \
        main.cpp \
        materialtest.cpp \
        scrolltext.cpp

HEADERS += \
        framelessWidget.h \
        materialtest.h \
        scrolltext.h

FORMS += \
        framelessWidget.ui \
        materialtest.ui

#SDK
#LIBS += $$PWD/SKD/components.lib
#INCLUDEPATH += $$PWD/SDK/components
#PRE_TARGETDEPS += $$PWD/SKD/components.lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#----------------------------------------------------------

win32: LIBS += -L$$PWD/SDK/ -lcomponents

INCLUDEPATH += $$PWD/SDK/components
DEPENDPATH += $$PWD/SDK/components

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/SDK/components.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/SDK/libcomponents.a

RESOURCES += \
    src.qrc
