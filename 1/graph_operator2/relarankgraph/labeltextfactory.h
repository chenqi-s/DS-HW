#ifndef ZODIAC_LABELTEXTFACTORY_H
#define ZODIAC_LABELTEXTFACTORY_H

#include <QSet>
#include <QString>

namespace relarank
{

class PlugEdge;

class LabelTextFactory
{

public:			// methods

    explicit LabelTextFactory(const QSet < PlugEdge * >&edges);

    explicit LabelTextFactory(PlugEdge * edge);

    QString produceLabel(int maxNameLength = 0) const;

    int getLabelCount() const
    {
        return m_labelCount;
    }

    int getMaxNameLength() const
    {
        return m_maxNameLength;
    }

public:			// static methods

    static const QString & getNewlineChar()
    {
        return s_newlineChar;
    }

    static QString getHorizontalLine(int maxNameLength);

private:			// members

    QList < QPair < QString, QString >> m_namePairs;

    int m_labelCount;

    int m_maxNameLength;

private:			// static members

    static const QString s_arrowChar;

    static const QString s_dotChar;

    static const QString s_whitespaceChar;

    static const QString s_newlineChar;

    static const QString s_horizontalLineChar;

};

}				// namespace relarank

#endif // ZODIAC_LABELTEXTFACTORY_H
