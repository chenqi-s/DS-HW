#ifndef ZODIAC_BEZIEREDGE_H
#define ZODIAC_BEZIEREDGE_H

#include "baseedge.h"

namespace relarank
{

class Plug;
class Scene;

class BezierEdge: public BaseEdge
{
    Q_OBJECT
public:		// methods

    void placeArrowAt(qreal fraction) override;

public:			// static methods

    static inline qreal getMaxCtrlDistance()
    {
        return s_maxCtrlDistance;
    }

    static inline void setMaxCtrlDistance(qreal distance)
    {
        s_maxCtrlDistance = qMax(0., distance);
    }

    static inline qreal getCtrlExpansionFactor()
    {
        return s_ctrlExpansionFactor;
    }

    static inline void setCtrlExpansionFactor(qreal factor)
    {
        s_ctrlExpansionFactor = factor;
    }

protected:			// methods

    explicit BezierEdge(Scene * scene);

    virtual void updateShape() override;

    QPointF getCtrlPointFor(Plug * plug);

protected:			// members

    QPointF m_startPoint;

    QPointF m_ctrlPoint1;

    QPointF m_ctrlPoint2;

    QPointF m_endPoint;

private:			// static members

    static qreal s_maxCtrlDistance;

    static qreal s_ctrlExpansionFactor;
};

}				// namespace relarank

#endif // ZODIAC_BEZIEREDGE_H
