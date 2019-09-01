#ifndef ZODIAC_PLUG_H
#define ZODIAC_PLUG_H

#include <QGraphicsObject>
#include <QSet>
#include <QVector2D>

namespace relarank
{

class Node;
class Scene;
class Perimeter;
class PlugEdge;
class PlugLabel;

enum class PlugDirection {
    IN      = 0, // INcoming Plug%s only accept incoming PlugEdge%s.
    OUT     = 1, // OUTcoming Plug%s only accept outoing PlugEdge%s.
    BOTH    = 2, // Plug%s cannot work in BOTH directions, but BOTH can be used as an argument.
};

class Plug: public QGraphicsObject
{

    Q_OBJECT
    friend class Node;

public:			// methods

    explicit Plug(Node * parent, const QString & name,
                  PlugDirection direction);

    void addEdge(PlugEdge * edge);

    void removeEdge(PlugEdge * edge);

    QList < Plug * >getConnectedPlugs() const
    {
        return m_connectedPlugs.toList();
    }

    void defineShape(QVector2D normal, qreal arclength);

    void updateEdges() const;

    void updateExpansion(qreal expansion);

    void setHighlight(bool highlight);

    inline QVector2D getNormal() const
    {
        return m_normal;
    }

    inline QString getName() const
    {
        return m_name;
    }

    inline Node *getNode() const
    {
        return m_node;
    }

    inline PlugDirection getDirection() const
    {
        return m_direction;
    }

    QVector2D getTargetNormal() const;

    inline int getEdgeCount() const
    {
        return m_edges.size();
    }

    inline bool isRemovable() const
    {
        return getEdgeCount() == 0;
    }

    inline bool isConnectedWith(Plug * plug) const
    {
        return m_connectedPlugs.contains(plug);
    }

    void aquireDrawEdge();

    void advanceDrawEdge(const QPointF & scenePos);

    void releaseDrawEdge();

    void updateEdgeLabels();

    void updateStyle();

    qreal getArrangementPriority();

signals:
    void plugRenamed(const QString & name);

public:			// static methods

    static inline qreal getWidth()
    {
        return s_width;
    }

    static inline void setWidth(qreal width)
    {
        s_width = width;
    }

    static inline QColor getInColor()
    {
        return s_inColor;
    }

    static inline void setInColor(QColor color)
    {
        s_inColor = color;
    }

    static inline QColor getOutColor()
    {
        return s_outColor;
    }

    static inline void setOutColor(QColor color)
    {
        s_outColor = color;
    }

    static inline QColor getHighlightColor()
    {
        return s_highlightColor;
    }

    static inline void setHighlightColor(QColor color)
    {
        s_highlightColor = color;
    }

    static inline bool getToggleExpansionOnEdgeCreation()
    {
        return s_toggleNodeExpansionOnEdgeCreation;
    }

    static inline void setToggleExpansionOnEdgeCreation(bool activate)
    {
        s_toggleNodeExpansionOnEdgeCreation = activate;
    }

    static inline Qt::MouseButton getDrawEdgeButton()
    {
        return s_drawEdgeButton;
    }

    static inline void setDrawEdgeButton(Qt::MouseButton button)
    {
        s_drawEdgeButton = button;
    }

    static inline Node *getDragTargetNode()
    {
        return s_dragTargetNode;
    }

    static inline void clearDragTargetNode()
    {
        s_dragTargetNode = nullptr;
    }

    static inline Plug *getDragTargetPlug()
    {
        return s_dragTargetPlug;
    }

    static inline void clearDragTargetPlug()
    {
        s_dragTargetPlug = nullptr;
    }

protected:			// methods

    QRectF boundingRect()const;

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    QPainterPath shape() const;

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

private:			// methods for friends

    inline void setDirection(PlugDirection direction)
    {
        Q_ASSERT(getEdgeCount() == 0);
        m_direction = direction;
    }

    void setName(const QString & name);

private:			// methods

    void updateShape();

    bool mayReceiveInput();

private:			// members

    QString m_name;

    PlugDirection m_direction;

    Node *m_node;

    qreal m_arclength;

    QVector2D m_normal;

    QPainterPath m_shape;

    bool m_isHighlighted;

    QSet < PlugEdge * >m_edges;

    PlugLabel *m_label;

    QSet < Plug * >m_connectedPlugs;

private:			// static members

    static qreal s_width;

    static QColor s_inColor;

    static QColor s_outColor;

    static QColor s_highlightColor;

    static bool s_toggleNodeExpansionOnEdgeCreation;

    static Qt::MouseButton s_drawEdgeButton;

    static Node *s_dragTargetNode;

    static Plug *s_dragTargetPlug;

    static Plug *s_edgeDrawingPlug;

};

}				// namespace relarank

#endif // ZODIAC_PLUG_H
