/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *toolEnlarge;
    QAction *action;
    QAction *actionTransfer;
    QAction *actionQueryInfo;
    QAction *actionAddAll;
    QAction *actionAddLine;
    QAction *actionAddStation;
    QAction *actionAddConnect;
    QAction *actiontoolBar;
    QAction *actionstatusBar;
    QAction *actionLineMap;
    QAction *actionWheel;
    QAction *actionAuthor;
    QAction *actionuseHelp;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QSlider *verticalSlider;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout4_4;
    QLabel *labelTransfer;
    QHBoxLayout *horizontalLayout4;
    QLabel *labelStart;
    QComboBox *comboBoxStartLine;
    QComboBox *comboBoxStartStation;
    QHBoxLayout *horizontalLayout5;
    QLabel *labelDestination;
    QComboBox *comboBoxDstLine;
    QComboBox *comboBoxDstStation;
    QHBoxLayout *horizontalLayout6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonMinTransfer;
    QRadioButton *radioButtonMinTime;
    QRadioButton *radioButtonMinStation;
    QPushButton *pushButtonTransfer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuWatch;
    QMenu *menu_H;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1030, 680);
        MainWindow->setMinimumSize(QSize(1030, 680));
        MainWindow->setMaximumSize(QSize(1030, 693));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(243, 243, 243, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/metro-shanghai.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolTipDuration(-1);
        MainWindow->setIconSize(QSize(24, 24));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose->setCheckable(true);
        actionClose->setFont(font);
        toolEnlarge = new QAction(MainWindow);
        toolEnlarge->setObjectName(QStringLiteral("toolEnlarge"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/icon/enlarge.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolEnlarge->setIcon(icon1);
        toolEnlarge->setFont(font);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/icon/shrink.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon2);
        action->setFont(font);
        actionTransfer = new QAction(MainWindow);
        actionTransfer->setObjectName(QStringLiteral("actionTransfer"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/icon/query.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTransfer->setIcon(icon3);
        actionTransfer->setFont(font);
        actionQueryInfo = new QAction(MainWindow);
        actionQueryInfo->setObjectName(QStringLiteral("actionQueryInfo"));
        actionQueryInfo->setFont(font);
        actionAddAll = new QAction(MainWindow);
        actionAddAll->setObjectName(QStringLiteral("actionAddAll"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/icon/all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddAll->setIcon(icon4);
        actionAddAll->setFont(font);
        actionAddLine = new QAction(MainWindow);
        actionAddLine->setObjectName(QStringLiteral("actionAddLine"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/icon/subway.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddLine->setIcon(icon5);
        actionAddLine->setFont(font);
        actionAddStation = new QAction(MainWindow);
        actionAddStation->setObjectName(QStringLiteral("actionAddStation"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/icon/station.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddStation->setIcon(icon6);
        actionAddStation->setFont(font);
        actionAddConnect = new QAction(MainWindow);
        actionAddConnect->setObjectName(QStringLiteral("actionAddConnect"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/icon/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddConnect->setIcon(icon7);
        actionAddConnect->setFont(font);
        actiontoolBar = new QAction(MainWindow);
        actiontoolBar->setObjectName(QStringLiteral("actiontoolBar"));
        actiontoolBar->setCheckable(true);
        actiontoolBar->setChecked(true);
        actiontoolBar->setFont(font);
        actionstatusBar = new QAction(MainWindow);
        actionstatusBar->setObjectName(QStringLiteral("actionstatusBar"));
        actionstatusBar->setCheckable(true);
        actionstatusBar->setChecked(true);
        actionstatusBar->setFont(font);
        actionLineMap = new QAction(MainWindow);
        actionLineMap->setObjectName(QStringLiteral("actionLineMap"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/icon/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLineMap->setIcon(icon8);
        actionLineMap->setFont(font);
        actionWheel = new QAction(MainWindow);
        actionWheel->setObjectName(QStringLiteral("actionWheel"));
        actionWheel->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/icon/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWheel->setIcon(icon9);
        actionWheel->setFont(font);
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QStringLiteral("actionAuthor"));
        actionAuthor->setIcon(icon);
        actionuseHelp = new QAction(MainWindow);
        actionuseHelp->setObjectName(QStringLiteral("actionuseHelp"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/icon/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionuseHelp->setIcon(icon10);
        actionuseHelp->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1030, 600));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 621, 591));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(480, 50, 141, 481));
        verticalSlider->setMouseTracking(false);
        verticalSlider->setMinimum(0);
        verticalSlider->setMaximum(200);
        verticalSlider->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(650, 180, 361, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout4_4 = new QHBoxLayout();
        horizontalLayout4_4->setSpacing(10);
        horizontalLayout4_4->setObjectName(QStringLiteral("horizontalLayout4_4"));

        verticalLayout_2->addLayout(horizontalLayout4_4);

        labelTransfer = new QLabel(layoutWidget);
        labelTransfer->setObjectName(QStringLiteral("labelTransfer"));
        labelTransfer->setEnabled(true);
        labelTransfer->setMinimumSize(QSize(280, 20));
        labelTransfer->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        labelTransfer->setFont(font1);

        verticalLayout_2->addWidget(labelTransfer);

        horizontalLayout4 = new QHBoxLayout();
        horizontalLayout4->setSpacing(10);
        horizontalLayout4->setObjectName(QStringLiteral("horizontalLayout4"));
        labelStart = new QLabel(layoutWidget);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setMinimumSize(QSize(70, 20));
        labelStart->setFont(font);

        horizontalLayout4->addWidget(labelStart);

        comboBoxStartLine = new QComboBox(layoutWidget);
        comboBoxStartLine->setObjectName(QStringLiteral("comboBoxStartLine"));
        comboBoxStartLine->setMinimumSize(QSize(90, 20));
        comboBoxStartLine->setFont(font);

        horizontalLayout4->addWidget(comboBoxStartLine);

        comboBoxStartStation = new QComboBox(layoutWidget);
        comboBoxStartStation->setObjectName(QStringLiteral("comboBoxStartStation"));
        comboBoxStartStation->setMinimumSize(QSize(90, 20));
        comboBoxStartStation->setFont(font);

        horizontalLayout4->addWidget(comboBoxStartStation);

        horizontalLayout4->setStretch(0, 7);
        horizontalLayout4->setStretch(1, 9);
        horizontalLayout4->setStretch(2, 9);

        verticalLayout_2->addLayout(horizontalLayout4);

        horizontalLayout5 = new QHBoxLayout();
        horizontalLayout5->setSpacing(10);
        horizontalLayout5->setObjectName(QStringLiteral("horizontalLayout5"));
        labelDestination = new QLabel(layoutWidget);
        labelDestination->setObjectName(QStringLiteral("labelDestination"));
        labelDestination->setMinimumSize(QSize(70, 20));
        labelDestination->setFont(font);

        horizontalLayout5->addWidget(labelDestination);

        comboBoxDstLine = new QComboBox(layoutWidget);
        comboBoxDstLine->setObjectName(QStringLiteral("comboBoxDstLine"));
        comboBoxDstLine->setMinimumSize(QSize(90, 20));
        comboBoxDstLine->setFont(font);

        horizontalLayout5->addWidget(comboBoxDstLine);

        comboBoxDstStation = new QComboBox(layoutWidget);
        comboBoxDstStation->setObjectName(QStringLiteral("comboBoxDstStation"));
        comboBoxDstStation->setMinimumSize(QSize(90, 20));
        comboBoxDstStation->setFont(font);

        horizontalLayout5->addWidget(comboBoxDstStation);

        horizontalLayout5->setStretch(0, 7);
        horizontalLayout5->setStretch(1, 9);
        horizontalLayout5->setStretch(2, 9);

        verticalLayout_2->addLayout(horizontalLayout5);

        horizontalLayout6 = new QHBoxLayout();
        horizontalLayout6->setSpacing(10);
        horizontalLayout6->setObjectName(QStringLiteral("horizontalLayout6"));
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(190, 30));
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonMinTransfer = new QRadioButton(groupBox);
        radioButtonMinTransfer->setObjectName(QStringLiteral("radioButtonMinTransfer"));
        radioButtonMinTransfer->setMinimumSize(QSize(100, 15));
        radioButtonMinTransfer->setFont(font);
        radioButtonMinTransfer->setChecked(true);

        verticalLayout->addWidget(radioButtonMinTransfer);

        radioButtonMinTime = new QRadioButton(groupBox);
        radioButtonMinTime->setObjectName(QStringLiteral("radioButtonMinTime"));
        radioButtonMinTime->setMinimumSize(QSize(100, 15));
        radioButtonMinTime->setFont(font);
        radioButtonMinTime->setChecked(false);

        verticalLayout->addWidget(radioButtonMinTime);

        radioButtonMinStation = new QRadioButton(groupBox);
        radioButtonMinStation->setObjectName(QStringLiteral("radioButtonMinStation"));
        radioButtonMinStation->setMinimumSize(QSize(100, 15));
        radioButtonMinStation->setFont(font);

        verticalLayout->addWidget(radioButtonMinStation);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout6->addWidget(groupBox);

        pushButtonTransfer = new QPushButton(layoutWidget);
        pushButtonTransfer->setObjectName(QStringLiteral("pushButtonTransfer"));
        pushButtonTransfer->setMinimumSize(QSize(70, 30));
        pushButtonTransfer->setFont(font);

        horizontalLayout6->addWidget(pushButtonTransfer);


        verticalLayout_2->addLayout(horizontalLayout6);

        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 2);
        verticalLayout_2->setStretch(3, 2);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(3, 26));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(211, 215, 207, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        statusBar->setPalette(palette1);
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 28));
        menuBar->setMinimumSize(QSize(0, 25));
        menuWatch = new QMenu(menuBar);
        menuWatch->setObjectName(QStringLiteral("menuWatch"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        labelStart->setBuddy(comboBoxStartLine);
        labelDestination->setBuddy(comboBoxDstLine);
#endif // QT_NO_SHORTCUT

        mainToolBar->addAction(actionAddAll);
        mainToolBar->addAction(actionAddLine);
        mainToolBar->addAction(actionAddStation);
        mainToolBar->addAction(actionAddConnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLineMap);
        menuBar->addAction(menuWatch->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuWatch->addAction(actiontoolBar);
        menuWatch->addAction(actionstatusBar);
        menu_H->addAction(actionuseHelp);
        menu_H->addAction(actionAuthor);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\234\260\351\223\201\346\215\242\344\271\230\346\214\207\345\215\227", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
        toolEnlarge->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolEnlarge->setToolTip(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\224\276\345\244\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolEnlarge->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "\347\202\271\345\207\273\347\274\251\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\214\207\345\215\227(\345\217\263\346\240\217)", Q_NULLPTR));
        actionQueryInfo->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\237\245\350\257\242(\351\242\204\347\225\231)", Q_NULLPTR));
        actionAddAll->setText(QApplication::translate("MainWindow", "\346\211\200\346\234\211(&A)", Q_NULLPTR));
        actionAddAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
        actionAddLine->setText(QApplication::translate("MainWindow", "\347\272\277\350\267\257(&L)", Q_NULLPTR));
        actionAddLine->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", Q_NULLPTR));
        actionAddStation->setText(QApplication::translate("MainWindow", "\347\253\231\347\202\271(&S)", Q_NULLPTR));
        actionAddStation->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
        actionAddConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245(&C)", Q_NULLPTR));
        actionAddConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", Q_NULLPTR));
        actiontoolBar->setText(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        actionstatusBar->setText(QApplication::translate("MainWindow", "statusBar", Q_NULLPTR));
        actionLineMap->setText(QApplication::translate("MainWindow", "\345\234\260\351\223\201\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLineMap->setToolTip(QApplication::translate("MainWindow", "\345\234\260\351\223\201\347\275\221\347\273\234\347\272\277\350\267\257\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionLineMap->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", Q_NULLPTR));
        actionWheel->setText(QApplication::translate("MainWindow", "\351\274\240\346\240\207\345\217\257\347\274\251\346\224\276", Q_NULLPTR));
        actionAuthor->setText(QApplication::translate("MainWindow", "\345\210\266\344\275\234\350\200\205", Q_NULLPTR));
        actionuseHelp->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\345\270\256\345\212\251", Q_NULLPTR));
        actionuseHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
        labelTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\214\207\345\215\227", Q_NULLPTR));
        labelStart->setText(QApplication::translate("MainWindow", "\350\265\267\347\202\271\347\253\231(&S)\357\274\232", Q_NULLPTR));
        comboBoxStartLine->clear();
        comboBoxStartLine->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxStartStation->clear();
        comboBoxStartStation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
        labelDestination->setText(QApplication::translate("MainWindow", "\347\273\210\347\202\271\347\253\231(&D)\357\274\232", Q_NULLPTR));
        comboBoxDstLine->clear();
        comboBoxDstLine->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\347\272\277", Q_NULLPTR)
        );
        comboBoxDstStation->clear();
        comboBoxDstStation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\253\231\347\202\271", Q_NULLPTR)
        );
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\215\242\344\271\230\347\255\226\347\225\245", Q_NULLPTR));
        radioButtonMinTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230\346\254\241\346\225\260\346\234\200\345\260\221", Q_NULLPTR));
        radioButtonMinTime->setText(QApplication::translate("MainWindow", "\346\211\200\351\234\200\346\227\266\351\227\264\346\234\200\347\237\255", Q_NULLPTR));
        radioButtonMinStation->setText(QApplication::translate("MainWindow", "\350\267\257\350\277\207\347\253\231\345\217\260\346\234\200\345\260\221", Q_NULLPTR));
        pushButtonTransfer->setText(QApplication::translate("MainWindow", "\346\215\242\344\271\230", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        menuWatch->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&W)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
