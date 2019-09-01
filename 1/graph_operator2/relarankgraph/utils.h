#ifndef ZODIAC_NODEUTILS_H
#define ZODIAC_NODEUTILS_H

#include <QRectF>

namespace relarank
{

enum zStack {
    EDGE            = -10,  // Edges are all the way in the background.
    NODE_CLOSED     = 0,    // A closed Node is the base line depth at zero.
    NODE_EXPANDED   = 10,   // An expanded Node automatically overlays a closed one.
    NODE_ACTIVE     = 20,   // The active Node (the last selected one) overlays other expanded Nodes.
    EDGE_LABEL      = 30,   // EdgeLabel%s overlay all Node%s.
    DRAW_EDGE       = 40    // The DrawEdge is drawn in front of overthing.

};

}				// namespace relarank

inline QRectF
quadrat(qreal sidelength)
{
    return QRectF(-sidelength, -sidelength, sidelength * 2, sidelength * 2);
}

#endif // ZODIAC_NODEUTILS_H
