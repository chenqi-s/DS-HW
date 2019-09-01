
#include "chainedge.h"
#include "chainnode.h"
#include "chainshow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QSizeF>

//! [0]
Node::Node(ChainShow *graphWidget)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

}
//! [0]

//! [1]
void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList<Edge *> Node::edges() const
{
    return edgeList;
}
//! [1]

void Node::setpostion(qreal x, qreal y)
{
    //newPos=QPointF(x,y);
    this->setPos(x,y);
    realPos=QPointF(x,y);
}


//! [2]
void Node::calculateForces()
{
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos();
        return;
    }
//! [2]

//! [3]
    // Sum up all forces pushing this item away
    qreal xvel =0;
    qreal yvel =0;


//! [3]

//! [4]
    // Now subtract all forces pulling items together
    QPointF vec;
    double weight = 90.0;
    foreach (Edge *edge, edgeList) {

        if (edge->sourceNode() == this)
            //vec = mapToItem(edge->destNode(), 0,0);
            vec = pos()-edge->destNode()->pos();
        else
            //vec = mapToItem(edge->sourceNode(), 0,0);
            vec = pos()-edge->sourceNode()->pos();
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }
//! [4]

    vec = pos()- realPos;
    xvel -= 2.5* vec.x() / weight;
    yvel -= 2.5* vec.y() / weight;

//! [5]
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;
//! [5]

//! [6]
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}
//! [6]

//! [7]
bool Node::advance()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}
//! [7]

//! [8]
QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -15 - adjust, -15 - adjust, 30 + adjust, 30 + adjust);
}
//! [8]

//! [9]
QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-15, -15, 30, 30);
    return path;
}
//! [9]

//! [10]
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(Qt::darkGray);
//    painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
    }
    painter->setBrush(nodecolor);

    painter->setPen(QPen(nodecolor, 0));
    painter->drawEllipse(-15, -15, 30, 30);

    painter->setPen(QPen(Qt::green,3));
    QSizeF textSize = nodetext.size();
    QPointF m_textPos = QPointF(textSize.width() / -2., textSize.height() / -2.);
    painter->drawStaticText(m_textPos,nodetext);
    //painter->drawText(textRect,"1");
}
//! [10]

//! [11]
QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}
//! [11]

//! [12]
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
//! [12]


