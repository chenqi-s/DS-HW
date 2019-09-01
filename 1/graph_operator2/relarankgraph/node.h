#ifndef ZODIAC_NODE_H
#define ZODIAC_NODE_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QSet>
#include <QUuid>

namespace relarank
{

class NodeLabel;
class Perimeter;
class Plug;
class StraightEdge;
class Scene;
enum class PlugDirection;

enum class NodeExpansion {
    NONE    = 0, // No expansion.
    IN      = 1, // Incoming Plug%s are expanded.
    OUT     = 2, // Outgoing Plug%s are expanded.
    BOTH    = 3  // Both types of Plug are expanded.
};

class Node: public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(qreal outgoingSpread MEMBER m_outgoingExpansionFactor WRITE updateOutgoingSpread)
    Q_PROPERTY(qreal incomingSpread MEMBER m_incomingExpansionFactor WRITE updateIncomingSpread)
public:	// methods

    explicit Node(Scene * scene, const QString & displayName,
                  const QUuid & uuid = QUuid());

    const QUuid & getUniqueId() const
    {
        return m_uniqueId;
    }

    Plug *createPlug(const QString & name, PlugDirection direction);

    bool removePlug(Plug * plug);

    inline void addStraightEdge(StraightEdge * edge)
    {
        m_straightEdges.insert(edge);
    }

    inline void removeStraightEdge(StraightEdge * edge)
    {
        Q_ASSERT(m_straightEdges.contains(edge));
        m_straightEdges.remove(edge);
    }

    Plug *getClosestPlugTo(const QPointF & pos, PlugDirection direction);

    qreal getPerimeterRadius() const;

    inline Scene *getScene()
    {
        return m_scene;
    }

    inline QString getDisplayName() const
    {
        return m_displayName;
    }

    void setDisplayName(const QString & displayName);

    QString renamePlug(Plug * plug, const QString & newName);

    bool togglePlugDirection(Plug * plug);

    QList < Plug * >getPlugs()const
    {
        return m_allPlugs.values();
    }

    Plug *getPlug(const QString & name) const
    {
        return m_allPlugs.value(name, nullptr);
    }

    inline qreal getIncomingExpansionFactor() const
    {
        return m_incomingExpansionFactor;
    }

    inline qreal getOutgoingExpansionFactor() const
    {
        return m_outgoingExpansionFactor;
    }

    inline bool isRemovable() const
    {
        return m_straightEdges.size() == 0;
    }

    inline NodeExpansion getExpansionState() const
    {
        return m_expansionState;
    }

    inline void softSetExpansion(NodeExpansion newState)
    {
        if (m_expansionState != NodeExpansion::BOTH) {
            setExpansion(newState);
        }
    }

    inline void softResetExpansion()
    {
        if (m_expansionState != NodeExpansion::BOTH) {
            setExpansion(m_lastExpansionState);
        }
    }

    inline void forceCollapse()
    {
        if (m_expansionState == NodeExpansion::BOTH) {
            setExpansion(NodeExpansion::NONE);
            m_lastExpansionState = NodeExpansion::NONE;
        }
    }

    inline void toggleExpansion()
    {
        if (m_expansionState == NodeExpansion::IN) {
            setExpansion(NodeExpansion::OUT);
        } else if (m_expansionState == NodeExpansion::OUT) {
            setExpansion(NodeExpansion::IN);
        }
    }

    inline void toggleForcedExpansion()
    {
        if (m_expansionState == NodeExpansion::BOTH) {
            resetExpansion();
        } else {
            setExpansion(NodeExpansion::BOTH);
        }
    }

    void updateStyle();

signals:

    void nodeActivated();

    void nodeRenamed(const QString & name);

    void removalRequested();

    void inputConnected(Plug * myInput, Plug * otherOutput);

    void outputConnected(Plug * myOutput, Plug * otherInput);

    void inputDisconnected(Plug * myInput, Plug * otherOutput);

    void outputDisconnected(Plug * myOutput, Plug * otherInput);

public:			// static methods

    static inline qreal getCoreRadius()
    {
        return s_coreRadius;
    }

    static inline void setCoreRadius(qreal radius)
    {
        s_coreRadius = qMax(0., radius);
    }

    static inline const QColor & getIdleColor()
    {
        return s_idleColor;
    }

    static inline void setIdleColor(const QColor & color)
    {
        s_idleColor = color;
    }

    static inline const QColor & getSelectedColor()
    {
        return s_selectedColor;
    }

    static inline void setSelectedColor(const QColor & color)
    {
        s_selectedColor = color;
    }

    static inline const QColor & getOutlineColor()
    {
        return s_outlineColor;
    }

    static inline void setOutlineColor(const QColor & color)
    {
        s_outlineColor = color;
        updateOutlinePen();
    }

    static inline qreal getOutlineWidth()
    {
        return s_outlineWidth;
    }

    static inline void setOutlineWidth(qreal width)
    {
        s_outlineWidth = qMax(0., width);
        updateOutlinePen();
    }

    static inline const QString & getPlugSuffix()
    {
        return s_plugSuffix;
    }

    static inline void setPlugSuffix(const QString & suffix)
    {
        s_plugSuffix = suffix;
    }

    static inline qreal getPlugSweep()
    {
        return s_plugSweep;
    }

    static inline void setPlugSweep(qreal plugSweep)
    {
        s_plugSweep = qMax(0., plugSweep);
    }

    static inline qreal getGapSweep()
    {
        return s_plugGap;
    }

    static inline void setGapSweep(qreal gapSize)
    {
        s_plugGap = qMax(0., gapSize);
    }

    static inline int getExpandDuration()
    {
        return s_expandDuration;
    }

    static inline void setExpandDuration(int duration)
    {
        s_expandDuration = duration;
    }

    static inline int getCollapseDuration()
    {
        return s_collapseDuration;
    }

    static inline void setCollapseDuration(int duration)
    {
        s_collapseDuration = duration;
    }

    static inline QEasingCurve getExpandCurve()
    {
        return s_expandCurve;
    }

    static inline void setExpandCurve(QEasingCurve curve)
    {
        s_expandCurve = curve;
    }

    static inline QEasingCurve getCollapseCurve()
    {
        return s_collapseCurve;
    }

    static inline void setCollapseCurve(QEasingCurve curve)
    {
        s_collapseCurve = curve;
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

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

    void keyPressEvent(QKeyEvent * event);

private:			// methods

    QString getUniquePlugName(const QString & name, const Plug * plug =
                                  nullptr);

private slots:
    void hasCompletelyCollapsed();

    void aboutToExpandAfresh();

private:			// methods

    void setExpansion(NodeExpansion newState);

    inline void resetExpansion()
    {
        setExpansion(m_lastExpansionState);
    }

    void updateConnectedEdges();

    void updateIncomingSpread(qreal expansion);

    void updateOutgoingSpread(qreal expansion);

    void arrangePlugs();

    qreal getPlugAngle() const;

    qreal getGapAngle() const;

    qreal getDeadZoneAngle() const;

    void adjustRadius();

private:			// static methods

    static void updateOutlinePen();

private:			// members

    Scene * m_scene;

    QString m_displayName;

    QUuid m_uniqueId;

    QPropertyAnimation m_outgoingExpandAnimation;

    QPropertyAnimation m_outgoingCollapseAnimation;

    QPropertyAnimation m_incomingExpandAnimation;

    QPropertyAnimation m_incomingCollapseAnimation;

    qreal m_outgoingExpansionFactor;

    qreal m_incomingExpansionFactor;

    Perimeter *m_perimeter;

    QMap < QString, Plug * >m_allPlugs;

    QSet < Plug * >m_outgoingPlugs;

    QSet < Plug * >m_incomingPlugs;

    QSet < StraightEdge * >m_straightEdges;

    NodeLabel *m_label;

    QRectF m_boundingRect;

    NodeExpansion m_expansionState;

    NodeExpansion m_lastExpansionState;

private:			// static members

    static qreal s_coreRadius;

    static QColor s_idleColor;

    static QColor s_selectedColor;

    static QColor s_outlineColor;

    static qreal s_outlineWidth;

    static QString s_plugSuffix;

    static qreal s_plugSweep;

    static qreal s_plugGap;

    static int s_expandDuration;

    static int s_collapseDuration;

    static QEasingCurve s_expandCurve;

    static QEasingCurve s_collapseCurve;

    static QPen s_linePen;

    static bool s_mouseWasDragged;

};

}				// namespace relarank

#endif // ZODIAC_NODE_H
