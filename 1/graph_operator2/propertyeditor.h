#ifndef NODEPROPERTYEDITOR_H
#define NODEPROPERTYEDITOR_H

#include <QScrollArea>
#include <QHash>

#include "relarankgraph/nodehandle.h"

class Collapsible;
class MainCtrl;
class QVBoxLayout;

class PropertyEditor: public QScrollArea
{
    Q_OBJECT
public:		// methods

    explicit PropertyEditor(QWidget * parent);

    void setMainCtrl(MainCtrl * mainCtrl)
    {
        Q_ASSERT(!m_mainCtrl);
        m_mainCtrl = mainCtrl;
    }

    void showNodes(const QList < relarank::NodeHandle > &selection);

private:			// members

    MainCtrl * m_mainCtrl;

    QVBoxLayout *m_layout;

    QHash < relarank::NodeHandle, Collapsible * >m_nodes;
};

#endif // NODEPROPERTYEDITOR_H
