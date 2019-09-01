#ifndef ZODIAC_NODELABEL_H
#define ZODIAC_NODELABEL_H

#include <QFont>
#include <QGraphicsObject>
#include <QPen>
#include <QStaticText>

namespace relarank
{

class Node;

class NodeLabel: public QGraphicsObject
{
    Q_OBJECT
public:		// methods

    explicit NodeLabel(Node * parent);

    void setText(const QString & text);

    inline qreal getHeight() const
    {
        return m_boundingRect.height();
    }

    void updateStyle();

public:			// static methods

    static inline QColor getTextColor()
    {
        return s_textColor;
    }

    static inline void setTextColor(const QColor & color)
    {
        s_textColor = color;
    }

    static inline QColor getBackgroundColor()
    {
        return s_backgroundColor;
    }

    static inline void setBackgroundColor(const QColor & color)
    {
        s_backgroundColor = color;
    }

    static inline QColor getLineColor()
    {
        return s_lineColor;
    }

    static inline void setLineColor(const QColor & color)
    {
        s_lineColor = color;
        s_linePen.setColor(color);
    }

    static inline qreal getLineWidth()
    {
        return s_outlineWidth;
    }

    static inline void setLineWidth(qreal width)
    {
        s_outlineWidth = qMax(0., width);
        s_linePen.setWidthF(width);
    }

    static inline qreal getCornerRadius()
    {
        return s_roundEdgeRadius;
    }

    static inline void setCornerRadius(qreal radius)
    {
        s_roundEdgeRadius = radius;
    }

    static inline qreal getVerticalMargin()
    {
        return s_verticalMargin;
    }

    static inline void setVerticalMargin(qreal margin)
    {
        s_verticalMargin = margin;
    }

    static inline qreal getHorizontalMargin()
    {
        return s_horizontalMargin;
    }

    static inline void setHorizontalMargin(qreal margin)
    {
        s_horizontalMargin = margin;
    }

    static inline QString getFontFamily()
    {
        return s_font.family();
    }

    static inline void setFontFamily(const QString & family)
    {
        s_font.setFamily(family);
    }

    static inline qreal getPointSize()
    {
        return s_font.pointSizeF();
    }

    static inline void setPointSize(qreal pointSize)
    {
        s_font.setPointSizeF(qMax(0., pointSize));
    }

    static inline int getWeight()
    {
        return s_font.weight();
    }

    static inline void setWeight(QFont::Weight weight)
    {
        s_font.setWeight(weight);
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

private:			// members

    QStaticText m_text;

    QRectF m_outlineRect;

    QRectF m_boundingRect;

    QPointF m_textPos;

private:			// static members

    static QColor s_textColor;

    static QColor s_backgroundColor;

    static QColor s_lineColor;

    static qreal s_outlineWidth;

    static uint s_roundEdgeRadius;

    static qreal s_verticalMargin;

    static qreal s_horizontalMargin;

    static QFont s_font;

    static QPen s_linePen;
};

}				// namespace relarank

#endif // ZODIAC_NODELABEL_H
