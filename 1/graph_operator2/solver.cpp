#include "solver.h"
#include "png.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <fstream>
#include <QDebug>
#include <QQueue>
#include <QStack>

using namespace std;
Solver::Solver(QString _filename)
{
    node.clear();
    edge.clear();
    ansedge.clear();
    QFile file(_filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream fi(&file);
    fi>>size_node;
    int size_view=size_node+8;            // set the veiw size ,no too small!!
    int half_size_view=size_view/2;
    bool Map[size_view][size_view];
    srand(time(NULL));
    for(int i=1,x,y;i<=size_node;++i)
    {
        for(x=rand()%size_view,y=rand()%size_view;Map[x][y];x=rand()%size_view,y=rand()%size_view);
        Map[x][y]=true;
        node.push_back(graph_node(i,x-half_size_view, y-half_size_view));
    }

    matrix = (double**) malloc(size_node*sizeof(double*)) ;
    map= (int**) malloc(size_node*sizeof(int*)) ;
    for(int i=0; i<size_node; ++i)
    {
        matrix[i] = (double *)malloc(size_node * sizeof(double));
        map[i] = (int *)malloc(size_node * sizeof(int));
    }

    double weight;
    int k=0;
    for(int i=0;i<size_node;++i)
    {
        for(int j=0;j<size_node;++j)
        {
            fi>>weight;
            if(i!=j)
            {
                if(weight>0)
                {
                    edge.push_back(graph_edge(i,j,weight));
                    map[i][j]=k;++k;
                }

                matrix[i][j]=weight;
            }
            else
                matrix[i][j]=0;
        }
    }

    file.close();
}



Solver::~Solver()
{
    for (int i=0;i<size_node;++i)
    {
        free(matrix[i]);
        free(map[i]);
    }
    free(matrix);
    free(map);
}


void Solver::BFSTraverse(int start)
{

    int i,j;
    visited=new int[size_node];
    for(i=0;i<this->size_node;++i)
        visited[i]=0;
    QQueue<double> Q;
    Q.clear();
    ansedge.clear();
    QSHistory.clear();
    QSHistory.push_back(oper(0,0,0));
    i=start;
    while(1)
    {
        if(!visited[i])
        {
            visited[i]=1;
            Q.enqueue(i);
            QSHistory.push_back(oper(2,i,i));
            while(!Q.isEmpty())
            {
                i=Q.head();
                Q.dequeue();      //将队中元素出队列，赋值给i
                QSHistory.push_back(oper(-1,0,i));
                for(j=0;j<size_node;++j)
                {
                    if(matrix[i][j]>0 && !visited[j])      //其他顶点与该顶点存在边   且未访问过
                    {
                        visited[j]=1;
                        Q.enqueue(j);                 //入队列
                        QSHistory.push_back(oper(1,i,j));
                        ansedge.push_back(edge[map[i][j]]);
                    }
                }
            }
        }
        if(i==(start+size_node-1)%size_node)
            break;
        else if(i<size_node-1)
            ++i;
        else if(i==size_node-1)
            i=0;
    }
//    for(int i=0;i< QSHistory.size();++i)
//        qDebug()<<QSHistory[i].type<< " " << QSHistory[i].from<< " "<< QSHistory[i].to<<endl;
    delete [] visited;
}






void Solver::DFS(int v)
{
    int w;
    visited[v]=1;
    for(w=0;w<this->size_node;++w)
    {
        if(!visited[w] && matrix[v][w]>0)
        {
            QSHistory.push_back(oper(1,v,w));
            ansedge.push_back(edge[map[v][w]]);
            DFS(w);
            QSHistory.push_back(oper(-1,0,w));
        }
    }

}


void Solver::DFSTraverse_D(int start)
{
    int v;
    visited=new int[size_node];
    for(v=0;v<this->size_node;++v)
        visited[v]=0;
    ansedge.clear();
    QSHistory.clear();
    QSHistory.push_back(oper(0,1,0));
    for(v=start;v!=(start+size_node-1)%size_node;v=(v+1)%size_node)
    {
        if(!visited[v])
        {
            QSHistory.push_back(oper(2,v,v));
            DFS(v);
            QSHistory.push_back(oper(-1,0,v));
        }

    }

    delete [] visited;
}



void Solver::DFSTraverse_ND(int start)
{
    visited=new int[size_node];
    for(int v=0;v<this->size_node;++v)
        visited[v]=0;
    ansedge.clear();
    QSHistory.clear();
    QSHistory.push_back(oper(0,2,0));
    QStack<int> s;
    s.clear();
    s.push(start);
    QSHistory.push_back(oper(2,start,start));
    visited[start]=1;
    while(!s.isEmpty())
    {
        int data, i;
        data = s.top();//取top的顶点
        for(i = 0; i < size_node; ++i)
        {
            if(matrix[data][i] >0 && visited[i] == 0)
            {

                visited[i] = 1;
                s.push(i);
                QSHistory.push_back(oper(1,data,i));
                ansedge.push_back(edge[map[data][i]]);
                break;//深度优先
            }
        }
        if(i == size_node)//data相邻的结点都访问结束了，就弹出data
        {
            QSHistory.push_back(oper(-1,0,s.top()));
            s.pop();
        }
    }


//    for(int i=0;i< QSHistory.size();++i)
//           qDebug()<<QSHistory[i].type<< " " << QSHistory[i].from<< " "<< QSHistory[i].to<<endl;

}





void Solver::print(QString _filename)
{
    //if(node.size()>=1000)return;
    for(size_t i=0;i<node.size();i++)node[i].reverse_y();
    const int circle_r = 15, line_r = 5, dis = 20;
    if(node.empty())return;
    int ma_x=node[0].get_x(), mi_x=node[0].get_x(), ma_y=node[0].get_y(), mi_y=node[0].get_y();
    for(size_t i=0;i<node.size();i++){
        ma_x=max(ma_x, node[i].get_x());
        mi_x=min(mi_x, node[i].get_x());
        ma_y=max(ma_y, node[i].get_y());
        mi_y=min(mi_y, node[i].get_y());
    }
    mi_x-=2, mi_y-=2, ma_x+=2, ma_y+=2;
    png map(int((ma_x-mi_x)*dis), int((ma_y-mi_y)*dis));
    for(size_t i=0;i<node.size();i++){
        map.circle(int((node[i].get_x()-mi_x)*dis), int((node[i].get_y()-mi_y)*dis), circle_r);
    }
    for(size_t i=0;i<ansedge.size();i++){
        map.line(int((node[ansedge[i].get_x()].get_x()-mi_x)*dis), int((node[ansedge[i].get_x()].get_y()-mi_y)*dis),
                int((node[ansedge[i].get_y()].get_x()-mi_x)*dis), int((node[ansedge[i].get_y()].get_y()-mi_y)*dis),
                line_r);
    }
    map.save(_filename);
    for(size_t i=0;i<node.size();i++)
        node[i].reverse_y();
}
