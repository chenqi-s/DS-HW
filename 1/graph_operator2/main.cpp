#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
using namespace std;
int main(int argc, char *argv[])
{
    // create application
    QApplication app(argc, argv);
    app.setApplicationName("Graphope");
    app.setWindowIcon(QIcon(":/icons/GO.png"));
    MainWindow window;
    window.show();
    return app.exec();
}
