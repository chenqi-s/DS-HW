#include "chartview.h"

#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QTime>
#include <QtWidgets/QGridLayout>
#include <QtCore/QTimer>

QT_CHARTS_USE_NAMESPACE

ChartView::ChartView(QWidget *parent,QVector<int> kind1, QVector<int> kind2, QVector<int> kind3,QVector<int> max)
    : QWidget(parent)
{
    setMinimumSize(800, 600);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    chartView = new QChartView;
    chartView->setRenderHint(QPainter::Antialiasing);
    QChart *chart = chartView->chart();
    chart->legend()->setVisible(false);
    chart->setTitle("Diff Method Comapre");
    chart->setAnimationOptions(QChart::AllAnimations);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartView, 1, 1);
    setLayout(mainLayout);

    updateTimer = new QTimer(this);
    updateTimer->start(1250);

    set(kind1,kind2,kind3,max);
}



void ChartView::set(QVector<int> kind1, QVector<int> kind2, QVector<int> kind3,QVector<int> max)
{
    qreal minSize = 0.1;
    qreal maxSize = 0.9;
    qreal step= (maxSize - minSize) / 4.0;
    int sliceCount =  6;
    QPieSeries *donut1 = new QPieSeries;
    qreal value;
    for (int j = 0; j < sliceCount; j++)
    {
        QPieSlice *slice = new QPieSlice();
        if(j%2==0)
        {
             slice->setLabel(QString("%1").arg(kind1[j/2]));
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::white);
            value= double(kind1[j/2])/max[j/2];
            slice->setLabelPosition(QPieSlice::LabelInsideTangential);
        }
        else
        {
            slice->setColor(Qt::gray);
            slice->setLabelVisible(false);
            slice->setLabelColor(Qt::white);
            value = 1.-value;
        }

        slice->setValue(value);
        connect(slice, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
        donut1->append(slice);

    }


    QPieSeries *donut2 = new QPieSeries;
    for (int j = 0; j < sliceCount; j++)
    {
        QPieSlice *slice = new QPieSlice();
        slice->setLabel(QString("%1").arg(kind2[j/2]));
        if(j%2==0)
        {
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::white);
            value= double(kind2[j/2])/max[j/2];
            slice->setLabelPosition(QPieSlice::LabelInsideTangential);
        }
        else
        {
            slice->setColor(Qt::gray);
            slice->setLabelVisible(false);
            slice->setLabelColor(Qt::white);
            value = 1.-value;
        }

        slice->setValue(value);
        connect(slice, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
        donut2->append(slice);

    }


    QPieSeries *donut3 = new QPieSeries;
    for (int j = 0; j < sliceCount; j++)
    {
        QPieSlice *slice = new QPieSlice();
        slice->setLabel(QString("%1").arg(kind3[j/2]));
        if(j%2==0)
        {
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::white);
            value= double(kind3[j/2])/max[j/2];
            slice->setLabelPosition(QPieSlice::LabelInsideTangential);
        }
        else
        {
            slice->setColor(Qt::gray);
            slice->setLabelVisible(false);
            slice->setLabelColor(Qt::white);
            value = 1.-value;
        }

        slice->setValue(value);
        connect(slice, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
        donut3->append(slice);

    }

    QPieSeries *donut4 = new QPieSeries;
    QPieSlice *slice1 = new QPieSlice();
    slice1->setLabel(QString("Distance"));
    slice1->setLabelVisible(true);
    slice1->setLabelColor(Qt::white);
    slice1->setLabelPosition(QPieSlice::LabelInsideTangential);
    slice1->setValue(1);
   // connect(slice1, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
    donut4->append(slice1);

    QPieSlice *slice2 = new QPieSlice();
    slice2->setLabel(QString("Station"));
    slice2->setLabelVisible(true);
    slice2->setLabelColor(Qt::white);
    slice2->setLabelPosition(QPieSlice::LabelInsideTangential);
    slice2->setValue(1);
    //connect(slice2, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
    donut4->append(slice2);

    QPieSlice *slice3 = new QPieSlice();
    slice3->setLabel(QString("Transfer"));
    slice3->setLabelVisible(true);
    slice3->setLabelColor(Qt::white);
    slice3->setLabelPosition(QPieSlice::LabelInsideTangential);
    slice3->setValue(1);
    //connect(slice3, SIGNAL(hovered(bool)), this, SLOT(explodeSlice(bool)));
    donut4->append(slice3);


    donut4->setHoleSize(minSize );
    donut4->setPieSize(minSize + step);
    donut1->setHoleSize(minSize +  step);
    donut1->setPieSize(minSize + 2. * step);
    donut2->setHoleSize(minSize + 2. * step);
    donut2->setPieSize(minSize + 3. * step);
    donut3->setHoleSize(minSize +3.*step );
    donut3->setPieSize(minSize +4.*step);


    m_donuts.append(donut4);
    chartView->chart()->addSeries(donut4);

    m_donuts.append(donut1);
    chartView->chart()->addSeries(donut1);

    m_donuts.append(donut2);
    chartView->chart()->addSeries(donut2);

    m_donuts.append(donut3);
    chartView->chart()->addSeries(donut3);
}

ChartView::~ChartView()
{

}


void ChartView::explodeSlice(bool exploded)
{
    QPieSlice *slice = qobject_cast<QPieSlice *>(sender());
    if (exploded) {
        updateTimer->stop();
        qreal sliceStartAngle = slice->startAngle();
        qreal sliceEndAngle = slice->startAngle() + slice->angleSpan();

        QPieSeries *donut = slice->series();
        qreal seriesIndex = m_donuts.indexOf(donut);
        for (int i = seriesIndex + 1; i < m_donuts.count(); i++) {
            m_donuts.at(i)->setPieStartAngle(sliceEndAngle);
            m_donuts.at(i)->setPieEndAngle(360 + sliceStartAngle);
        }
    } else {
        for (int i = 0; i < m_donuts.count(); i++) {
            m_donuts.at(i)->setPieStartAngle(0);
            m_donuts.at(i)->setPieEndAngle(360);
        }
        updateTimer->start();
    }
    slice->setExploded(exploded);
}

