#include "chainedge.h"
#include "chainnode.h"

#include <math.h>

#include <QPainter>
static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

//! [0]
Edge::Edge(Node *sourceNode, Node *destNode,QString text,QColor edge_color)
    :edgecolor(edge_color),edgetext(QStaticText(text))
{
    arrowSize=10;
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
}
//! [0]

//! [1]
Node *Edge::sourceNode() const
{
    return source;
}

Node *Edge::destNode() const
{
    return dest;
}
//! [1]

//! [2]
void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}
//! [2]

//! [3]
QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}
//! [3]

//! [4]
void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;
//! [4]

//! [5]
    // Draw the line itself
    painter->setPen(QPen(edgecolor, 3.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
//! [5]

//! [6]
    // Draw the arrows
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    //QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * arrowSize, cos(angle + Pi / 3) * arrowSize);
    //QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,cos(angle + Pi - Pi / 3) * arrowSize);
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize, cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,cos(angle - Pi + Pi / 3) * arrowSize);

    painter->setBrush(edgecolor);
    //painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

    painter->setBrush(Qt::black);
    QSizeF rect=edgetext.size();
    QPointF midpoint=(destPoint+sourcePoint)/2. + QPointF(rect.width()  / -2., -rect.height());
    painter->drawStaticText(midpoint , edgetext);

}
//! [6]
