#include "ranklist.h"
#include <algorithm>
#include <cstdio>
using namespace std;
void RankList::changelist(vector<graph_edge> &_edge, vector<NodeCtrl*> &_np)
{
    tmp.resize(_edge.size());
    for(size_t i=0;i<_edge.size();i++){
        tmp[i].x = _edge[i];
        tmp[i].npx = _np[_edge[i].get_x()];
        tmp[i].npy = _np[_edge[i].get_y()];
    }
    for(size_t i=0;i<tmp.size();i++){
        QStringList t;
        QVariant from(tmp[i].x.get_x()+1), to(tmp[i].x.get_y()+1), value(tmp[i].x.get_w());
        t<<from.toString()<<to.toString()<<value.toString();
        QTreeWidgetItem *ln = new QTreeWidgetItem(this, t);
        ln->setData(0x0100, 0x0100, int(i));
        this->addTopLevelItem(ln);
    }
    this->header()->resizeSections(QHeaderView::ResizeToContents);
    connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(NodeChange(QTreeWidgetItem*, QTreeWidgetItem*)));
}


void RankList::NodeChange(QTreeWidgetItem * current, QTreeWidgetItem * previous){
    for(size_t i=0;i<tmp.size();i++){
        if(tmp[i].npx)tmp[i].npx->setSelected(false);
        if(tmp[i].npy)tmp[i].npy->setSelected(false);
    }
    if(current&&tmp[current->data(0x0100, 0x0100).toInt()].npx)tmp[current->data(0x0100, 0x0100).toInt()].npx->setSelected(true);
    if(current&&tmp[current->data(0x0100, 0x0100).toInt()].npy)tmp[current->data(0x0100, 0x0100).toInt()].npy->setSelected(true);
}



