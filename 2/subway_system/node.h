#ifndef NODE_H
#define NODE_H

#include "base.h"


//所有站点的边界位置


class SubwayGraph;
class QTextStream;

//地铁站点类定义
class Station
{
protected:
    int id;
    QString name;
    double longitude, latitude;
    QSet<int> linesInfo;

    static double minLongitude, minLatitude, maxLongitude, maxLatitude;
    //求取站点间实地直线距离
    int distance(Station another);

    //声明友元
    friend class SubwayGraph;
    friend class QTextStream;
public:
    //构造函数
    Station();
    Station(QString nameStr, double longi, double lati, QList<int> linesList);
};



#endif // NODE_H

