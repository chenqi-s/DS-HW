#ifndef ZODIAC_EDGEGROUP_H
#define ZODIAC_EDGEGROUP_H

#include <QObject>
#include <QPair>
#include <QSet>

#include "edgegroupinterface.h"

namespace relarank
{

class EdgeGroupPair;
class Node;
class Scene;
class PlugEdge;
class StraightEdge;

class EdgeGroup: public QObject, public EdgeGroupInterface
{

    Q_OBJECT
public:		// methods

    explicit EdgeGroup(Scene * scene, Node * fromNode, Node * toNode,
                       EdgeGroupPair * pair);

    ~EdgeGroup();

    void addEdge(PlugEdge * edge);

    void removeEdge(PlugEdge * edge);

    void increaseBentCount();

    void decreaseBentCount();

    void updateVisibility();

    uint getHash() const;

    bool isVisible() const;

    void setVisibility(bool visibility);

    inline int getEdgeCount() const
    {
        return m_edges.size();
    }

    inline const QSet < PlugEdge * >&getEdges() const
    {
        return m_edges;
    }

    inline EdgeGroupPair *getEdgeGroupPair() const
    {
        return m_pair;
    }

    QString getLabelText();

    void updateLabelText();

    void updateStyle();

public:			// static methods

    static inline uint getHashOf(Node * fromNode, Node * toNode, uint seed =
                                     0)
    {
        return qHash(QPair < Node *, Node * >(fromNode, toNode), seed);
    }

private slots:
    void removalRequested();

private:			// members

    Scene * m_scene;

    Node *m_fromNode;

    Node *m_toNode;

    EdgeGroupPair *m_pair;

    QSet < PlugEdge * >m_edges;

    StraightEdge *m_straightEdge;

    int m_bentEdgesCount;

};

}				// namespace relarank

#endif // ZODIAC_EDGEGROUP_H
