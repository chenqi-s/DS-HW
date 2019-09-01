#ifndef ZODIAC_EDGEGROUPPAIR_H
#define ZODIAC_EDGEGROUPPAIR_H

#include "edgegroupinterface.h"

namespace relarank
{

class StraightDoubleEdge;
class EdgeGroup;
class Node;
class Scene;

class EdgeGroupPair: public EdgeGroupInterface
{

public:			// methods

    explicit EdgeGroupPair(Scene * scene, Node * nodeA, Node * nodeB);

    virtual ~ EdgeGroupPair();

    inline EdgeGroup *getFirstGroup() const
    {
        return m_firstGroup;
    }

    inline EdgeGroup *getSecondGroup() const
    {
        return m_secondGroup;
    }

    bool isEmpty() const;

    void updateDoubleEdgeVisibility();

    void hideDoubleEdge();

    void updateLabel();

    QString getLabelText();

    void updateStyle();

private:			// members

    Scene * m_scene;

    EdgeGroup *m_firstGroup;

    EdgeGroup *m_secondGroup;

    StraightDoubleEdge *m_edge;
};

}				// namespace relarank

#endif				// ZODIAC_EDGEGROUPPAIR_H
