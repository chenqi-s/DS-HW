#ifndef ZODIAC_EDGELABEL_H
#define ZODIAC_EDGELABEL_H

#include <QFont>
#include <QGraphicsSimpleTextItem>

namespace relarank
{

class EdgeLabel: public QGraphicsSimpleTextItem
{

public:			// methods

    explicit EdgeLabel();

    void setPos(qreal x, qreal y);

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

    static inline qreal getTransparency()
    {
        return s_color.alphaF();
    }

    static inline void setTransparency(qreal alpha)
    {
        s_color.setAlphaF(alpha);
    }

    static inline qreal getVerticalOffset()
    {
        return s_verticalOffset;
    }

    static inline void setVerticalOffset(qreal offset)
    {
        s_verticalOffset = offset;
    }

private:			// static members

    static QFont s_font;

    static QColor s_color;

    static qreal s_verticalOffset;

};

}				// namespace relarank

#endif // ZODIAC_EDGELABEL_H
