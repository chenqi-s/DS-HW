#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include "graph.h"
#include "solver.h"
#include "ranklist.h"
#include "nodectrl.h"
#include "apphelp.h"
#include "propertyeditor.h"
#include "relarankgraph/scene.h"
#include "relarankgraph/view.h"
#include "matrixshow.h"
#include "chainshow.h"
#include "qsshow.h"
#include "searchset.h"
class MainCtrl;
class PropertyEditor;
class QSplitter;


enum PlaySta {Pundo,Playing,Pause,Pend};

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:		// methods

    MainWindow(QWidget * parent = 0);
   // ~MainWindow();

protected:			// methods

    void closeEvent(QCloseEvent * event);

private slots:
    void displayAbout();
    void displayHelp();
    void displayMatrix();
    void displayChian();
    void DFS();
    void doDFS();
    void BFS();
    void doBFS();
signals:
    void loaded(bool);
    void calced(bool);
public slots:
    void openfile();
    void savefile();
    void calculate();
    void reload();
    void step();
    void play();
    void pause();



private:			// methods

    void readSettings();

    void writeSettings();

    void printsta(MainCtrl * mainCtrl, std::vector<graph_node>& node, std::vector<graph_edge>& edge);
    void clearsta();
    Solver *solver;
    std::vector < NodeCtrl * >nodectrl;
    relarank::Scene * relarankScene;
    relarank::View * relarankView;
    PropertyEditor *propertyEditor;
    RankList * ranklist;
    QToolBar *mainToolBar;
    QAction *saveAction, *calcAction,*helpAction,*newNodeAction,*matrixAction,*chainAction,
            *deepAction,*widthAction,*playAction,*stepAction,*pauseAction,*redoAction,*closeAction,*aboutAction;
    AppHelp *appHelp;
    MainCtrl * m_mainCtrl;
    Matrixshow *matrixshow;
    QSplitter *m_mainSplitter,*m_leftSplitter;
    QSshow *qsshow;
    QString fileName;
    Searchset *dfsset,*bfsset;
    int displaystep;
    int playstatus;

};

#endif // MAINWINDOW_H
