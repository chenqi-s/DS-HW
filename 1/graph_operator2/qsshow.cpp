#include "qsshow.h"

#include<QHBoxLayout>
#include<QPainter>
#include<QScrollArea>
#include <QDebug>
#include <QScrollBar>
QSshow::QSshow(QWidget *parent) :
    QScrollArea(parent)
{
    // setup the scroll area
    setFrameShape(QFrame::Box);
    setWidgetResizable(true);
    // set up the view widget

    // ... and the layout of the view widget
    pWidget = new QWidget(this);

    setWidget(pWidget);
    pWidget->setStyleSheet("QWidget{background:white;}QWidget:hover{background:#00ff00;}");
    pHlayout = new QVBoxLayout();
    pHlayout->addSpacerItem(new QSpacerItem(2, 2, QSizePolicy::Expanding, QSizePolicy::Expanding));
    pHlayout->setSpacing(1);
    pHlayout->setMargin(1);
    pWidget->setLayout(pHlayout);
    tail=0;
}




void QSshow::add(QString s)
{
    label= new QLabel();
    label->setFrameShape (QFrame::Box);
    label->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);");
    QPalette pa;
    label->setAutoFillBackground(true);
    pa.setColor(QPalette::Background,Qt::red);
    label->setPalette(pa);
    QFont ft;
    ft.setPointSize(14);
    label->setFont(ft);
    label->setText(s);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(20,20,50,50);
    pHlayout->insertWidget(pHlayout->count()-1, label);
    ++tail;
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
}

void QSshow::deleteQueue()
{

    QLayoutItem *pLayoutItem = (QLayoutItem *)pHlayout->itemAt(0);
    //pLayoutItem->widget()->setParent(NULL);
    //mylabel->first()->setParent(NULL);
    //pHlayout->removeWidget(pLayoutItem->widget());
    //pHlayout->removeWidget(mylabel->first());
    if(pLayoutItem->widget())
    {
        delete pLayoutItem->widget();
        --tail;
    }
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->minimum());
    //qDebug()<<pHlayout->count();
    //delete pLayoutItem;
}


void QSshow::deleteStack()
{
    if(tail>=0)
    {
        QLayoutItem *pLayoutItem = (QLayoutItem *)pHlayout->itemAt(tail-1);
        //pHlayout->removeWidget(pLayoutItem->widget());
        //pLayoutItem->widget()->setParent(0);
        if(pLayoutItem->widget())
        {
            delete pLayoutItem->widget();
            --tail;
        }

    }
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
    //qDebug()<<pHlayout->count();
    //delete pLayoutItem;
}
