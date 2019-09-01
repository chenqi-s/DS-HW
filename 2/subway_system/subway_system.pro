#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T15:29:00
#
#-------------------------------------------------

QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subway_system
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


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    apphelp.cpp \
    graphics_view_zoom.cpp \
    graph.cpp \
    managelines.cpp \
    chartview.cpp \
    solution_show.cpp

HEADERS  += mainwindow.h \
    node.h \
    line.h \
    base.h \
    apphelp.h \
    graphics_view_zoom.h \
    graph.h \
    managelines.h \
    chartview.h \
    solution_show.h

FORMS    += mainwindow.ui \
    managelines.ui \
    solution_show.ui

RESOURCES += \
    resource.qrc
