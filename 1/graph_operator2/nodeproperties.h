#ifndef NODEPROPERTIES_H
#define NODEPROPERTIES_H

#include <QHash>
#include <QWidget>

#include "relarankgraph/nodehandle.h"
#include "relarankgraph/plughandle.h"

class QGridLayout;
class QLineEdit;
class QPushButton;

class Collapsible;
class NodeCtrl;
class PlugRow;

class NodeProperties: public QWidget
{
    Q_OBJECT
    friend class PlugRow;

public:			// methods

    explicit NodeProperties(NodeCtrl * node, Collapsible * parent);

private:			// for friend

    NodeCtrl * getNode() const
    {
        return m_node;
    }

    QGridLayout *getPlugLayout() const
    {
        return m_plugLayout;
    }

    void removePlugRow(const QString & plugName);

private slots:
    void renameNode();

    void createNewPlug();

    void addPlugRow(relarank::PlugHandle plug);

private:			// members

    NodeCtrl * m_node;

    QLineEdit *m_nameEdit;

    QGridLayout *m_plugLayout;

    QPushButton *m_addPlugButton;

    QHash < QString, PlugRow * >m_plugRows;

    bool m_nextPlugIsIncoming;

private:			// static members

    static QString s_defaultPlugName;

};

class PlugRow: public QObject
{
    Q_OBJECT
public:		// methods

    PlugRow(NodeProperties * editor, relarank::PlugHandle plug,
            QLineEdit * nameEdit, QPushButton * directionToggle,
            QPushButton * removalButton);

private slots:
    void renamePlug();

    void togglePlugDirection();

    void removePlug();

private:			// methods

    void updateDirectionIcon();

private:			// members

    NodeProperties * m_editor;

    relarank::PlugHandle m_plug;

    QLineEdit *m_nameEdit;

    QPushButton *m_directionToggle;

    QPushButton *m_removalButton;
};

#endif // NODEPROPERTIES_H
