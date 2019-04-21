#include "missionitem.h"

#include <QMap>

class MissionItemPrivate
{
public:
    MissionItemPrivate();
    ~MissionItemPrivate();

    bool loadFromJson(const QString &filePath);
    bool saveToJson(const QString &filePath, MissionItem::FileFormat format) const;

    QMap<int, VisualItem *> items;
};

MissionItemPrivate::MissionItemPrivate()
{
}

MissionItemPrivate::~MissionItemPrivate()
{
    for (auto it = items.begin(); it != items.end(); it++)
        delete it.value();
}

bool MissionItemPrivate::loadFromJson(const QString &filePath)
{
    return false;
}

bool MissionItemPrivate::saveToJson(const QString &filePath, MissionItem::FileFormat format) const
{
    return false;
}

MissionItem::MissionItem(QObject *parent)
    : QObject(parent)
    , d(new MissionItemPrivate)
{
}

MissionItem::~MissionItem()
{
    delete d;
}

bool MissionItem::save(const QString &filePath, FileFormat format) const
{
    return d->saveToJson(filePath, format);
}

bool MissionItem::load(const QString &filePath) const
{
    return d->loadFromJson(filePath);
}
