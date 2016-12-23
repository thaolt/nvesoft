#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T15:15:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$OUT_PWD/../dist/
TARGET = NVEAssistant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -luser32 -lshell32 -lgdi32

SOURCES += main.cpp\
        mainwindow.cpp \
    configform.cpp

HEADERS  += mainwindow.h \
    configform.h

FORMS    += mainwindow.ui \
    configform.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../3rdparty/litecadapi/release/ -llitecadapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../3rdparty/litecadapi/debug/ -llitecadapi

INCLUDEPATH += $$PWD/../3rdparty/litecadapi
DEPENDPATH += $$PWD/../3rdparty/litecadapi

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdparty/litecadapi/release/liblitecadapi.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdparty/litecadapi/debug/liblitecadapi.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdparty/litecadapi/release/litecadapi.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdparty/litecadapi/debug/litecadapi.lib
