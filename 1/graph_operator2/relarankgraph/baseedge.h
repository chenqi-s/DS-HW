#ifndef RELARANK_BASEEDGE_H
#define RELARANK_BASEEDGE_H

#include <QGraphicsObject>
#include <QPen>
#include <QPropertyAnimation>

namespace relarank
{

class EdgeArrow;
class EdgeLabel;
class Scene;

class BaseEdge: public QGraphicsObject
{
    Q_OBJECT
    friend class EdgeArrow;

    Q_PROPERTY(qreal secondaryOpacity MEMBER m_secondaryOpacity WRITE updateSecondaryOpacity)
public:	// methods

    explicit BaseEdge(Scene *
                      scene);

    virtual ~ BaseEdge();

    virtual void setLabelText(const QString & text);

    void setVisible(bool visible);

    virtual void placeArrowAt(qreal fraction) = 0;

    virtual void updateStyle();

public:			// static methods

    static inline qreal getBaseWidth()
    {
        return s_width;
    }

    static inline void setBaseWidth(qreal width)
    {
        s_width = width;
        s_pen.setWidthF(s_width);
    }

    static inline QColor getBaseColor()
    {
        return s_color;
    }

    static inline void setBaseColor(const QColor & color)
    {
        s_color = color;
        s_pen.setColor(color);
    }

    static inline qreal getSecondaryFadeInDuration()
    {
        return s_secondaryFadeInDuration;
    }

    static inline void setSecondaryFadeInDuration(qreal duration)
    {
        s_secondaryFadeInDuration = duration;
    }

    static inline qreal getSecondaryFadeOutDuration()
    {
        return s_secondaryFadeOutDuration;
    }

    static inline void setSecondaryFadeOutDuration(qreal duration)
    {
        s_secondaryFadeOutDuration = duration;
    }

    static inline QEasingCurve getSecondaryFadeInCurve()
    {
        return s_secondaryFadeInCurve;
    }

    static inline void setSecondaryFadeInCurve(QEasingCurve curve)
    {
        s_secondaryFadeInCurve = curve;
    }

    static inline QEasingCurve getSecondaryFadeOutCurve()
    {
        return s_secondaryFadeOutCurve;
    }

    static inline void setSecondarylFadeOutCurve(QEasingCurve curve)
    {
        s_secondaryFadeOutCurve = curve;
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    void updateSecondaryOpacity(qreal opacity);

    virtual void updateShape() = 0;

protected:			// members

    Scene * m_scene;

    EdgeArrow *m_arrow;

    QPainterPath m_path;

    QPropertyAnimation m_secondaryFadeIn;

    QPropertyAnimation m_secondaryFadeOut;

    qreal m_secondaryOpacity;

protected:			// static members

    static qreal s_width;

    static QColor s_color;

    static qreal s_secondaryFadeInDuration;

    static qreal s_secondaryFadeOutDuration;

    static QEasingCurve s_secondaryFadeInCurve;

    static QEasingCurve s_secondaryFadeOutCurve;

    static QPen s_pen;

private:			// members

    EdgeLabel * m_label;

};

}				// namespace relarank

#endif // RELARANK_BASEEDGE_H
