#ifndef SOLUTION_SHOW_H
#define SOLUTION_SHOW_H

#include <QDialog>
#include <QtWidgets/QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFontDatabase>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTextStream>
#include "solution_view.h"
#include "chartview.h"

class MainWindow;

namespace Ui {
class Solution_show;
}

class Solution_show : public QDialog
{
    Q_OBJECT

public:
    explicit Solution_show(QWidget *parent = 0);
    ~Solution_show();
    void setText(QString text);

protected:
    Ui::Solution_show *ui;
    QGridLayout *baseLayout;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QComboBox *ChooseBox;

    QString m_filePath;

    int chartype;


    friend class MainWindow;

private:
    QComboBox *createChooseBox() const;

private slots:
    void onFileSave();
    void onFileSaveAs();
};

#endif // SOLUTION_SHOW_H
