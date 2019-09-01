#ifndef NODECTRL_H
#define NODECTRL_H

#include <QObject>
#include <QHash>

#include "relarankgraph/nodehandle.h"
#include "relarankgraph/plughandle.h"

class MainCtrl;

class NodeCtrl: public QObject
{
    Q_OBJECT
public:		// methods

    explicit NodeCtrl(MainCtrl * manager, relarank::NodeHandle node);

    inline QString getName() const
    {
        return m_node.getName();
    }

    void rename(const QString & name);

    inline relarank::NodeHandle getNodeHandle() const
    {
        return m_node;
    }

    inline QList < relarank::PlugHandle > getPlugHandles() const
    {
        return m_node.getPlugs();
    }

    inline bool isRemovable() const
    {
        return m_node.isRemovable();
    }

    inline relarank::PlugHandle addIncomingPlug(const QString & name)
    {
        return addPlug(name, true);
    }

    inline relarank::PlugHandle addOutgoingPlug(const QString & name)
    {
        return addPlug(name, false);
    }

    QString renamePlug(const QString & oldName, const QString & newName);

    bool togglePlugDirection(const QString & name);

    bool removePlug(const QString & name);

    void setSelected(bool isSelected);

public slots:
    bool remove();

private:			// methods

    relarank::PlugHandle addPlug(const QString & name, bool incoming);

private slots:
    void inputConnected(relarank::PlugHandle myInput,
                        relarank::PlugHandle otherOutput);

    void outputConnected(relarank::PlugHandle myOutput,
                         relarank::PlugHandle otherInput);

    void inputDisconnected(relarank::PlugHandle myInput,
                           relarank::PlugHandle otherOutput);

    void outputDisconnected(relarank::PlugHandle myOutput,
                            relarank::PlugHandle otherInput);

private:			// members

    MainCtrl * m_manager;

    relarank::NodeHandle m_node;

    QHash < relarank::PlugHandle, QList < relarank::PlugHandle >> m_plugs;
};

#endif // NODECTRL_H
