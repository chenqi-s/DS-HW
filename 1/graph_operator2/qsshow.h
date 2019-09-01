#ifndef QSSHOW_H
#define QSSHOW_H

#include <QWidget>
#include<QPainter>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QString>
#include<QLabel>
#include<QPushButton>


class QSshow : public QScrollArea
{
    Q_OBJECT

public:
    explicit QSshow(QWidget *parent = 0);
    void add(QString);
    void deleteQueue();
    void deleteStack();

private:
    int tail;

    QLabel *label;
    QWidget *pWidget;
    QVBoxLayout *pHlayout;
friend class MainWindow;
};


#endif // QSSHOW_H
