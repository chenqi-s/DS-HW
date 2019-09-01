#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <QString>

class graph_edge
{
private:
    int x, y;
    double w;
public:
    int get_x() const;
    int get_y() const;
    double get_w() const;
    graph_edge(int _x = 0, int _y = 0, double _w = 0.0);
    bool operator< (const graph_edge & b) const;
};



class graph_node
{
private:
    int id;
    int x,y;
    std::vector < graph_edge > edge;
public:
    QString get_id() const;
    int get_x() const;
    int get_y() const;

    void reverse_y();
    std::vector < graph_edge > & get_edge();
    graph_node(int _id=0,int _x = 0, int _y = 0);
    std::vector < graph_edge >::iterator insert(graph_edge x);
    std::vector < graph_edge >::iterator insert(int x, int y, double w);
};

inline graph_edge::graph_edge(int _x, int _y, double _w)
    : x(_x), y(_y),w(_w)
{
}

inline bool graph_edge::operator< (const graph_edge & b) const
{
    return w < b.w;
}

inline int graph_edge::get_x() const
{
    return x;
}

inline int graph_edge::get_y() const
{
    return y;
}



inline double graph_edge::get_w() const
{
    return w;
}

inline graph_node::graph_node(int _id,int _x, int _y)
    : id(_id),x(_x), y(_y)
{
    edge.clear();
}

inline std::vector < graph_edge >::iterator graph_node::insert(graph_edge x)
{
    edge.push_back(x);
    return --edge.end();
}

inline std::vector < graph_edge >::iterator graph_node::insert(int x, int y, double w)
{
    edge.push_back(graph_edge(x, y, w));
    return --edge.end();
}

inline int graph_node::get_x() const
{
    return x;
}

inline int graph_node::get_y() const
{
    return y;
}


inline QString graph_node::get_id() const
{
    return QString::number(id);
}


inline void graph_node::reverse_y()
{
    y=-y;
}


inline std::vector < graph_edge > & graph_node::get_edge()
{
    return edge;
}


#endif // GRAPH_H
