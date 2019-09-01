#ifndef ZODIAC_STRAIGHTEDGE_H
#define ZODIAC_STRAIGHTEDGE_H

#include "baseedge.h"

namespace relarank
{

class Node;
class Scene;
class EdgeGroupInterface;

class StraightEdge: public BaseEdge
{
    Q_OBJECT
public:		// methods

    explicit StraightEdge(Scene * scene, EdgeGroupInterface * group,
                          Node * fromNode, Node * toNode);

    void nodePositionHasChanged();

    void updateLabel();

    inline Node *getFromNode() const
    {
        return m_fromNode;
    }

    inline Node *getToNode() const
    {
        return m_toNode;
    }

    void placeArrowAt(qreal fraction) override;

signals:
    void removalRequested();

protected:			// methods

    virtual void updateShape() override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

protected:			// members

    EdgeGroupInterface * m_group;

    Node *m_fromNode;

    Node *m_toNode;

    QPointF m_startPoint;

    QPointF m_endPoint;

};

}				// namespace relarank

#endif				// ZODIAC_STRAIGHTEDGE_H
