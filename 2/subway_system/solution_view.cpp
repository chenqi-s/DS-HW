#include "solution_view.h"

void solution_view::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
      if (!event->isAccepted()) {
          if (event->button() == Qt::LeftButton)
          {

          }
      }
}

void solution_view::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    QGraphicsScene::wheelEvent(event);

}
