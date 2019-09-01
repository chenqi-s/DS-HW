#include "mainwindow.h"
#include "ui_searchset.h"

#include <QApplication>
#include <QAction>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>
#include <QSplitter>
#include <QStyleFactory>
#include <QToolBar>
#include <QDebug>
#include <QMenuBar>
#include <QTime>
#include <QTimer>
#include <QProgressDialog>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QVariant>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <thread>


#include "nodectrl.h"
#include "mainctrl.h"
#include "propertyeditor.h"
#include "relarankgraph/baseedge.h"
#include "relarankgraph/edgearrow.h"
#include "relarankgraph/edgelabel.h"
#include "relarankgraph/node.h"
#include "relarankgraph/nodelabel.h"
#include "relarankgraph/perimeter.h"
#include "relarankgraph/plug.h"
#include "relarankgraph/pluglabel.h"
#include "relarankgraph/scene.h"
#include "relarankgraph/view.h"
using namespace std;

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent)
{
    this->resize(1422, 768);

    // create the main toolbar
    //QMenuBar* mainMenuBar = new QMenuBar(this);
    mainToolBar = new QToolBar("ToolBar", this);
    //this->setMenuBar(mainMenuBar);
    //mainToolBar->setStyleSheet("QToolBar {border: 0px;}");
    //mainToolBar->setIconSize(QSize(12,12));
    mainToolBar->setMovable(false);
    mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    // create global actions
    newNodeAction = new QAction(QIcon(":/icons/incoming.png"), tr("&Open"), this);
    newNodeAction->setShortcuts(QKeySequence::Open);
    newNodeAction->setStatusTip(tr("Open the file"));
    mainToolBar->addAction(newNodeAction);
    connect(newNodeAction, SIGNAL(triggered()), this, SLOT(openfile()));


    matrixAction =new QAction(QIcon(":/icons/matrix.png"),tr("M&atrix"),this);
    matrixAction->setStatusTip(tr("Show the Matrix"));
    mainToolBar->addAction(matrixAction);
    matrixAction->setDisabled(true);
    connect(this, SIGNAL(loaded(bool)), matrixAction, SLOT(setEnabled(bool)));
    connect(matrixAction, SIGNAL(triggered()), this, SLOT(displayMatrix()));


    chainAction =new QAction(QIcon(":/icons/chain.png"),tr("C&hain"),this);
    chainAction->setStatusTip(tr("Show the Chain"));
    mainToolBar->addAction(chainAction);
    chainAction->setDisabled(true);
    connect(this, SIGNAL(loaded(bool)), chainAction, SLOT(setEnabled(bool)));
    connect(chainAction, SIGNAL(triggered()), this, SLOT(displayChian()));


    deepAction =new QAction(QIcon(":/icons/deep.png"),tr("D&FS"),this);
    deepAction->setStatusTip(tr("Deep first search"));
    mainToolBar->addAction(deepAction);
    deepAction->setDisabled(true);
    connect(this, SIGNAL(loaded(bool)), deepAction, SLOT(setEnabled(bool)));
    connect(deepAction, SIGNAL(triggered()), this, SLOT(DFS()));


    widthAction =new QAction(QIcon(":/icons/width.png"),tr("B&FS"),this);
    widthAction->setStatusTip(tr("Breadth first search"));
    mainToolBar->addAction(widthAction);
    widthAction->setDisabled(true);
    connect(this, SIGNAL(loaded(bool)), widthAction, SLOT(setEnabled(bool)));
    connect(widthAction, SIGNAL(triggered()), this, SLOT(BFS()));


    playAction =new QAction(QIcon(":/icons/play.png"),tr("P&lay"),this);
    playAction->setStatusTip(tr("Display the search"));
    mainToolBar->addAction(playAction);
    playAction->setDisabled(true);
    connect(this, SIGNAL(calced(bool)), playAction, SLOT(setEnabled(bool)));
    connect(playAction, SIGNAL(triggered()), this, SLOT(play()));

    stepAction =new QAction(QIcon(":/icons/step.png"),tr("S&tep"),this);
    stepAction->setStatusTip(tr("Step the search"));
    mainToolBar->addAction(stepAction);
    stepAction->setDisabled(true);
    connect(this, SIGNAL(calced(bool)), stepAction, SLOT(setEnabled(bool)));
    connect(stepAction, SIGNAL(triggered()), this, SLOT(step()));

    pauseAction =new QAction(QIcon(":/icons/pause.png"),tr("P&ause"),this);
    pauseAction->setStatusTip(tr("Pause the search"));
    mainToolBar->addAction(pauseAction);
    pauseAction->setDisabled(true);
    connect(this, SIGNAL(calced(bool)), pauseAction, SLOT(setEnabled(bool)));
    connect(pauseAction, SIGNAL(triggered()), this, SLOT(pause()));

    redoAction =new QAction(QIcon(":/icons/redo.png"),tr("R&eload"),this);
    redoAction->setStatusTip(tr("Reload the graph"));
    mainToolBar->addAction(redoAction);
    redoAction->setDisabled(true);
    connect(this, SIGNAL(loaded(bool)), redoAction, SLOT(setEnabled(bool)));
    connect(redoAction, SIGNAL(triggered()), this, SLOT(reload()));


    saveAction = new QAction(QIcon(":/icons/save.png"), tr("&Save"), this);
    saveAction->setStatusTip(tr("Save"));
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setDisabled(true);
    connect(this, SIGNAL(calced(bool)), saveAction, SLOT(setEnabled(bool)));
    mainToolBar->addAction(saveAction);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(savefile()));


    closeAction = new QAction(QIcon(":/icons/outgoing.png"), tr("E&xit"), this);
    closeAction->setStatusTip(tr("Exit"));
    closeAction->setShortcuts(QKeySequence::Close);
    mainToolBar->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));


    helpAction =new QAction(QIcon(":/icons/help.png"),tr("H&elp"),this);
    helpAction->setStatusTip(tr("Help of the operator"));
    mainToolBar->addAction(helpAction);
    connect(helpAction, SIGNAL(triggered()), this, SLOT(displayHelp()));


    aboutAction = new QAction(QIcon(":/icons/questionmark.png"), tr("&About"), this);
    aboutAction->setStatusTip(tr("About this application"));
    mainToolBar->addAction(aboutAction);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(displayAbout()));

    // create the status bar
    statusBar();
    // create the RelaRank graph
    relarankScene = new relarank::Scene(this);
    relarankView = new relarank::View(this);
    relarankView->setScene(relarankScene);
    // create the Property Editor
    propertyEditor = new PropertyEditor(this);
    // create the Main Controller
    ranklist = new RankList(this);
    qsshow = new QSshow(this);
    // create the Node List
    m_mainCtrl = new MainCtrl(this, relarankScene, propertyEditor);
    // setup the main splitter
    m_mainSplitter = new QSplitter(Qt::Horizontal, this);
    m_leftSplitter = new QSplitter(Qt::Vertical,this);
    m_mainSplitter->addWidget(propertyEditor);

    m_mainSplitter->addWidget(relarankView);
    m_mainSplitter->addWidget(m_leftSplitter);
    m_leftSplitter->addWidget(ranklist);
    m_leftSplitter->addWidget(qsshow);
    m_leftSplitter->setSizes({350,400});
    m_mainSplitter->setSizes({200, 900, 200});

    // initialize the GUI
    setCentralWidget(m_mainSplitter);


    solver = NULL;
    displaystep=0;
    playstatus=Pundo;
}



void MainWindow::closeEvent(QCloseEvent * event)
{
    if (m_mainCtrl->shutdown()) {
        // if the user accepted, close the application
        //writeSettings();
        event->accept();
    } else {
        // if the user objected, do nothing
        event->ignore();
    }
}


void MainWindow::displayHelp()
{
    appHelp=new AppHelp;
    appHelp->show();
}

void MainWindow::displayAbout()
{
    QMessageBox aboutBox(this);
    aboutBox.setToolTip("About this Application");
    aboutBox.setText("<h2>Graphope</h2>"
                     "<p>Graphope is an application for showing and editing the graph, as well as displaying the DFS and BFS result.</p>"
                     "<h4>By: </h4><p>&nbsp;&nbsp;&nbsp;&nbsp;1653282<br></p>"
                     "<h4>Website: </h4><p><a href=https://github.com/chenqi-s/DS-hw>https://github.com/chenqi-s/DS-hw</a></p>");
    aboutBox.setIconPixmap(QPixmap(":/icons/sq.jpeg"));
    aboutBox.exec();

}

void MainWindow::openfile()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open Files"), "test.map", tr("Map Files(*.map);;All Files(*.*)"));
    if (fileName == "") return;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("ERROR!"), tr("Can not open this fils. %1").arg(fileName));
        return;
    }
    file.close();
    emit loaded(true);
    if(solver != NULL) delete solver;
    solver = new Solver(fileName);
    //Solver->calc();
    clearsta();
    printsta(m_mainCtrl, solver->get_node(), solver->get_edge());
}



void MainWindow::reload()
{
    clearsta();
    printsta(m_mainCtrl, solver->get_node(), solver->get_edge());
    displaystep=0;
}

void MainWindow::calculate()
{
    if(solver == NULL)return;
    clearsta();
    QDialog *ans = new QDialog(this, Qt::WindowCloseButtonHint);
    ans->setWindowTitle("MST Answer");
    ans->setAutoFillBackground(true);
    ans->setPalette(QPalette(Qt::white));
    QLCDNumber *LCD = new QLCDNumber(ans);
    LCD->setDigitCount(20);
    //LCD->display(solver->get_ans());
    QHBoxLayout *layout = new QHBoxLayout(ans);
    ans->setLayout(layout);
    layout->addWidget(LCD);
    ans->resize(600, 100);
    ans->show();
    printsta(m_mainCtrl, solver->get_node(), solver->get_ansedge());
    emit calced(true);
}

void MainWindow::savefile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Files"), "result.png", tr("PNG Files(*.png);;All Files(*.*)"));
    solver->print(fileName);
}

void MainWindow::clearsta()
{
    for (vector < NodeCtrl * >::const_iterator i = nodectrl.begin();
         i != nodectrl.end(); i++) {
        if(*i != NULL)(*i)->remove();
        delete *i;
    }
    nodectrl.clear();
    delete m_mainCtrl;
    delete relarankView;
    delete relarankScene;
    delete propertyEditor;
    delete ranklist;
    delete qsshow;
    delete m_leftSplitter;
    delete m_mainSplitter;

    relarankScene = new relarank::Scene(this);
    relarankView = new relarank::View(this);
    relarankView->setScene(relarankScene);
    ranklist = new RankList(this);
    propertyEditor = new PropertyEditor(this);
    qsshow = new QSshow(this);
    m_mainCtrl = new MainCtrl(this, relarankScene, propertyEditor);
    m_mainSplitter = new QSplitter(Qt::Horizontal, this);
    m_leftSplitter = new QSplitter(Qt::Vertical,this);
    m_mainSplitter->addWidget(propertyEditor);

    m_mainSplitter->addWidget(relarankView);
    m_mainSplitter->addWidget(m_leftSplitter);
    m_leftSplitter->addWidget(ranklist);
    m_leftSplitter->addWidget(qsshow);
    m_leftSplitter->setSizes({350,400});
    m_mainSplitter->setSizes({200, 900, 200});
    setCentralWidget(m_mainSplitter);
}


void MainWindow::printsta(MainCtrl * mainCtrl, vector<graph_node>& node, vector<graph_edge>& edge)
{
    QProgressDialog progress_dialog("    Loading graph file...    ", "Cancel", 0, node.size() + edge.size(), this);
    progress_dialog.show();
    qApp->processEvents();
    nodectrl.assign(node.size(), NULL);
    for (vector < graph_node >::const_iterator i = node.begin(); i != node.end(); i++) {
        progress_dialog.setValue(i - node.begin());
        QString name(i->get_id());
        nodectrl[i-node.begin()]=mainCtrl->createNode(name);
        nodectrl[i-node.begin()]->getNodeHandle().setPos(i->get_x()*70, -i->get_y()*70);
        qApp->processEvents();
        if (progress_dialog.wasCanceled()) {
            break;
        }
    }
    ranklist->changelist(edge, nodectrl);
    for (vector < graph_edge >::const_iterator i = edge.begin(); i != edge.end(); i++) {
        progress_dialog.setValue(node.size() + i - edge.begin());
        QVariant from(i->get_x()+1), to(i->get_y()+1), value(i->get_w());
        relarank::PlugHandle x = nodectrl[i->get_x()]->addOutgoingPlug("Out to " + to.toString() + " Value = " + value.toString());
        relarank::PlugHandle y = nodectrl[i->get_y()]->addIncomingPlug("In from " + from.toString() + " Value = " + value.toString());
        x.connectPlug(y);
//        y = nodectrl[i->get_x()]->addIncomingPlug("In from " + to.toString() + " Value = " + value.toString());
//        x = nodectrl[i->get_y()]->addOutgoingPlug("Out to " + from.toString() + " Value = " + value.toString());
//        x.connectPlug(y);
        qApp->processEvents();
        if (progress_dialog.wasCanceled()) {
            return;
        }
    }
    progress_dialog.accept();
}



void MainWindow::DFS()
{
    dfsset=new Searchset(solver->size_node,0,this);
    dfsset->show();
    QPushButton* OK=dfsset->ui->buttonBox->button(QDialogButtonBox::Ok);
    connect(OK,SIGNAL(clicked()),this,SLOT(doDFS()));
}

void MainWindow::doDFS()
{
    if(solver == NULL)return;
    clearsta();

     if(dfsset->set->currentIndex()==0)
         solver->DFSTraverse_ND(dfsset->startNode->currentIndex());
     else
         solver->DFSTraverse_D(dfsset->startNode->currentIndex());

    printsta(m_mainCtrl, solver->get_node(), solver->get_ansedge());

    emit calced(true);
    playstatus=Pend;
}


void MainWindow::BFS()
{
    bfsset=new Searchset(solver->size_node,1,this);
    bfsset->show();
    QPushButton* OK=bfsset->ui->buttonBox->button(QDialogButtonBox::Ok);
    connect(OK,SIGNAL(clicked()),this,SLOT(doBFS()));

}

void MainWindow::doBFS()
{
    if(solver == NULL)return;
    clearsta();

    solver->BFSTraverse(bfsset->startNode->currentIndex());
    printsta(m_mainCtrl, solver->get_node(), solver->get_ansedge());

    emit calced(true);
    playstatus=Pend;
}


void delay(int mSec)
{
//    QEventLoop loop;
//    QTimer::singleShot(mSec, &loop, SLOT(quit()));
//    loop.exec();
    QTime dieTime = QTime::currentTime().addMSecs(mSec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::play()
{
    if(solver == NULL)return;
    //    thread Th(&MainWindow::playing(),this);
    //    Th.detach();

    // qDebug()<<"play start";
    if(playstatus == Pause)
        playstatus=Playing;
    while(1)
    {
        step();
        if(playstatus==Pause || playstatus==Pend)
            return;
        delay(800);
    }

}




void MainWindow::step()
{
    if(playstatus == Pundo || playstatus == Pend)
    {
        clearsta();
        displaystep=0;
        playstatus = Playing;
        nodectrl.assign(solver->get_node().size(), NULL);
        ranklist->changelist(solver->get_ansedge(), nodectrl);
    }
    else
    {
        if(solver->QSHistory.size()>uint(displaystep))
        {
            int F=solver->QSHistory[displaystep].from,T=solver->QSHistory[displaystep].to;
            if(solver->QSHistory[displaystep].type == 1 )
            {
                qDebug()<< "+" <<F << T;
                if(nodectrl[T] ==NULL )
                {
                    nodectrl[T]=m_mainCtrl->createNode(solver->get_node().at(T).get_id());
                    nodectrl[T]->getNodeHandle().setPos(solver->get_node().at(T).get_x()*70,-solver->get_node().at(T).get_y()*70);
                }
                if(nodectrl[T] ==NULL)
                {
                    nodectrl[F]=m_mainCtrl->createNode(solver->get_node().at(F).get_id());
                    nodectrl[F]->getNodeHandle().setPos(solver->get_node().at(F).get_x()*70, -solver->get_node().at(F).get_y()*70);
                }
                graph_edge nowedge=solver->edge[solver->map[F][T]];
                QVariant from(nowedge.get_x()+1),to(nowedge.get_y()+1), value(nowedge.get_w());
                relarank::PlugHandle x = nodectrl[nowedge.get_x()]->addOutgoingPlug("Out to " + to.toString() + " Value = " + value.toString());
                relarank::PlugHandle y = nodectrl[nowedge.get_y()]->addIncomingPlug("In from " + from.toString() + " Value = " + value.toString());
                x.connectPlug(y);

                qsshow->add(QString::number(T+1));
            }
            else if(solver->QSHistory[displaystep].type == -1)
            {
                qDebug()<< "-" << F << T;
    //            graph_edge nowedge=solver->edge[solver->map[F][T]];
    //            QVariant from(nowedge.get_x()+1),to(nowedge.get_y()+1);
    //            relarank::PlugHandle x = nodectrl[nowedge.get_x()]->("Out to " + to.toString() + " Value = " + value.toString());
    //            relarank::PlugHandle y = nodectrl[nowedge.get_y()]->("In from " + from.toString() + " Value = " + value.toString());
                //x.disconnectPlug(y);
                if(solver->QSHistory[0].type == 0 && solver->QSHistory[0].from == 0)
                {
                    qsshow->deleteQueue();
                }
                else if(solver->QSHistory[0].type == 0 && solver->QSHistory[0].from >= 1)
                {
                    qsshow->deleteStack();
                }
            }
            else if(solver->QSHistory[displaystep].type == 2 )
            {
                qDebug()<< "o" << F << T;
                if(nodectrl[T]==NULL)
                {
                    nodectrl[T]=m_mainCtrl->createNode(solver->get_node().at(T).get_id());
                    nodectrl[T]->getNodeHandle().setPos(solver->get_node().at(T).get_x()*70,
                                                        -solver->get_node().at(T).get_y()*70);
                }

    //            nodectrl[i-node.begin()]=m_mainCtrl->createNode(name);
    //            nodectrl[i-node.begin()]->getNodeHandle().setPos(i->get_x()*70, -i->get_y()*70);
                qsshow->add(QString::number(T+1));
            }
            ++displaystep;
        }
        else
        {
            qDebug()<< "Play end";
            --displaystep;
            playstatus=Pend;

        }
    }

}


void MainWindow::pause()
{
    if(playstatus!=Pend)
        playstatus=Pause;
}



void MainWindow::displayMatrix()
{
    if(solver==NULL)return;
    matrixshow=new Matrixshow(this);
    matrixshow->generator->setupModel(solver);
    matrixshow->show();
}


void MainWindow::displayChian()
{
    ChainShow *widget = new ChainShow;
    widget->setupModel(solver);
//    QMainWindow *chainshow=new QMainWindow;
//    chainshow->setCentralWidget(widget);
//    chainshow->resize(1000,800);

    widget->show();
}
