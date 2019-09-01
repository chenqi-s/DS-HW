#ifndef ZODIAC_VIEW_H
#define ZODIAC_VIEW_H

#include <QGraphicsView>

class QEvent;
class QGestureEvent;
class QMouseEvent;
class QWheelEvent;

namespace relarank
{

class Scene;

class View: public QGraphicsView
{
    Q_OBJECT
public:		// methods

    explicit View(QWidget * parent);

    void setScene(Scene * scene);

    void updateStyle();

public:			// static methods

    inline static QColor getBackgroundColor()
    {
        return s_backgroundColor;
    }

    inline static void setBackgroundColor(const QColor & color)
    {
        s_backgroundColor = color;
    }

    inline static qreal getZoomSpeed()
    {
        return s_zoomSpeed;
    }

    inline static void setZoomSpeed(qreal speed)
    {
        s_zoomSpeed = speed;
    }

    inline static Qt::MouseButton getMoveButton()
    {
        return s_dragMoveButton;
    }

    inline static void setMoveButton(Qt::MouseButton button)
    {
        s_dragMoveButton = button;
    }

    inline static Qt::MouseButton getSelectionButton()
    {
        return s_selectionButton;
    }

    inline static void setSelectionButton(Qt::MouseButton button)
    {
        s_selectionButton = button;
    }

    static inline Qt::MouseButton getRemovalButton()
    {
        return s_removalButton;
    }

    static inline void setRemovalButton(Qt::MouseButton button)
    {
        s_removalButton = button;
    }

    static inline int getActivationKey()
    {
        return s_activationKey;
    }

    static inline void setActivationKey(int key)
    {
        s_activationKey = key;
    }

protected:			// methods

    bool event(QEvent * event);

    bool gestureEvent(QGestureEvent * event);

    bool viewportEvent(QEvent * event);

    void mousePressEvent(QMouseEvent * event);

    void mouseReleaseEvent(QMouseEvent * event);

    void mouseDoubleClickEvent(QMouseEvent * event);

    void wheelEvent(QWheelEvent * event);

    void paintEvent(QPaintEvent * event);

private:			// members

    qreal m_zoomFactor;

private:			// static members

    static QColor s_backgroundColor;

    static qreal s_zoomSpeed;

    static Qt::MouseButton s_dragMoveButton;

    static Qt::MouseButton s_selectionButton;

    static Qt::MouseButton s_removalButton;

    static int s_activationKey;

    static qreal s_minZoomFactor;

    static qreal s_maxZoomFactor;

};

}				// namespace relarank

#endif // ZODIAC_VIEW_H
