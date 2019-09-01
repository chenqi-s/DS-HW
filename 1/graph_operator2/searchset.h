#ifndef SEARCHSET_H
#define SEARCHSET_H

#include <QDialog>
#include <QComboBox>
#include "solver.h"


namespace Ui {
class Searchset;
}

class Searchset : public QDialog
{
    Q_OBJECT

public:
    explicit Searchset(int num,int T,QWidget *parent = 0);
    ~Searchset();
   // void output(int &R,int &Start);
public slots:
    //void setchoose();

public:
    Ui::Searchset *ui;
    int type;
    QComboBox *startNode;
    QComboBox *set;


};

#endif // SEARCHSET_H
