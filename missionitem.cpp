#include "missionitem.h"

#include <QFile>
#include <QVector>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(missionItem, "WayRouteLoader.MissionItem")

class MissionItemPrivate
{
public:
    MissionItemPrivate();
    ~MissionItemPrivate();

    bool loadFromJson(const QString &filePath);
    bool saveToJson(const QString &filePath, MissionItem::FileFormat format);
    void saveToSimpleItem(QJsonObject &object, VisualItem *item);
    void saveToSurveyItem(QJsonObject &object, VisualItem *item);

    QVector<VisualItem *> itemsData;
};

MissionItemPrivate::MissionItemPrivate()
{
}

MissionItemPrivate::~MissionItemPrivate()
{
}

bool MissionItemPrivate::loadFromJson(const QString &filePath)
{
    return false;
}

bool MissionItemPrivate::saveToJson(const QString &filePath, MissionItem::FileFormat format)
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly))
        return false;

    QByteArray fileContent;
    QJsonObject jsonObject;
    QJsonArray itemsArray;

    for (auto it = itemsData.begin(); it != itemsData.end(); it++) {
        QJsonObject itemObject;
        if ((*it)->type() == QString("SimpleItem"))
            saveToSimpleItem(itemObject, *it);
        else
            saveToSurveyItem(itemObject, *it);

        itemsArray.append(itemObject);
    }
    jsonObject["items"] = itemsArray;

    QJsonDocument json(jsonObject);
    if (format == MissionItem::BinaryFileFormat)
        fileContent = json.toBinaryData();
    else
        fileContent = json.toJson();
    file.write(fileContent);
    file.close();
    return !fileContent.isEmpty();
}

void MissionItemPrivate::saveToSimpleItem(QJsonObject &object, VisualItem *item)
{
    SimpleItem *simpleItem = qobject_cast<SimpleItem *>(item);
    object["type"] = "Simple";
    object["sequence"] = item->sequence();

    QJsonArray paramsArray;
    paramsArray.append(simpleItem->longitude());
    paramsArray.append(simpleItem->latitude());
    paramsArray.append(simpleItem->altitude());
    paramsArray.append(simpleItem->speed());
    paramsArray.append(simpleItem->radius());
    paramsArray.append(simpleItem->flag());

    object["params"] = paramsArray;
}

void MissionItemPrivate::saveToSurveyItem(QJsonObject &object, VisualItem *item)
{
    SurveyItem *surveyItem = qobject_cast<SurveyItem *>(item);
    object["type"] = "Survey";
    object["sequence"] = item->sequence();

    QJsonObject cameraObject;
    cameraObject["CameraName:"] = surveyItem->cameraName();
    cameraObject["ImageWidth:"] = surveyItem->imageWidth();
    cameraObject["ImageHeight:"] = surveyItem->imageHeight();
    cameraObject["ImageDensity"] = surveyItem->imageDensity();

    QJsonArray itemArray;
    auto lists = surveyItem->items();

    for (auto it = lists.begin(); it != lists.end(); it++) {
        QJsonArray paramsArray;
        paramsArray.append((*it)->longitude());
        paramsArray.append((*it)->latitude());
        paramsArray.append((*it)->altitude());
        paramsArray.append((*it)->speed());
        paramsArray.append((*it)->radius());
        paramsArray.append((*it)->flag());
        itemArray.append(paramsArray);
    }

    object["Camera"] = cameraObject;
    object["Items"] = itemArray;
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

QVector<VisualItem *> MissionItem::itemsData() const
{
    return d->itemsData;
}

void MissionItem::setItemsData(const QVector<VisualItem *> data)
{
    if (!d->itemsData.isEmpty())
        d->itemsData.clear();

    d->itemsData = data;
}

bool MissionItem::save(const QString &filePath, FileFormat format) const
{
    return d->saveToJson(filePath, format);
}

bool MissionItem::load(const QString &filePath) const
{
    return d->loadFromJson(filePath);
}
