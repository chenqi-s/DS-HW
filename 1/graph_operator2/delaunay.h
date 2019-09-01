#ifndef DELAUNAY_H
#define DELAUNAY_H

#include "graph.h"
#include <QString>

class Delaunay
{
protected:
    std::vector<graph_node> node;
    std::vector<graph_edge> edge;
    int size_node, size_edge;
public:
    Delaunay(int _size_node = 0, int _size_edge = 0);
    Delaunay(QString _filename);
    std::vector<graph_node> & get_node();
    std::vector<graph_edge> & get_edge();
    void addnode(double x, double y);
    //virtual void calc();
    virtual ~Delaunay();
};

inline Delaunay::Delaunay(int _size_node, int _size_edge)
    :size_node(_size_node), size_edge(_size_edge)
{
    node.clear();
    edge.clear();
}

inline std::vector<graph_node> & Delaunay::get_node()
{
    return node;
}

inline std::vector<graph_edge> & Delaunay::get_edge()
{
    return edge;
}

inline void Delaunay::addnode(double x, double y)
{
    node.push_back(graph_node(x, y));
}

inline Delaunay::~Delaunay()
{
}

#endif // DELAUNAY_H
