#ifndef MATRIXSHOW_H
#define MATRIXSHOW_H


#include "graphdatagenerator.h"
#include "solver.h"
#include <QDialog>
#include <QLabel>

class MainWindow;


class Matrixshow : public QDialog
{
    Q_OBJECT

public:
    explicit Matrixshow(QWidget *parent = 0);
    ~Matrixshow();

protected:
    Q3DBars *graph;
    QWidget *container;
    GraphDataGenerator *generator;
    QVBoxLayout *layout;
    QTableWidget *tableWidget;
    QLabel *help;
    int chartype;

    friend class MainWindow;

};

#endif // MATRIXSHOW_H






