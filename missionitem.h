#ifndef MISSIONITEM_H
#define MISSIONITEM_H

#include "simpleitem.h"

#include <QObject>
#include <QScopedPointer>

class MissionItemPrivate;
class MissionItem : public QObject
{
    Q_OBJECT
public:
    enum FileFormat { BinaryFileFormat, TextFileFormat };
    explicit MissionItem(QObject *parent = nullptr);
    ~MissionItem();

    bool save(const QString &filePath, FileFormat format = TextFileFormat) const;
    bool load(const QString &filePath) const;

private:
    MissionItemPrivate *d;
};

#endif // MISSIONITEM_H
