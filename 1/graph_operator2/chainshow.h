#ifndef CHAINSHOW_H
#define CHAINSHOW_H

#include <QGraphicsView>
#include "solver.h"

class Node;

//! [0]
class ChainShow : public QGraphicsView
{
    Q_OBJECT

public:
    ChainShow(QWidget *parent = 0);
    void setupModel(Solver * solver);
    void itemMoved();
public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    QGraphicsScene *myscene;
};
//! [0]


#endif // CHAINSHOW_H
