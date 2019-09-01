#include "graphdatagenerator.h"


GraphDataGenerator::GraphDataGenerator(Q3DBars *bargraph, QTableWidget *tableWidget)
    : m_graph(bargraph),
      m_dataTimer(0),
      m_styleTimer(0),
      m_presetTimer(0),
      m_themeTimer(0),
      m_columnCount(100),
      m_rowCount(50),
      m_tableWidget(tableWidget)
{

    // Set up bar specifications; make the bars as wide as they are deep,
    // and add a small space between them
    m_graph->setBarThickness(1.0f);
    m_graph->setBarSpacing(QSizeF(0.2, 0.2));


#ifndef USE_STATIC_DATA
    // Set up sample space; make it as deep as it's wide
    m_graph->rowAxis()->setRange(0, m_rowCount);
    m_graph->columnAxis()->setRange(0, m_columnCount);
    m_tableWidget->setColumnCount(m_columnCount);

    // Set selection mode to full
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemRowAndColumn);

    // Hide axis labels by explicitly setting one empty string as label list
    m_graph->rowAxis()->setLabels(QStringList(QString()));
    m_graph->columnAxis()->setLabels(QStringList(QString()));

    m_graph->seriesList().at(0)->setItemLabelFormat(QStringLiteral("@valueLabel"));
#else
    // Set selection mode to slice row
    m_graph->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow | QAbstract3DGraph::SelectionSlice);
#endif


    m_graph->activeTheme()->setType(Q3DTheme::ThemeDigia);
    m_graph->activeTheme()->setFont(QFont("Impact", 20));
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);

    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::darkGreen);
    gr.setColorAt(0.5, Qt::yellow);
    gr.setColorAt(0.8, Qt::red);
    gr.setColorAt(1.0, Qt::darkRed);

    m_graph->seriesList().at(0)->setBaseGradient(gr);
    m_graph->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

}

GraphDataGenerator::~GraphDataGenerator()
{
    if (m_dataTimer) {
        m_dataTimer->stop();
        delete m_dataTimer;
    }
    delete m_graph;
}



void GraphDataGenerator::start()
{
#ifndef USE_STATIC_DATA
    m_dataTimer = new QTimer();
    m_dataTimer->setTimerType(Qt::CoarseTimer);
    QObject::connect(m_dataTimer, &QTimer::timeout, this, &GraphDataGenerator::addRow);
    m_dataTimer->start(0);
    m_tableWidget->setFixedWidth(m_graph->width());
#else
    //setupModel();

    // Table needs to be shown before the size of its headers can be accurately obtained,
    // so we postpone it a bit
    m_dataTimer = new QTimer();
    m_dataTimer->setSingleShot(true);
    QObject::connect(m_dataTimer, &QTimer::timeout, this, &GraphDataGenerator::fixTableSize);
    m_dataTimer->start(0);
#endif
}

void GraphDataGenerator::setupModel(Solver *solver)
{

    // Set up row and column names
    QStringList x;
    for(int i=1;i<=solver->size_node;++i)
        x.push_back(QString::number(i));
    QStringList y;

    for(int i=1;i<=solver->size_node;++i)
        y.push_back(QString::number(i));


    // Add labels
    m_graph->rowAxis()->setTitle("From");
    m_graph->rowAxis()->setTitleVisible(true);
    m_graph->columnAxis()->setTitle("To");
    m_graph->columnAxis()->setTitleVisible(true);
    m_graph->valueAxis()->setTitle("Weight");
    m_graph->valueAxis()->setTitleVisible(true);
    m_graph->valueAxis()->setLabelFormat("%.1f");


    m_tableWidget->setRowCount(solver->size_node);
    m_tableWidget->setColumnCount(solver->size_node);
    m_tableWidget->setHorizontalHeaderLabels(x);
    m_tableWidget->setVerticalHeaderLabels(y);
    m_tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tableWidget->setCurrentCell(-1, -1);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);


    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j) {
            QModelIndex index = m_tableWidget->model()->index(i, j);
            m_tableWidget->model()->setData(index, solver->matrix[i][j]);
            m_tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }
}




void GraphDataGenerator::addRow()
{
    m_tableWidget->model()->insertRow(0);
    if (m_tableWidget->model()->rowCount() > m_rowCount)
        m_tableWidget->model()->removeRow(m_rowCount);
    for (int i = 0; i < m_columnCount; i++) {
        QModelIndex index = m_tableWidget->model()->index(0, i);
        m_tableWidget->model()->setData(index,
            ((float)i / (float)m_columnCount) / 2.0f + (float)(rand() % 30) / 100.0f);
    }
    m_tableWidget->resizeColumnsToContents();
}



void GraphDataGenerator::selectFromTable(const QPoint &selection)
{
    m_tableWidget->setFocus();
    m_tableWidget->setCurrentCell(selection.x(), selection.y());
}


void GraphDataGenerator::selectedFromTable(int currentRow, int currentColumn,
                                           int previousRow, int previousColumn)
{
    Q_UNUSED(previousRow)
    Q_UNUSED(previousColumn)
    m_graph->seriesList().at(0)->setSelectedBar(QPoint(currentRow, currentColumn));
}



void GraphDataGenerator::fixTableSize()
{
    int width = m_tableWidget->horizontalHeader()->length();
    width += m_tableWidget->verticalHeader()->width();
    m_tableWidget->setFixedWidth(width + 2);
    int height = m_tableWidget->verticalHeader()->length();
    height += m_tableWidget->horizontalHeader()->height();
    m_tableWidget->setFixedHeight(height + 2);
}

