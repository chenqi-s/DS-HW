#ifndef ZODIAC_SCENEHANDLE_H
#define ZODIAC_SCENEHANDLE_H

#include <QObject>
#include <QHash>
#include <QUuid>

#include "nodehandle.h"

namespace relarank
{

class PlugHandle;
class Scene;

class SceneHandle: public QObject
{

    Q_OBJECT
public:		// methods

    explicit SceneHandle(Scene * scene = nullptr);

    SceneHandle(const SceneHandle & other): SceneHandle(other.data())
    {
    }

    SceneHandle & operator = (const SceneHandle & other);

    bool operator == (const SceneHandle & other) const
    {
        return other.data() == data();
    }

    inline Scene *data() const
    {
        return m_scene;
    }

    inline bool isValid() const
    {
        return m_isValid;
    }

    NodeHandle createNode(const QString & name, const QUuid & uuid =
                              QUuid());

    QList < NodeHandle > getNodes() const;

    void deselectAll() const;

signals:
    void selectionChanged(QList < relarank::NodeHandle >
                          selection);

private:			// methods

    void connectSignals();

private slots:
    void updateSelection();

    void sceneWasDestroyed();

private:			// member

    Scene * m_scene;

    bool m_isValid;
};

}				// namespace relarank

inline uint
qHash(const relarank::SceneHandle & key)
{
    return qHash(size_t (key.data()));
}

#endif // ZODIAC_SCENEHANDLE_H
