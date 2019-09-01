#ifndef RANKLIST_H
#define RANKLIST_H

#include <QTreeWidget>
#include <QHeaderView>
#include "nodectrl.h"
#include "graph.h"
#include <vector>

class RankList : public QTreeWidget
{
    Q_OBJECT
public:
    RankList(QWidget *parent = 0)
        :QTreeWidget(parent)
    {
        QStringList headers;
        headers << tr("From") << tr("To") << tr("Value");
        this->setColumnCount(2);
        this->setHeaderLabels(headers);
        this->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    void changelist(std::vector<graph_edge> &_edge, std::vector<NodeCtrl*> &_np);
public slots:
    void NodeChange(QTreeWidgetItem * current, QTreeWidgetItem * previous);
private:
    struct TmpNode
    {
        graph_edge x;
        NodeCtrl * npx, *npy;
    };
    std::vector<TmpNode> tmp;
};

#endif // RANKLIST_H
