#ifndef ZODIAC_STRAIGHTDOUBLEEDGE_H
#define ZODIAC_STRAIGHTDOUBLEEDGE_H

#include "straightedge.h"

namespace relarank
{

class Node;
class Scene;
class EdgeGroupInterface;

class StraightDoubleEdge: public StraightEdge
{
    Q_OBJECT
public:		// methods

    explicit StraightDoubleEdge(Scene * scene, EdgeGroupInterface * group,
                                Node * fromNode, Node * toNode);

    void updateLabel();

protected:			// methods

    virtual void updateShape() override;
};

}				// namespace relarank

#endif				// ZODIAC_STRAIGHTDOUBLEEDGE_H
