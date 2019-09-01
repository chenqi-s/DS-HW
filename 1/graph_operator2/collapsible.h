#ifndef COLLAPSIBLE_H
#define COLLAPSIBLE_H

#include <QFrame>

class QPushButton;
class QVBoxLayout;

class Collapsible: public QFrame
{
    Q_OBJECT
public:		// methods

    Collapsible(QWidget * parent);

    void setWidget(QWidget * displayWidget);

public slots:
    void updateTitle(const QString & title = 0);

public:			// static methods

    static int getMaximumWidth()
    {
        return s_maxWidth;
    }

private slots:
    void toggleCollapse();

private:			// members

    QVBoxLayout * m_mainLayout;

    QWidget *m_displayWidget;

    QPushButton *m_titleButton;

    QString m_title;

private:			// static members

    static const QString s_downArrow;

    static const QString s_upArrow;

    static const int s_maxWidth;
};

#endif // COLLAPSIBLE_H
