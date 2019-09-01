#ifndef LINE_H
#define LINE_H

#include "base.h"

//定义边类型

class SubwayGraph;
class QTextStream;



typedef QPair<int,int> Edge;

//线路类
class Line
{
protected:
    int id;
    QString name;
    QColor color;
    QVector <QString> fromTo;
    QSet<int> stationsSet;
    QSet<Edge> edges;
public:
    //构造函数
    Line(){};
    Line(QString lineName, QColor lineColor):name(lineName), color(lineColor)
    {};

    //声明友元
    friend class SubwayGraph;
    friend class QTextStream;
};



#endif // LINE_H
