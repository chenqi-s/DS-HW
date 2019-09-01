#ifndef Solver_H
#define Solver_H

#include "graph.h"
#include <QString>




class oper
{
public:
    int type;
    int from;
    int to;
    oper(int K,int F,int T):type(K),from(F),to(T){}
};



class Solver
{
public:
    std::vector<graph_node> node;
    std::vector<graph_edge> edge;
    double ** matrix;
    int ** map;
    int size_node, size_edge;
    std::vector<graph_edge> ansedge;
    std::vector<oper> QSHistory;
    int * visited;

    Solver(int _size_node = 0, int _size_edge = 0);
    Solver(QString _filename);
    //void calc();
    std::vector<graph_node> & get_node();
    std::vector<graph_edge> & get_edge();
    std::vector<graph_edge> & get_ansedge();
    void print(QString _filename);
    virtual ~Solver();

    void BFSTraverse(int start);
    void DFSTraverse_D(int start);
    void DFSTraverse_ND(int start);
    void DFS(int v);
};



inline Solver::Solver(int _size_node, int _size_edge)
:size_node(_size_node), size_edge(_size_edge)
{
    node.clear();
    edge.clear();
    ansedge.clear();
}

inline std::vector<graph_node> & Solver::get_node()
{
    return node;
}

inline std::vector<graph_edge> & Solver::get_edge()
{
    return edge;
}


inline std::vector<graph_edge> & Solver::get_ansedge()
{
    return ansedge;
}


#endif // Solver_H
