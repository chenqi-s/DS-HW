#include "matrixshow.h"



Matrixshow::Matrixshow(QWidget *parent) :
    QDialog(parent)
{

    graph=new Q3DBars();

    container =QWidget::createWindowContainer(graph);

    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
    }

    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 2));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    help=new QLabel(this);
    help->setText("鼠标左键查看,右键旋转,滚动缩放,点击表格查看,修改数据");

    layout = new QVBoxLayout(this);
    tableWidget = new QTableWidget();
    layout->addWidget(help,0);
    layout->addWidget(container, 2);
    layout->addWidget(tableWidget, 2, Qt::AlignHCenter);

    tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    tableWidget->setAlternatingRowColors(true);
    setWindowTitle(QStringLiteral("Matrix of the Graph"));


    // Since we are dealing with QTableWidget, the model will already have data sorted properly
    // into rows and columns, so we simply set useModelCategories property to true to utilize this.
    QItemModelBarDataProxy *proxy = new QItemModelBarDataProxy(tableWidget->model());
    proxy->setUseModelCategories(true);
    QBar3DSeries *series = new QBar3DSeries(proxy);
    series->setMesh(QAbstract3DSeries::MeshPyramid);
    graph->addSeries(series);


    generator=new GraphDataGenerator(graph, tableWidget);
    QObject::connect(series, &QBar3DSeries::selectedBarChanged, generator,
                     &GraphDataGenerator::selectFromTable);
    QObject::connect(tableWidget, &QTableWidget::currentCellChanged, generator,
                     &GraphDataGenerator::selectedFromTable);

    generator->start();

}

Matrixshow::~Matrixshow()
{
    delete generator;
    delete layout;
    delete tableWidget;
    delete container;
    delete graph;

}


