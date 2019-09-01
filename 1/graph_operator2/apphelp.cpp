#include "apphelp.h"
#include <QIcon>

#include <QDesktopWidget>
#include <QRect>
#include <QPoint>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QDir>

//构造函数
AppHelp::AppHelp(QWidget *parent):QWidget(parent)
{
    createHelpUI();

    setWindowTitle(tr("使用帮助"));
    setWindowIcon(QIcon(":/icon/help.png"));
    setMinimumSize(600,400);

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    center.setX(center.x() - this->width()/2);
    center.setY(center.y() - this->height()/2);
    move(center);

    connect(listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(listWidgetChanged(QListWidgetItem*)));
}

//创建UI
void AppHelp::createHelpUI()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    setLayout(mainLayout);

    listWidget = new QListWidget;
    listWidget->addItem(tr("Load"));
    listWidget->addItem(tr("Show"));
    listWidget->addItem(tr("Algorithm"));
    listWidget->addItem(tr("Display"));
    listWidget->addItem(tr("Save"));
    listWidget->setFixedWidth(100);
    mainLayout->addWidget(listWidget);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    textBrowser = new QTextBrowser;
    textBrowser->setFont(QFont("consolas"));
    textBrowser->setOpenExternalLinks(true);
    textBrowser->setOpenLinks(true);
    rightLayout->addWidget(textBrowser);

    mainLayout->addLayout(rightLayout);
    listWidget->setCurrentItem(listWidget->item(0));
    listWidgetChanged(listWidget->item(0));
}

//当前列表项变化
void AppHelp::listWidgetChanged(QListWidgetItem* item) {
    if (listWidget->item(0) == item) {
        QFile txtFile(":/html/helpLoad.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(1)==item)
    {
        QFile txtFile(":/html/helpShow.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(2)==item)
    {
        QFile txtFile(":/html/helpAlgorithm.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(3)==item)
    {
        QFile txtFile(":/html/helpPlay.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
    else if(listWidget->item(4)==item)
    {
        QFile txtFile(":/html/helpSave.html");
        txtFile.open(QIODevice::ReadOnly);
        textBrowser->setHtml(txtFile.readAll());
        txtFile.close();
    }
}
