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
    void loadFromSimpleItem(QJsonObject &object);
    void loadFromSurveyItem(QJsonObject &object);

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
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)) {
        qCWarning(missionItem) << QString("file open failed!").arg(filePath);
        return false;
    }

    QByteArray fileContent = file.readAll();
    file.close();

    QJsonDocument json = QJsonDocument::fromBinaryData(fileContent);
    if (json.isNull())
        json = QJsonDocument::fromJson(fileContent);
    if (!json.isObject())
        return false;

    QJsonObject jsonTopObject = json.object();
    QJsonArray itemsArray = jsonTopObject["Items"].toArray();
    for (int i = 0; i < itemsArray.size(); i++) {
        QJsonObject itemObject = itemsArray[i].toObject();
        if (itemObject["Type"].toString() == QString("Simple"))
            loadFromSimpleItem(itemObject);
        else
            loadFromSurveyItem(itemObject);
    }

    return true;
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
    jsonObject["Items"] = itemsArray;

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
    object["Type"] = "Simple";
    object["Sequence"] = item->sequence();

    QJsonArray paramsArray;
    paramsArray.append(simpleItem->longitude());
    paramsArray.append(simpleItem->latitude());
    paramsArray.append(simpleItem->altitude());
    paramsArray.append(simpleItem->speed());
    paramsArray.append(simpleItem->radius());
    paramsArray.append(simpleItem->flag());

    object["Params"] = paramsArray;
}

void MissionItemPrivate::saveToSurveyItem(QJsonObject &object, VisualItem *item)
{
    SurveyItem *surveyItem = qobject_cast<SurveyItem *>(item);
    object["Type"] = "Survey";
    object["Sequence"] = item->sequence();

    QJsonObject cameraObject;
    cameraObject["CameraName"] = surveyItem->cameraName();
    cameraObject["ImageWidth"] = surveyItem->imageWidth();
    cameraObject["ImageHeight"] = surveyItem->imageHeight();
    cameraObject["ImageDensity"] = surveyItem->imageDensity();

    QJsonObject paramsObject;

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

    paramsObject["Num"] = lists.size();
    paramsObject["Params"] = itemArray;
    object["Camera"] = cameraObject;
    object["items"] = paramsObject;
}

void MissionItemPrivate::loadFromSimpleItem(QJsonObject &object)
{
    SimpleItem *item = new SimpleItem;
    item->setSequence(object["Sequence"].toInt());
    QJsonArray paramsArray = object["Params"].toArray();
    item->setLatitude(paramsArray[0].toDouble());
    item->setLongitude(paramsArray[1].toDouble());
    item->setLatitude(paramsArray[2].toDouble());
    item->setSpeed(paramsArray[3].toDouble());
    item->setRadius(paramsArray[4].toInt());
    item->setFlag(paramsArray[5].toInt());
    itemsData.append(item);
}

void MissionItemPrivate::loadFromSurveyItem(QJsonObject &object)
{
    SurveyItem *surveyItem = new SurveyItem;
    surveyItem->setSequence(object["Sequence"].toInt());
    // just set some camera params
    QJsonObject cameraObject = object["Camera"].toObject();
    surveyItem->setCameraName(cameraObject["CameraName"].toString());
    surveyItem->setImageDensity(cameraObject["ImageDensity"].toDouble());
    surveyItem->setImageHeight(cameraObject["ImageHeight"].toInt());
    surveyItem->setImageWidth(cameraObject["ImageWidth"].toInt());

    QJsonObject itemsObject = object["items"].toObject();
    QJsonArray paramsArray = itemsObject["Params"].toArray();
    for (int i = 0; i < paramsArray.size(); i++) {
        QJsonArray paramArray = paramsArray[i].toArray();
        SimpleItem *simpleItem = new SimpleItem;
        simpleItem->setLatitude(paramArray[0].toDouble());
        simpleItem->setLongitude(paramArray[1].toDouble());
        simpleItem->setLatitude(paramArray[2].toDouble());
        simpleItem->setSpeed(paramArray[3].toDouble());
        simpleItem->setRadius(paramArray[4].toInt());
        simpleItem->setFlag(paramArray[5].toInt());
        surveyItem->appendItem(simpleItem);
    }
    itemsData.append(surveyItem);
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

void MissionItem::clearItemsData()
{
    if (d->itemsData.isEmpty())
        return;

    d->itemsData.clear();
}

QVector<VisualItem *> MissionItem::itemsData() const
{
    return d->itemsData;
}

void MissionItem::setItemsData(const QVector<VisualItem *> &data)
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
