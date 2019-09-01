#ifndef ZODIAC_DRAWEDGE_H
#define ZODIAC_DRAWEDGE_H

#include "bezieredge.h"

namespace relarank
{

class Scene;

class DrawEdge: public BezierEdge
{

    Q_OBJECT
public:

    explicit DrawEdge(Scene * scene);

    inline void setReverse(bool isReverse)
    {
        m_isReverse = isReverse;
    }

    inline bool isReversed() const
    {
        return m_isReverse;
    }

public:			// methods

    void fromPlugToPoint(Plug * plug, const QPointF & endPoint);

private:			// members

    bool m_isReverse;

};

}				// namespace relarank

#endif // ZODIAC_DRAWEDGE_H
