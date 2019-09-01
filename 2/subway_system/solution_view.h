#ifndef SOLUTION_VIEW_H
#define SOLUTION_VIEW_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class solution_view:public QGraphicsView
{


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
};

#endif // SOLUTION_VIEW_H
