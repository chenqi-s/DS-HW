#ifndef ZODIAC_SCENE_H
#define ZODIAC_SCENE_H

#include <QGraphicsScene>
#include <QUuid>
#include <QSet>

namespace relarank
{

class DrawEdge;
class PlugEdge;
class Node;
class Plug;
class EdgeGroup;
class EdgeGroupPair;

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:		// methods

    explicit Scene(QObject * parent);

    virtual ~ Scene();

    Node *createNode(const QString & name, const QUuid & uuid = QUuid());

    bool removeNode(Node * node);

    QList < Node * >getNodes() const
    {
        return m_nodes.toList();
    }

    PlugEdge *createEdge(Plug * fromPlug, Plug * toPlug);

    void removeEdge(PlugEdge * edge);

    PlugEdge *getEdge(Plug * fromPlug, Plug * toPlug);

    void collapseAllNodes();

    inline DrawEdge *getDrawEdge()
    {
        return m_drawEdge;
    }

    void updateStyle();

private:			// members

    DrawEdge * m_drawEdge;

    QSet < Node * >m_nodes;

    QHash < QPair < Plug *, Plug * >, PlugEdge * >m_edges;

    QHash < uint, EdgeGroup * >m_edgeGroups;

    QSet < EdgeGroupPair * >m_edgeGroupPairs;

};

}				// namespace relarank

#endif // ZODIAC_SCENE_H
