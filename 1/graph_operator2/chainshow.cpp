
#include "chainshow.h"
#include "chainedge.h"
#include "chainnode.h"

#include <math.h>
#include <QKeyEvent>

//! [0]
ChainShow::ChainShow(QWidget *parent)
    : QGraphicsView(parent), timerId(0)
{
    myscene = new QGraphicsScene(this);
    myscene->setItemIndexMethod(QGraphicsScene::NoIndex);
    myscene->setSceneRect(-400, -400, 800, 800);
    setScene(myscene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(800, 800);
    setWindowTitle(tr("Chain of Graph"));
    scaleView(qreal(1.2));
}
//! [1]


void ChainShow::setupModel(Solver *solver)
{
    if(solver==NULL)return;


    for(int i=0;i<solver->size_node;++i)
    {
        QColor nodecolor=i%5==0? QColor(qRgb(50, 147, 22)):
                         i%5==1? QColor(qRgb(236, 191, 49)):
                         i%5==2? QColor(qRgb(243, 61, 34)):
                         i%5==3? QColor(qRgb(135, 81, 60)):
                         i%5==4? QColor(qRgb(121, 75, 255)):QColor(qRgb(164, 255, 244));
        Node *start=new Node(this);
        myscene->addItem(start);
        start->setpostion(-280,-200+80*i);               //optim
        start->set(QStaticText(QString::number(i+1)),nodecolor);
        for(int j=0;j<solver->size_node;++j)
        {
            if(solver->matrix[i][j] > 0 )
            {
                Node *tail=new Node(this);
                myscene->addItem(tail);
                tail->setpostion(-200+j*80,-200+80*i);               //optim
                tail->set(QStaticText(QString::number(j+1)),nodecolor);

                myscene->addItem(new Edge(start, tail,QString::number(solver->matrix[i][j])));        // todo
                start=tail;
            }
        }

    }

}

//! [2]
void ChainShow::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}
//! [2]

//! [3]
void ChainShow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
//! [3]

//! [4]
void ChainShow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QList<Node *> nodes;
    foreach (QGraphicsItem *item, scene()->items()) {
        if (Node *node = qgraphicsitem_cast<Node *>(item))
            nodes << node;
    }

    foreach (Node *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (Node *node, nodes) {
        if (node->advance())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}
//! [4]

#ifndef QT_NO_WHEELEVENT
//! [5]
void ChainShow::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
//! [5]
#endif

//! [6]
void ChainShow::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}
//! [6]

//! [7]
void ChainShow::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
//! [7]

void ChainShow::shuffle()
{
    foreach (QGraphicsItem *item, scene()->items()) {
        if (qgraphicsitem_cast<Node *>(item))
            item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
    }
}

void ChainShow::zoomIn()
{
    scaleView(qreal(1.2));
}

void ChainShow::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
