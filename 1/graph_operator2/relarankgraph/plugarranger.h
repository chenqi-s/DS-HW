#ifndef ZODIAC_PLUGARRANGER_H
#define ZODIAC_PLUGARRANGER_H

#include <QVector>

namespace relarank
{

QVector < int >arrangePlugs(const QVector < qreal > &costTable,
                            const int rowCount, const int columnCount);

}				// namespace relarank

#endif				// ZODIAC_PLUGARRANGER_H
