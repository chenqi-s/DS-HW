#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T16:43:44
#
#-------------------------------------------------

QT       += core gui
QT += datavisualization

contains(TARGET, qml.*) {
    QT += qml quick
}
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graph_operator2
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
    relarankgraph/baseedge.cpp \
    relarankgraph/bezieredge.cpp \
    relarankgraph/drawedge.cpp \
    relarankgraph/edgearrow.cpp \
    relarankgraph/edgegroup.cpp \
    relarankgraph/edgegroupinterface.cpp \
    relarankgraph/edgegrouppair.cpp \
    relarankgraph/edgelabel.cpp \
    relarankgraph/labeltextfactory.cpp \
    relarankgraph/node.cpp \
    relarankgraph/nodehandle.cpp \
    relarankgraph/nodelabel.cpp \
    relarankgraph/perimeter.cpp \
    relarankgraph/plug.cpp \
    relarankgraph/plugarranger.cpp \
    relarankgraph/plugedge.cpp \
    relarankgraph/plughandle.cpp \
    relarankgraph/pluglabel.cpp \
    relarankgraph/scene.cpp \
    relarankgraph/scenehandle.cpp \
    relarankgraph/straightdoubleedge.cpp \
    relarankgraph/straightedge.cpp \
    relarankgraph/view.cpp \
    collapsible.cpp \
    lodepng.cpp \
    mainctrl.cpp \
    nodectrl.cpp \
    nodeproperties.cpp \
    png.cpp \
    propertyeditor.cpp \
    ranklist.cpp \
    apphelp.cpp \
    matrixshow.cpp \
    graphdatagenerator.cpp \
    chainshow.cpp \
    qsshow.cpp \
    solver.cpp \
    chainedge.cpp \
    chainnode.cpp \
    searchset.cpp

HEADERS  += mainwindow.h \
    relarankgraph/baseedge.h \
    relarankgraph/bezieredge.h \
    relarankgraph/drawedge.h \
    relarankgraph/edgearrow.h \
    relarankgraph/edgegroup.h \
    relarankgraph/edgegroupinterface.h \
    relarankgraph/edgegrouppair.h \
    relarankgraph/edgelabel.h \
    relarankgraph/labeltextfactory.h \
    relarankgraph/node.h \
    relarankgraph/nodehandle.h \
    relarankgraph/nodelabel.h \
    relarankgraph/perimeter.h \
    relarankgraph/plug.h \
    relarankgraph/plugarranger.h \
    relarankgraph/plugedge.h \
    relarankgraph/plughandle.h \
    relarankgraph/pluglabel.h \
    relarankgraph/scene.h \
    relarankgraph/scenehandle.h \
    relarankgraph/straightdoubleedge.h \
    relarankgraph/straightedge.h \
    relarankgraph/utils.h \
    relarankgraph/view.h \
    collapsible.h \
    graph.h \
    lodepng.h \
    mainctrl.h \
    nodectrl.h \
    nodeproperties.h \
    png.h \
    propertyeditor.h \
    ranklist.h \
    apphelp.h \
    matrixshow.h \
    graphdatagenerator.h \
    chainshow.h \
    qsshow.h \
    solver.h \
    chainedge.h \
    chainnode.h \
    searchset.h

FORMS    += mainwindow.ui \
    searchset.ui

RESOURCES += \
    resource/icons.qrc \
    resource/html.qrc

RC_FILE = resource/Qt_ico.rc

DISTFILES += \
    graph_operator.pro.user
