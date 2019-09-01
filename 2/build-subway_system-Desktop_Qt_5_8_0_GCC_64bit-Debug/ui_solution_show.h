/********************************************************************************
** Form generated from reading UI file 'solution_show.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTION_SHOW_H
#define UI_SOLUTION_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Solution_show
{
public:
    QPushButton *button_compare;
    QPushButton *button_save;
    QPushButton *button_OK;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_Solution;

    void setupUi(QDialog *Solution_show)
    {
        if (Solution_show->objectName().isEmpty())
            Solution_show->setObjectName(QStringLiteral("Solution_show"));
        Solution_show->resize(706, 635);
        button_compare = new QPushButton(Solution_show);
        button_compare->setObjectName(QStringLiteral("button_compare"));
        button_compare->setGeometry(QRect(150, 570, 89, 31));
        button_save = new QPushButton(Solution_show);
        button_save->setObjectName(QStringLiteral("button_save"));
        button_save->setGeometry(QRect(290, 570, 89, 31));
        button_OK = new QPushButton(Solution_show);
        button_OK->setObjectName(QStringLiteral("button_OK"));
        button_OK->setGeometry(QRect(430, 570, 89, 31));
        gridLayoutWidget = new QWidget(Solution_show);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 50, 631, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_Solution = new QTextBrowser(gridLayoutWidget);
        textBrowser_Solution->setObjectName(QStringLiteral("textBrowser_Solution"));

        gridLayout->addWidget(textBrowser_Solution, 0, 0, 1, 1);


        retranslateUi(Solution_show);

        QMetaObject::connectSlotsByName(Solution_show);
    } // setupUi

    void retranslateUi(QDialog *Solution_show)
    {
        Solution_show->setWindowTitle(QApplication::translate("Solution_show", "\346\215\242\344\271\230\350\267\257\347\272\277", Q_NULLPTR));
        button_compare->setText(QApplication::translate("Solution_show", "comapre", Q_NULLPTR));
        button_save->setText(QApplication::translate("Solution_show", "save", Q_NULLPTR));
        button_OK->setText(QApplication::translate("Solution_show", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Solution_show: public Ui_Solution_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTION_SHOW_H
