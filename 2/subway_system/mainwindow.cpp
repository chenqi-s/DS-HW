#include "ui_mainwindow.h"
#include "ui_managelines.h"
#include "ui_solution_show.h"
#include "mainwindow.h"

#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myView = new Graphics_view_zoom(ui->graphicsView,ui->verticalSlider);
    myView->set_modifiers(Qt::NoModifier);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene=new QGraphicsScene;
    scene->setSceneRect(-LINE_INFO_WIDTH,0,SCENE_WIDTH,SCENE_HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    initStatusBar();

    manageLines=new ManageLines(this);
    subwayGraph=new SubwayGraph;
    appHelp=new AppHelp();
    solution = new Solution_show(this) ;

    bool flag = subwayGraph->readFileData(":/data/data/outLine.txt");
    if (!flag)
    {
        QMessageBox box;
        box.setWindowTitle(tr("error information"));
        box.setIcon(QMessageBox::Warning);
        box.setText("读取数据错误!\n将无法展示内置线路！");
        box.addButton(tr("确定"), QMessageBox::AcceptRole);
        if (box.exec() == QMessageBox::Accepted)
        {
            box.close();
        }
    }


    myConnect();

    updateTranserQueryInfo();

    on_actionLineMap_triggered();


    way=1;
    solution->ChooseBox->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myView;
    delete scene;
    delete subwayGraph;
    delete manageLines;
    delete appHelp;
    delete solution;
}

//连接信号和槽函数
void MainWindow::myConnect()
{
    connect(manageLines->ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabWidgetCurrentChanged(int)));
    connect(manageLines->ui->pushButtonAddLine, SIGNAL(clicked()), this, SLOT(addLine()));
    connect(manageLines->ui->pushButtonAddStation, SIGNAL(clicked()), this, SLOT(addStation()));
    connect(manageLines->ui->pushButtonConnect, SIGNAL(clicked()), this, SLOT(addConnection()));


    connect(solution->ui->button_compare, SIGNAL(clicked()), this, SLOT(SetChartCompare()));

    connect(solution->ui->button_OK, SIGNAL(clicked()), solution, SLOT(close()));

    connect(solution->ChooseBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(setMethod_S()));

    connect(ui->radioButtonMinStation,SIGNAL(clicked()),this,SLOT(setMethod_M()));
    connect(ui->radioButtonMinTime,SIGNAL(clicked()),this,SLOT(setMethod_M()));
    connect(ui->radioButtonMinTransfer,SIGNAL(clicked()),this,SLOT(setMethod_M()));

    connect(ui->comboBoxStartLine, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(transferStartLineChanged(QString)));
    connect(ui->comboBoxDstLine, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(transferDstLineChanged(QString)));
    connect(ui->pushButtonTransfer, SIGNAL(clicked()), this, SLOT(transferQuery()));

    QTimer *timer = new QTimer(this);//新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));//关联定时器计满信号和相应的槽函数
    timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒
}

//时间更新槽函数
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    statusLabel1->setText(str);
}

//初始状态栏
void MainWindow::initStatusBar()
{
    QStatusBar* bar = ui->statusBar;


    statusLabel1 = new QLabel;
    statusLabel1->setMinimumSize(200,23);
    statusLabel1->setFrameShape(QFrame::Box);
    statusLabel1->setFrameShadow(QFrame::Sunken);

    statusLabel2 = new QLabel;
    statusLabel2->setMinimumSize(500,23);
    statusLabel2->setFrameShape(QFrame::Box);
    statusLabel2->setFrameShadow(QFrame::Sunken);

    bar->addWidget(statusLabel1);
    bar->addWidget(statusLabel2);

    statusLabel1->setText(tr("0000-00-00 00:00::00 星期 "));
    statusLabel2->setText(tr("欢迎使用地铁换乘指南,详情帮助"));
}

//由线路表计算混合颜色
QColor MainWindow::getLinesColor(const QList<int>& linesList)
{
    QColor color1=QColor(255,255,255);
    QColor color2;
    for (int i=0; i<linesList.size(); ++i)
    {
        color2=subwayGraph->getLineColor(linesList[i]);
        color1.setRed(color1.red()*color2.red()/255);
        color1.setGreen(color1.green()*color2.green()/255);
        color1.setBlue(color1.blue()*color2.blue()/255);
    }
    return color1;
}

//获得线路表的名字集
QString MainWindow::getLinesName(const QList<int>& linesList)
{
    QString str;
    str+="\t";
    for (int i=0; i<linesList.size(); ++i)
    {
        str+=" ";
        str+=subwayGraph->getLineName(linesList[i]);
    }
    //    qDebug()<<"tip="<<str<<"\n";
    return str;
}

//将站点的经纬度地理坐标转为视图坐标
QPointF MainWindow::transferCoord(QPointF coord)
{
    QPointF minCoord=subwayGraph->getMinCoord();
    QPointF maxCoord=subwayGraph->getMaxCoord();
    double x = (coord.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*NET_WIDTH+MARGIN;
    double y = (maxCoord.y()-coord.y())/(maxCoord.y()-minCoord.y())*NET_HEIGHT+MARGIN;
    return QPointF(x,y);
}




void MainWindow::setMethod_M()
{
    way=ui->radioButtonMinTransfer->isChecked()?1:
            ui->radioButtonMinTime->isChecked()?2:
            ui->radioButtonMinStation->isChecked() ? 3:0;

}

void MainWindow::setMethod_S()
{
    way=solution->ChooseBox->currentIndex()+1;
    transferQuery();
//    switch (solution->ChooseBox->currentIndex()) {
//    case 0:ui->radioButtonMinTime->setChecked(true);
//        ui->radioButtonMinTransfer->setChecked(false);
//        ui->radioButtonMinStation->setChecked(false);
//        break;
//    case 1:
//        ui->radioButtonMinTime->setChecked(false);
//        ui->radioButtonMinTransfer->setChecked(true);
//        ui->radioButtonMinStation->setChecked(false);
//        break;
//    case 2:
//        ui->radioButtonMinTime->setChecked(false);
//        ui->radioButtonMinTransfer->setChecked(false);
//        ui->radioButtonMinStation->setChecked(true);
//        break;
//    default:
//        break;
//    }
    //emit ui->pushButtonTransfer->click();
}


//绘制网络图的边
void MainWindow::drawEdges(const QList<Edge>& edgesList,int choose)
{
    for(int i=0; i<edgesList.size(); ++i)
    {
        int s1=edgesList[i].first;
        int s2=edgesList[i].second;
        QList<int> linesList=subwayGraph->getCommonLines(s1, s2);
        QColor color=getLinesColor(linesList);
        QString tip="途经： "+subwayGraph->getStationName(s1)+"--"+subwayGraph->getStationName(s2)+"\n线路：";
        tip+=getLinesName(linesList);
        QPointF s1Pos=transferCoord(subwayGraph->getStationCoord(s1));
        QPointF s2Pos=transferCoord(subwayGraph->getStationCoord(s2));

        QGraphicsLineItem* edgeItem=new QGraphicsLineItem;
        edgeItem->setPen(QPen(color, EDGE_PEN_WIDTH));
        edgeItem->setCursor(Qt::PointingHandCursor);
        edgeItem->setToolTip(tip);
        edgeItem->setPos(s1Pos);
        edgeItem->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());

        if(choose==0)
            scene->addItem(edgeItem);

        else if(choose==1)
        {
            solution->scene->addItem(edgeItem);
        }
        else if(choose==2)
        {
            solution->scene->addItem(edgeItem);
            QGraphicsLineItem* edgeItem2=new QGraphicsLineItem;
            edgeItem2->setPen(QPen(color, EDGE_PEN_WIDTH));
            edgeItem2->setCursor(Qt::PointingHandCursor);
            edgeItem2->setToolTip(tip);
            edgeItem2->setPos(s1Pos);
            edgeItem2->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());
             scene->addItem(edgeItem2);
        }

    }

}

#define INF 99999

//绘制网络图的站点节点
void MainWindow::drawStations (const QList<int>& stationsList,int choose)
{
    qreal S(INF),X(0),Z(INF),Y(0);
    for (int i=0; i<stationsList.size(); ++i)
    {
        int s=stationsList[i];
        QString name=subwayGraph->getStationName(s);
        QList<int> linesList=subwayGraph->getStationLinesInfo(s);
        QColor color=getLinesColor(linesList);
        QPointF longiLati=subwayGraph->getStationCoord(s);
        QPointF coord=transferCoord(longiLati);
        QString tip="站名：  "+name+"\n"+
                "经度：  "+QString::number(longiLati.x(),'f',5)+"\n"+
                "纬度：  "+QString::number(longiLati.y(),'f',5)+"\n"+
                "线路："+getLinesName(linesList);

        QGraphicsEllipseItem* stationItem=new QGraphicsEllipseItem;
        stationItem->setRect(-NODE_HALF_WIDTH, -NODE_HALF_WIDTH, NODE_HALF_WIDTH<<1, NODE_HALF_WIDTH<<1);
        stationItem->setPos(coord);
        stationItem->setPen(color);
        stationItem->setCursor(Qt::PointingHandCursor);
        stationItem->setToolTip(tip);

        Z=coord.x()<Z? coord.x():Z;
        Y=coord.x()>Y? coord.x():Y;
        S=coord.y()<S? coord.y():S;
        X=coord.y()>X? coord.y():X;

        if(linesList.size()<=1)
        {
            stationItem->setBrush(QColor(QRgb(0xffffff)));
        }

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(name);
        textItem->setFont(QFont("consolas",4,1));
        textItem->setPos(coord.x(),coord.y()-NODE_HALF_WIDTH*2);


        if(choose==0)
        {
            scene->addItem(stationItem);
            scene->addItem(textItem);
        }
        else if(choose==1)
        {
            solution->scene->addItem(stationItem);
            solution->scene->addItem(textItem);
        }
        else if(choose==2)
        {
            solution->scene->addItem(stationItem);
            solution->scene->addItem(textItem);

            QGraphicsEllipseItem* stationItem2=new QGraphicsEllipseItem;
            stationItem2->setRect(-NODE_HALF_WIDTH, -NODE_HALF_WIDTH, NODE_HALF_WIDTH<<1, NODE_HALF_WIDTH<<1);
            stationItem2->setPos(coord);
            stationItem2->setPen(color);
            stationItem2->setCursor(Qt::PointingHandCursor);
            stationItem2->setToolTip(tip);

            if(linesList.size()<=1)
            {
                stationItem2->setBrush(QColor(QRgb(0xffffff)));
            }

            QGraphicsTextItem* textItem2=new QGraphicsTextItem;
            textItem2->setPlainText(name);
            textItem2->setFont(QFont("consolas",4,1));
            textItem2->setPos(coord.x(),coord.y()-NODE_HALF_WIDTH*2);

            scene->addItem(stationItem2);
            scene->addItem(textItem2);
        }
    }

    solution->graphicsView->centerOn((Z+Y)/2,(S+X)/2);
    ui->graphicsView->centerOn((Z+Y)/2,(S+X)/2);
}


//更新换乘选择信息
void MainWindow::updateTranserQueryInfo()
{
    statusLabel2->setText(tr("已更新数据"));
    QComboBox* comboL1=ui->comboBoxStartLine;
    QComboBox* comboL2=ui->comboBoxDstLine;

    comboL1->clear();
    comboL2->clear();
    QList<QString> linesList=subwayGraph->getLinesNameList();
    for(auto &a:linesList)
    {
        comboL1->addItem(a);
        comboL2->addItem(a);
    }
    transferStartLineChanged(comboL1->itemText(0));
    transferDstLineChanged(comboL2->itemText(0));
}

//换乘出发线路改变槽函数
void MainWindow::transferStartLineChanged(QString lineName)
{
    QComboBox* comboS1=ui->comboBoxStartStation;
    comboS1->clear();

    int lineHash=subwayGraph->getLineHash(lineName);
    if(lineHash==-1)
    {
        return ;
    }

    QList<QString> stationsList=subwayGraph->getLineStationsList(lineHash);
    for(auto &a:stationsList)
    {
        comboS1->addItem(a);
    }
}

//换乘目的线路改变槽函数
void MainWindow::transferDstLineChanged(QString lineName)
{
    QComboBox* comboS2=ui->comboBoxDstStation;
    comboS2->clear();

    int lineHash=subwayGraph->getLineHash(lineName);
    if(lineHash==-1)
    {
        return ;
    }

    QList<QString> stationsList=subwayGraph->getLineStationsList(lineHash);
    for(auto &a:stationsList)
    {
        comboS2->addItem(a);
    }
}

//换乘查询槽函数
void MainWindow::transferQuery()
{
    int s1=subwayGraph->getStationHash(ui->comboBoxStartStation->currentText());
    int s2=subwayGraph->getStationHash(ui->comboBoxDstStation->currentText());


    if(s1==-1||s2==-1)
    {
        QMessageBox box;
        box.setWindowTitle(tr("换乘查询"));
        box.setWindowIcon(QIcon(":/icon/icon/query.png"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择有站点的线路"));
        box.addButton(tr("确定"),QMessageBox::AcceptRole);
        if(box.exec()==QMessageBox::Accepted)
        {
            box.close();
        }
    }
    else
    {
        QList<int> stationsList;
        QList<Edge> edgesList;
        bool flag=true;
        int distance,CT;
        if(way==1)
        {
            flag=subwayGraph->queryTransferMinTransfer(s1, s2, stationsList, edgesList,distance,CT);
        }
        else if(way==2)
        {
            flag=subwayGraph->queryTransferMinTime(s1, s2, stationsList, edgesList,distance,CT);
        }
        else if(way==3)
        {
            flag=subwayGraph->queryTransferMinStation(s1, s2, stationsList, edgesList,distance,CT);
        }

        if(flag)
        {
            statusLabel2->setText(tr("换乘查询成功！"));
            scene->clear();
            solution->scene->clear();
            drawEdges(edgesList,2);
            drawStations(stationsList,2);
            QString text=way==1? ("以下线路换乘最少，共换乘"+QString::number(CT)+"条线路\n\n"):
                         way==2?("以下线路时间最短，共经历"+QString::number(distance)+" m\n\n"):
                         way==3? ("以下路过站台最少，共经历"+QString::number(stationsList.size()-1)+"个站台\n\n"):"";
            for(int i=0; i<stationsList.size(); ++i)
            {
                if(i)
                {
                    text+="\n  ↓\n";
                }
                text+=subwayGraph->getStationName(stationsList[i]);
                QString linesStr=getLinesName(subwayGraph->getStationLinesInfo(stationsList[i]));
                text+=linesStr;
            }
            solution->show();
            solution->setText(text);
        }
        else
        {
            QMessageBox box;
            box.setWindowTitle(tr("换乘查询"));
            box.setWindowIcon(QIcon(":/icon/icon/query.png"));
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("您选择的起始和终止站点暂时无法到达！"));
            box.addButton(tr("确定"),QMessageBox::AcceptRole);
            if(box.exec()==QMessageBox::Accepted)
            {
                box.close();
            }
        }
    }
    if(solution->ChooseBox->currentIndex()!=way-1)
        solution->ChooseBox->setCurrentIndex(way-1);
}

//添加列表视图部件变化槽函数
void MainWindow::tabWidgetCurrentChanged(int index)
{
    QWidget* widget=manageLines->ui->tabWidget->currentWidget();

    if(widget==manageLines->tabWigetsVector[1])
    {
        manageLines->linesNameList=subwayGraph->getLinesNameList();
        manageLines->updateLinesListWidget();
    }
    else if(widget==manageLines->tabWigetsVector[2])
    {
        manageLines->linesNameList=subwayGraph->getLinesNameList();
        manageLines->stationsNameList=subwayGraph->getStationsNameList();
        manageLines->ui->comboBoxConnectStation1->setMaxCount(manageLines->stationsNameList.size());
        manageLines->ui->comboBoxConnectStation2->setMaxCount(manageLines->stationsNameList.size());
        manageLines->ui->comboBoxConnectLine->setMaxCount(manageLines->linesNameList.size());
        manageLines->updateComboBox();
    }
    Q_UNUSED(index);
}

//添加线路功能函数
void MainWindow::addLine()
{
    QMessageBox box;
    box.setWindowTitle(tr("添加线路"));
    box.setWindowIcon(QIcon(":/icon/icon/subway.png"));

    if(manageLines->lineName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入线路名称！"));
    }
    else if(subwayGraph->getLineHash(manageLines->lineName)==-1)
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("线路：")+manageLines->lineName+tr(" 添加成功！"));
        subwayGraph->addLine(manageLines->lineName, manageLines->lineColor);
        updateTranserQueryInfo();
    }
    else
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("添加失败！\n错误原因：线路名已存在！"));
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    updateTranserQueryInfo();
}

//添加站点功能函数
void MainWindow::addStation()
{
    QMessageBox box;
    box.setWindowTitle(tr("添加站点"));
    box.setWindowIcon(QIcon(":/icon/icon/station.png"));

    if(manageLines->stationName.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入站点名称！"));
    }
    else if(manageLines->linesSelected.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择站点所属线路！"));
    }
    else
    {
        if(subwayGraph->getStationHash(manageLines->stationName)!=-1)
        {
            box.setIcon(QMessageBox::Critical);
            box.setText(tr("添加失败！\n错误原因：站点已存在！"));
        }
        else
        {
            Station s(manageLines->stationName, manageLines->longitude, manageLines->latitude,
                      subwayGraph->getLinesHash(manageLines->linesSelected));
            subwayGraph->addStation(s);
            box.setText(tr("站点：")+manageLines->stationName+tr(" 添加成功！"));
            updateTranserQueryInfo();
        }
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    updateTranserQueryInfo();
    on_actionLineMap_triggered();
}

//添加连接功能函数
void MainWindow::addConnection()
{
    QString station1=manageLines->ui->comboBoxConnectStation1->currentText();
    QString station2=manageLines->ui->comboBoxConnectStation2->currentText();
    int s1=subwayGraph->getStationHash(station1);
    int s2=subwayGraph->getStationHash(station2);
    int l=subwayGraph->getLineHash(manageLines->ui->comboBoxConnectLine->currentText());

    QMessageBox box;
    box.setWindowTitle(tr("添加连接"));
    box.setWindowIcon(QIcon(":/icon/icon/connect.png"));

    if(s1==-1||s2==-1||l==-1)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择已有的站点和线路！"));
    }
    else if(s1==s2)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("同一站点不需要连接！"));
    }
    else if(!subwayGraph->getStationLinesInfo(s1).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点1"));
    }
    else if(!subwayGraph->getStationLinesInfo(s2).contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败！\n错误原因：所属线路不包含站点2"));
    }
    else
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("添加连接成功！"));
        subwayGraph->addConnection(s1,s2,l);
    }
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    updateTranserQueryInfo();
    on_actionLineMap_triggered();
}


//动作添加所有槽函数
void MainWindow::on_actionAddAll_triggered()
{
    statusLabel2->setText(tr("添加线路、站点、连接关系"));
    manageLines->setAllVisible();
    manageLines->show();
}

//动作添加线路槽函数
void MainWindow::on_actionAddLine_triggered()
{
    statusLabel2->setText(tr("添加线路"));
    manageLines->setAddLineVisible();
    manageLines->show();
}

//动作添加站点槽函数
void MainWindow::on_actionAddStation_triggered()
{
    statusLabel2->setText(tr("添加站点"));
    manageLines->setAddStationVisible();
    manageLines->show();
}

//动作添加连接槽函数
void MainWindow::on_actionAddConnect_triggered()
{
    statusLabel2->setText(tr("添加连接关系"));
    manageLines->setAddConnectionVisible();
    manageLines->show();
}



//动作查看所有线路图槽函数
void MainWindow::on_actionLineMap_triggered()
{
    statusLabel2->setText(tr("图示：上海地铁网络线路图"));
    scene->clear();
    QList<int> stationsList;
    QList<Edge> edgesList;
    subwayGraph->getGraph(stationsList,edgesList);
    drawEdges(edgesList);
    drawStations(stationsList);
    //    qDebug()<<"stations.size()="<<stationsList.size()<<" edges.size()="<<edgesList.size();
}

//动作是否显示状态栏槽函数
void MainWindow::on_actionstatusBar_triggered(bool checked)
{
    if(checked)
    {
        ui->statusBar->show();
    }
    else
    {
        ui->statusBar->hide();
    }
}

//动作是否显示工具栏槽函数
void MainWindow::on_actiontoolBar_triggered(bool checked)
{
    if(checked)
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}


//动作关于作者槽函数
void MainWindow::on_actionAuthor_triggered()
{
    QMessageBox aboutBox(this);
    aboutBox.setToolTip("About this Application");
    aboutBox.setText("<h2>Subway system</h2>"
                     "<p>Subway system is an application for Shanghai Metro Route Query.</p>"
                     "<h4>By: </h4><p>&nbsp;&nbsp;&nbsp;&nbsp;1653282<br></p>"
                     "<h4>Website: </h4><p><a href=https://github.com/chenqi-s/DS-hw>https://github.com/chenqi-s/DS-hw</a></p>");
    aboutBox.setIconPixmap(QPixmap(":/icon/icon/sq.jpeg"));
    aboutBox.exec();
}

//动作帮助菜单槽函数
void MainWindow::on_actionuseHelp_triggered()
{
    appHelp->show();
}

//动作关闭程序槽函数
void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionQueryInfo_triggered()
{

}



void MainWindow::SetChartCompare()
{
    M1.clear();M2.clear();M3.clear();

    int s1=subwayGraph->getStationHash(ui->comboBoxStartStation->currentText());
    int s2=subwayGraph->getStationHash(ui->comboBoxDstStation->currentText());

    QList<int> stationsList;
    QList<Edge> edgesList;

    int distance,CT;
    subwayGraph->queryTransferMinTransfer(s1, s2, stationsList, edgesList,distance,CT);
    M1.push_back(distance);M1.push_back(stationsList.size());M1.push_back(CT);
    subwayGraph->queryTransferMinTime(s1, s2, stationsList, edgesList,distance,CT);
    M2.push_back(distance);M2.push_back(stationsList.size());M2.push_back(CT);
    subwayGraph->queryTransferMinStation(s1, s2, stationsList, edgesList,distance,CT);
    M3.push_back(distance);M3.push_back(stationsList.size());M3.push_back(CT);


    QVector<int > max;
    for(int i=0;i<3;++i)
    {
        max.append(qMax(qMax(qMax(M1[i],M2[i]),M3[i]),1));
    }

    compare = new ChartView(0,M1,M2,M3,max);
    compare->show();
}
