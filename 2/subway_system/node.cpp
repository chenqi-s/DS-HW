#include "node.h"
#include <math.h>

#define EARTH_RADIUS  6378.137
#define  PI  3.1415926535898
#define Pi_p_cir PI/180.0



// 传入两个经纬度，计算之间的大致直线距离
double calcuDistance(double fLati1, double fLong1, double fLati2, double fLong2)
{
    double radLat1 = fLati1*Pi_p_cir;
    double radLat2 = fLati2*Pi_p_cir;
    double a = radLat1 - radLat2;
    double b = fLong1*Pi_p_cir - fLong2*Pi_p_cir;
    double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
    s*=EARTH_RADIUS;
    s = (int)(s * 10000000) / 10000;
    return s;
}

double Station::minLongitude = 200;
double Station::minLatitude = 200;
double Station::maxLongitude = 0;
double Station::maxLatitude = 0;

//构造函数
Station::Station()
{

}

//构造函数
Station::Station(QString nameStr, double longi, double lati, QList<int> linesList):
    name(nameStr), longitude(longi), latitude(lati)
{
    linesInfo=linesList.toSet();
}


//求取站点间实地直线距离
int Station::distance(Station other)
{
    return calcuDistance(latitude, longitude, other.latitude, other.longitude);
}
