#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include <QObject>
#include <QHash>

#include "relarankgraph/nodehandle.h"
#include "relarankgraph/scenehandle.h"

class NodeCtrl;
class PropertyEditor;
namespace relarank
{
class Scene;
}

class MainCtrl: public QObject
{
    Q_OBJECT
public:		// methods

    explicit MainCtrl(QObject * parent, relarank::Scene * scene,
                      PropertyEditor * propertyEditor);

    NodeCtrl *createNode(const QString & name = "");

    bool deleteNode(NodeCtrl * node);

    inline NodeCtrl *getCtrlForHandle(relarank::NodeHandle handle) const
    {
        return m_nodes.value(handle, nullptr);
    }

    void printZodiacScene();

    bool shutdown();

public slots:
    void createDefaultNode();

private slots:
    void selectionChanged(QList < relarank::NodeHandle >
                          selection);

private:			// members

    relarank::SceneHandle m_scene;

    PropertyEditor *m_propertyEditor;

    QHash < relarank::NodeHandle, NodeCtrl * >m_nodes;

    uint m_nodeIndex;

private:			// static members

    static QString s_defaultName;

};

#endif // NODEMANAGER_H
