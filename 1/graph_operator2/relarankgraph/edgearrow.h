#ifndef ZODIAC_EDGEARROW_H
#define ZODIAC_EDGEARROW_H

#include <QGraphicsObject>

namespace relarank
{

class EdgeLabel;
class BaseEdge;

enum class ArrowKind {
    SINGLE = 0, // A single triangle pointing into the direction of the edge.
    DOUBLE = 1, // Two mirrored triangles, pointing along different directions of the edge.
};

class EdgeArrow: public QGraphicsObject
{
    Q_OBJECT
public:		// methods

    explicit EdgeArrow(BaseEdge * edge);

    void setTransformation(const QPointF & pos, qreal angle);

    inline void setLabel(EdgeLabel * label)
    {
        m_label = label;
    }

    inline void setKind(ArrowKind kind)
    {
        m_kind = kind;
    }

public:			// static methods

    inline static qreal getArrowLength()
    {
        return s_arrowHalfLength * 2;
    }

    inline static qreal getArrowWidth()
    {
        return s_arrowHalfWidth * 2;
    }

    static void defineArrow(qreal length, qreal width);

    inline static QColor getArrowColor()
    {
        return s_arrowColor;
    }

    inline static void setArrowColor(const QColor & color)
    {
        s_arrowColor = color;
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

private:			// members

    BaseEdge * m_edge;

    QPolygonF m_arrowPolygon;

    ArrowKind m_kind;

    EdgeLabel *m_label;

private:			// static members

    static qreal s_doubleGap;

    static qreal s_arrowHalfLength;

    static qreal s_arrowHalfWidth;

    static QColor s_arrowColor;

    static QPolygonF s_originalArrow;

    static QPolygonF s_originalDoubleArrow;

};

}				// namespace relarank

#endif // ZODIAC_EDGEARROW_H
