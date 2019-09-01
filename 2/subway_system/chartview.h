
#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtWidgets/QWidget>
#include <QtCharts/QPieSeries>
#include <QVector>
#include <QtCharts/QChartView>
QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ChartView : public QWidget
{
    Q_OBJECT

public:
    ChartView(QWidget *parent ,QVector<int> kind1, QVector<int> kind2, QVector<int> kind3,QVector<int> max);
    ~ChartView();
    void set(QVector<int> kind1,QVector<int> kind2,QVector<int> kind3,QVector<int> max);
public slots:

    void explodeSlice(bool exploded);

private:
    QList<QPieSeries *> m_donuts;
    QTimer *updateTimer;
    QChartView *chartView;
};


#endif
