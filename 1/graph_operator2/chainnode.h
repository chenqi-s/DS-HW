#ifndef CHAINNODE_H
#define CHAINNODE_H

#include <QGraphicsItem>
#include <QList>
#include <QStaticText>

class Edge;
class ChainShow;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

//! [0]
class Node : public QGraphicsItem
{
public:
    Node(ChainShow *graphWidget);
    void setpostion(qreal x, qreal y);
    void set(QStaticText text,QColor color);
    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    void calculateForces();
    bool advance();


    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QList<Edge *> edgeList;
    QColor nodecolor;
    QStaticText nodetext;
    QPointF newPos;
    QPointF realPos;
    ChainShow *graph;
};



inline void Node::set(QStaticText text,QColor color)
{nodetext=text,nodecolor=color;}

#endif // NODE_H
