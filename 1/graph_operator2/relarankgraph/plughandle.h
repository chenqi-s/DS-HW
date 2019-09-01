#ifndef ZODIAC_PLUGHANDLE_H
#define ZODIAC_PLUGHANDLE_H

#include <QObject>
#include <QHash>

namespace relarank
{

class NodeHandle;
class Plug;
class SceneHandle;

class PlugHandle: public QObject
{

    Q_OBJECT
public:		// methods

    explicit PlugHandle(Plug * plug = nullptr);

    PlugHandle(const PlugHandle & other): PlugHandle(other.data())
    {
    }

    PlugHandle & operator = (const PlugHandle & other);

    bool operator == (const PlugHandle & other) const
    {
        return other.data() == data();
    }

    inline Plug *data() const
    {
        return m_plug;
    }

    inline bool isValid() const
    {
        return m_isValid;
    }

    bool isRemovable() const;

    bool remove();

    QString getName() const;

    bool toggleDirection();

    bool isIncoming() const;

    bool isOutgoing() const;

    int connectionCount() const;

    QList < PlugHandle > getConnectedPlugs() const;

    bool connectPlug(PlugHandle other);

    bool disconnectPlug(PlugHandle other);

    void disconnectAll();

    NodeHandle getNode() const;

    SceneHandle getScene() const;

public slots:
    QString rename(const QString & name);

signals:
    void plugRenamed(const QString & name);

private:			// methods

    void connectSignals();

private slots:
    void plugWasDestroyed();

private:			// member

    Plug * m_plug;

    bool m_isValid;

};

}				// namespace relarank

inline uint
qHash(const relarank::PlugHandle & key)
{
    return qHash(size_t (key.data()));
}

#endif // ZODIAC_PLUGHANDLE_H
