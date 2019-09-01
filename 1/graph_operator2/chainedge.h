
#ifndef CHAINEDGE_H
#define CHAINEDGE_H

#include <QGraphicsItem>
#include <QStaticText>
class Node;

//! [0]
class Edge : public QGraphicsItem
{
public:
    Edge(Node *sourceNode, Node *destNode,QString text="",QColor edge_color=Qt::black);

    Node *sourceNode() const;
    Node *destNode() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    Node *source, *dest;
    QColor edgecolor;
    QStaticText edgetext;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};
//! [0]

#endif // EDGE_H
