#include "delaunay.h"
//#include "boost/polygon/voronoi.hpp"
#include <QFile>
#include <QTextStream>
using namespace std;
//using namespace boost::polygon;

Delaunay::Delaunay(QString _filename)
{
    node.clear();
    edge.clear();
    QFile file(_filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream fi(&file);
    fi>>size_node;
    for(int i=0;i<size_node;i++)
    {
        double x, y;
        fi>>x>>y;
        node.push_back(graph_node(x, y));
    }
    file.close();
}



//void Delaunay::calc()
//{
//    typedef int coordinate_type;
//    typedef point_data<coordinate_type> Point;
//    typedef voronoi_diagram<double> VD;

//    vector<Point> points;points.clear();
//    for(size_t i=0;i<node.size();i++){
//        points.push_back(Point(node[i].get_x(), node[i].get_y()));
//    }
//    VD vd;
//    construct_voronoi(points.begin(), points.end(), &vd);

//    for (voronoi_diagram<double>::const_edge_iterator it = vd.edges().begin(); it != vd.edges().end(); ++++it) {
//        int x=it->cell()->source_index(), y=it->twin()->cell()->source_index();
//        edge.push_back(graph_edge(x, y, euclidean_distance(points[x], points[y])));
//    }

//}
