#ifndef ZODIAC_PLUGLABEL_H
#define ZODIAC_PLUGLABEL_H

#include <QFont>
#include <QGraphicsItem>
#include <QStaticText>

namespace relarank
{

class Plug;

class PlugLabel: public QGraphicsItem
{

public:			// methods

    explicit PlugLabel(Plug * parent);

    void updateShape();

    inline void setHighlight(bool highlight)
    {
        m_isHighlighted = highlight;
        update();
    }

    void updateStyle();

public:			// static methods

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

    static inline QColor getColor()
    {
        return s_color;
    }

    static inline void setColor(const QColor & color)
    {
        s_color = color;
    }

    static inline qreal getLabelDistance()
    {
        return s_labelDistance;
    }

    static inline void setLabelDistance(qreal distance)
    {
        s_labelDistance = distance;
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

private:			// members

    Plug * m_plug;

    QStaticText m_text;

    QRectF m_boundingRect;

    QTransform m_transform;

    bool m_isHighlighted;

private:			// static members

    static QFont s_font;

    static QColor s_color;

    static qreal s_labelDistance;
};

}				// namespace relarank

#endif // ZODIAC_PLUGLABEL_H
