#ifndef ZODIAC_PERIMETER_H
#define ZODIAC_PERIMETER_H

#include <QGraphicsObject>

namespace relarank
{

class Node;
class Plug;

class Perimeter: public QGraphicsObject
{
    Q_OBJECT
public:		// methods

    explicit Perimeter(Node * parent);

    inline qreal getRadius() const
    {
        return m_radius;
    }

    inline void setRadius(qreal radius)
    {
        prepareGeometryChange();
        m_radius = qMax(s_minRadius, radius);
    }

    inline void updateStyle()
    {
        update();
    }

public:			// static methods

    inline static qreal getMinRadius()
    {
        return s_minRadius;
    }

    inline static void setMinRadius(qreal radius)
    {
        s_minRadius = qMax(0., radius);
    }

    inline static qreal getMaxOpacity()
    {
        return s_maxOpacity;
    }

    inline static void setMaxOpacity(qreal opacity)
    {
        s_maxOpacity = qMax(0., qMin(1., opacity));
    }

    inline static QColor getColor()
    {
        return s_color;
    }

    inline static void setColor(QColor color)
    {
        s_color = color;
    }

    inline static const Plug *getClosestPlugToMouse()
    {
        return s_closestPlugToMouse;
    }

    inline static void clearClosestPlugToMouse()
    {
        s_closestPlugToMouse = nullptr;
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

    void hoverMoveEvent(QGraphicsSceneHoverEvent * event);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

private:			// members

    Node * m_node;

    qreal m_radius;

private:			// static members

    static qreal s_minRadius;

    static qreal s_maxOpacity;

    static QColor s_color;

    static Plug *s_closestPlugToMouse;

    static bool s_mouseWasDragged;

};

}				// namespace relarank

#endif // ZODIAC_PERIMETER_H
