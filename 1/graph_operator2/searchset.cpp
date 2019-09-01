#include "searchset.h"
#include "ui_searchset.h"
#include <QLayout>
#include <QLabel>
#include <QPushButton>
Searchset::Searchset(int num,int T,QWidget *parent) :
    QDialog(parent),
    type(T),
    ui(new Ui::Searchset)
{
    ui->setupUi(this);
    if(T==0)
    {
        this->setWindowTitle(tr("DFS set"));
        this->resize(300,180);
        QLabel *styletitle=new QLabel("Choose DFS method:");
        set = new QComboBox;
        set->addItem(tr("No Recursion"),0);
        set->addItem(tr("Recursion"),1);
        QLabel *nodetitle=new QLabel("Start Node:");
        startNode = new QComboBox;
        for(int i=0;i<num;++i)
            startNode->addItem(QString::number(i+1),i);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(styletitle);
        mainLayout->addWidget(set);
        mainLayout->addWidget(nodetitle);
        mainLayout->addWidget(startNode);
        mainLayout->addWidget(ui->buttonBox);
        setLayout(mainLayout);

    }
    else if(T==1)
    {
        this->setWindowTitle(tr("BFS set"));
        this->resize(300,100);
        QLabel *nodetitle=new QLabel("Start Node:");
        startNode = new QComboBox;
        for(int i=0;i<num;++i)
            startNode->addItem(QString::number(i+1),i);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(nodetitle);
        mainLayout->addWidget(startNode);
        mainLayout->addWidget(ui->buttonBox);
        setLayout(mainLayout);
    }



}




Searchset::~Searchset()
{
    delete ui;
    delete startNode;

}



//void Searchset::setchoose()
//{
//    if(type==0)
//    {
//        R=set->currentData().toInt();
//        start=startNode->currentData().toInt();
//    }
//    else if(type==1)
//    {
//        start=startNode->currentData().toInt();
//    }
//}


//void Searchset::output(int &R, int &Start)
//{
//    R=this->R;
//    Start=this->start;
//}
