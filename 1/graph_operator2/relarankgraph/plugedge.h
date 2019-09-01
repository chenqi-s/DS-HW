#ifndef ZODIAC_PLUGEDGE_H
#define ZODIAC_PLUGEDGE_H

#include "bezieredge.h"

namespace relarank
{

class EdgeGroup;
class Scene;
class Plug;

class PlugEdge: public BezierEdge
{

    Q_OBJECT
public:		// methods

    explicit PlugEdge(Scene * scene, Plug * startPlug, Plug * endPlug,
                      EdgeGroup * edgeGroup);

    void plugHasChanged();

    inline Plug *getStartPlug() const
    {
        return m_startPlug;
    }

    inline Plug *getEndPlug() const
    {
        return m_endPlug;
    }

    inline EdgeGroup *getGroup() const
    {
        return m_group;
    }

    inline void updateLabelText()
    {
        setLabelText(getLabelText());
    }

    QString getLabelText();

    virtual void setLabelText(const QString & text);

protected:			// methods

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

private:			// members

    Plug * m_startPlug;

    Plug *m_endPlug;

    EdgeGroup *m_group;

    bool m_isBent;

};

}				// namespace relarank

#endif // ZODIAC_PLUGEDGE_H
