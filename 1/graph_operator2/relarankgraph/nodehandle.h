#ifndef ZODIAC_NODEHANDLE_H
#define ZODIAC_NODEHANDLE_H

#include <QObject>
#include <QHash>

#include "plughandle.h"

namespace relarank
{

class Node;
class Plug;
class SceneHandle;

class NodeHandle: public QObject
{
    Q_OBJECT
public:		// methods

    explicit NodeHandle(Node * node = nullptr);

    NodeHandle(const NodeHandle & other): NodeHandle(other.data())
    {
    }

    NodeHandle & operator = (const NodeHandle & other);

    bool operator == (const NodeHandle & other) const
    {
        return other.data() == data();
    }

    inline Node *data() const
    {
        return m_node;
    }

    inline bool isValid() const
    {
        return m_isValid;
    }

    bool isRemovable() const;

    bool remove();

    const QUuid & getId() const;

    QString getName() const;

    void rename(const QString & name);

    PlugHandle createIncomingPlug(const QString & name);

    PlugHandle createOutgoingPlug(const QString & name);

    QList < PlugHandle > getPlugs() const;

    PlugHandle getPlug(const QString & name) const;

    void setSelected(bool isSelected);

    SceneHandle getScene() const;

    QPointF getPos() const;

    void setPos(qreal x, qreal y);

signals:
    void nodeActivated();

    void nodeRenamed(const QString & name);

    void removalRequested();

    void inputConnected(relarank::PlugHandle myInput,
                        relarank::PlugHandle otherOutput);

    void outputConnected(relarank::PlugHandle myOutput,
                         relarank::PlugHandle otherInput);

    void inputDisconnected(relarank::PlugHandle myInput,
                           relarank::PlugHandle otherOutput);

    void outputDisconnected(relarank::PlugHandle myOutput,
                            relarank::PlugHandle otherInput);

private:			// methods

    void connectSignals();

private slots:
    void passInputConnected(Plug * myInput,
                            Plug * otherOutput);

    void passOutputConnected(Plug * myOutput, Plug * otherInput);

    void passInputDisconnected(Plug * myInput, Plug * otherOutput);

    void passOutputDisconnected(Plug * myOutput, Plug * otherInput);

    void nodeWasDestroyed();

private:			// member

    Node * m_node;

    bool m_isValid;

};

}				// namespace relarank

inline uint
qHash(const relarank::NodeHandle & key)
{
    return qHash(size_t (key.data()));
}

#endif // ZODIAC_NODEHANDLE_H
