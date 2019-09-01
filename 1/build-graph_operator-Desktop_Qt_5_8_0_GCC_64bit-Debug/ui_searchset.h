/********************************************************************************
** Form generated from reading UI file 'searchset.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSET_H
#define UI_SEARCHSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Searchset
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Searchset)
    {
        if (Searchset->objectName().isEmpty())
            Searchset->setObjectName(QStringLiteral("Searchset"));
        Searchset->resize(400, 300);
        buttonBox = new QDialogButtonBox(Searchset);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Searchset);
        QObject::connect(buttonBox, SIGNAL(accepted()), Searchset, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Searchset, SLOT(reject()));

        QMetaObject::connectSlotsByName(Searchset);
    } // setupUi

    void retranslateUi(QDialog *Searchset)
    {
        Searchset->setWindowTitle(QApplication::translate("Searchset", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Searchset: public Ui_Searchset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSET_H
