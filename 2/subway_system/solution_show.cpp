#include "solution_show.h"
#include "ui_solution_show.h"
#include <QImage>

Solution_show::Solution_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Solution_show),
    ChooseBox(createChooseBox())
{
    ui->setupUi(this);
    // create layout
    baseLayout = new QGridLayout();
    QHBoxLayout *HsettingsLayoutup = new QHBoxLayout();
    HsettingsLayoutup->addWidget(new QLabel("Method:"));
    HsettingsLayoutup->addWidget(ChooseBox);
    HsettingsLayoutup->addStretch();
    baseLayout->addLayout(HsettingsLayoutup,0,0,1,2);

    QVBoxLayout *VsettingsLayout = new QVBoxLayout();
    VsettingsLayout->addWidget(ui->textBrowser_Solution);
    baseLayout->addLayout(VsettingsLayout, 1, 0, 2, 1);
    //create charts


    scene = new QGraphicsScene;
    graphicsView=new QGraphicsView;
    graphicsView->setScene(scene);
    graphicsView->setMaximumWidth(600);
    baseLayout->addWidget(graphicsView,1,1);

    QHBoxLayout *HsettingsLayoutdown = new QHBoxLayout();
    HsettingsLayoutdown->addWidget(ui->button_compare);
    HsettingsLayoutdown->addWidget(ui->button_save);
    HsettingsLayoutdown->addWidget(ui->button_OK);
    baseLayout->addLayout(HsettingsLayoutdown,3,0,4,2);

    setLayout(baseLayout);

    QPalette pal = window()->palette();
    pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    //pal.setColor(QPalette::Window, QRgb(0x121218));
    //pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    window()->setPalette(pal);

    //compare->chart()->setTheme(QChart::ChartThemeQt);

    //connect(ChooseBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateUI()));

    connect(ui->button_save, SIGNAL(clicked()), this, SLOT(onFileSave()));

}

Solution_show::~Solution_show()
{
    delete ui;
    delete baseLayout;
}


void Solution_show::setText(QString text)
{
    QTextBrowser *browser=ui->textBrowser_Solution;
    browser->clear();
    browser->setText(text);
}


QComboBox *Solution_show::createChooseBox() const
{
    QComboBox *themeComboBox = new QComboBox();
    themeComboBox->addItem("换乘次数最少", 0);
    themeComboBox->addItem("所需时间最短", 1);
    themeComboBox->addItem("路过站台最少", 2);
    return themeComboBox;
}




void Solution_show::onFileSaveAs()
{
    QString path = QFileDialog::getSaveFileName(this,
        tr("Save File"), "solution", tr("file folder"));
    if (path.isEmpty())
        return;
    m_filePath = path;

    onFileSave();
}


void Solution_show::onFileSave()
{
    if (m_filePath.isEmpty()) {
        onFileSaveAs();
        return;
    }

    QDir dir;
    dir.mkpath(m_filePath);
    QFile f(m_filePath+"/solution.md");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))  {
        QMessageBox::warning(this, windowTitle(),
                             tr("Could not write to file %1: %2").arg(
                                 QDir::toNativeSeparators(m_filePath), f.errorString()));
        return;
    }
    QTextStream str(&f);
    str << ui->textBrowser_Solution->toPlainText()<<"\n ![avatar]("<<m_filePath<<"/solution.png"<< ")";
    QImage image(scene->width(),scene->height(),QImage::Format_RGB32);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter);
    image.save(m_filePath+"/solution.png");

    m_filePath.clear();

}




