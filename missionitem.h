#ifndef MISSIONITEM_H
#define MISSIONITEM_H

#include "visualitem.h"
#include "simpleitem.h"
#include "surveyitem.h"

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

    QVector<VisualItem *> itemsData() const;
    void setItemsData(const QVector<VisualItem *> data);

    bool save(const QString &filePath, FileFormat format = TextFileFormat) const;
    bool load(const QString &filePath) const;

private:
    MissionItemPrivate *d;
};

#endif // MISSIONITEM_H
