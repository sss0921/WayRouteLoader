#include "surveyitem.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(surveyItem, "WayRouteLoader.SurveyItem")

class SurveyItemPrivate
{
public:
    SurveyItemPrivate();
    ~SurveyItemPrivate();

    int sequence;
    double adjustedFootprintFrontal;
    double adjustedFootprintSide;
    QString cameraName;
    int distanceToSurface;
    bool distanceToSurfaceRelative;
    bool fixedOrientation;
    double focalLength;
    int frontalOverlap;
    double imageDensity;
    int imageWidth;
    int imageHeight;
    bool landscape;
    int minTriggerInteral;
    double sensorWidth;
    double sensorHeight;
    int sideOverlap;
    bool valueSetIsDistance;

    QVector<QGeoCoordinate> items;
};

SurveyItemPrivate::SurveyItemPrivate()
    : adjustedFootprintFrontal(0.0)
    , adjustedFootprintSide(0.0)
    , cameraName(QString())
    , distanceToSurface(0)
    , distanceToSurfaceRelative(false)
    , fixedOrientation(false)
    , focalLength(0.0)
    , frontalOverlap(0)
    , imageDensity(0.0)
    , imageWidth(0)
    , imageHeight(0)
    , landscape(false)
    , minTriggerInteral(0)
    , sensorWidth(0.0)
    , sensorHeight(0.0)
    , sideOverlap(0)
    , valueSetIsDistance(false)
    , items(QVector<QGeoCoordinate>())
{
}

SurveyItemPrivate::~SurveyItemPrivate()
{
}

SurveyItem::SurveyItem(QObject *parent)
    : VisualItem(parent)
{
    qCWarning(surveyItem) << "SurveyItem";
}

SurveyItem::~SurveyItem()
{
    qCWarning(surveyItem) << "~SurveyItem";
}

QString SurveyItem::type() const
{
    return QString("SurveyItem");
}

int SurveyItem::sequence() const
{
    qCWarning(surveyItem) << "sequence";
    return d->sequence;
}

void SurveyItem::setSequence(int sequence)
{
    qCWarning(surveyItem) << "setSequence:" << sequence;
    if (d->sequence == sequence)
        return;

    d->sequence = sequence;
}

double SurveyItem::adjustedFootprintFrontal() const
{
    qCWarning(surveyItem) << "adjustedFootprintFrontal";
    return d->adjustedFootprintFrontal;
}

void SurveyItem::setAdjustedFootprintFrontal(double adjustedFootprintFrontal)
{
    qCWarning(surveyItem) << "setAdjustedFootprintFrontal:" << adjustedFootprintFrontal;
    if (qFuzzyCompare(d->adjustedFootprintFrontal, adjustedFootprintFrontal))
        return;

    d->adjustedFootprintFrontal = adjustedFootprintFrontal;
}

double SurveyItem::adjustedFootprintSide() const
{
    qCWarning(surveyItem) << "adjustedFootprintSide";
    return d->adjustedFootprintSide;
}

void SurveyItem::setAdjustedFootprintSide(double adjustedFootprintSide)
{
    qCWarning(surveyItem) << "setAdjustedFootprintSide:" << adjustedFootprintSide;
    if (qFuzzyCompare(d->adjustedFootprintSide, adjustedFootprintSide))
        return;

    d->adjustedFootprintSide = adjustedFootprintSide;
}

QString SurveyItem::cameraName() const
{
    qCWarning(surveyItem) << "cameraName";
    return d->cameraName;
}

void SurveyItem::setCameraName(const QString &cameraName)
{
    qCWarning(surveyItem) << "setCameraName:" << cameraName;
    if (d->cameraName == cameraName)
        return;

    d->cameraName = cameraName;
}

int SurveyItem::distanceToSurface() const
{
    qCWarning(surveyItem) << "distanceToSurface";
    return d->distanceToSurface;
}

void SurveyItem::setDistanceToSurface(int distanceToSurface)
{
    qCWarning(surveyItem) << "setDistanceToSurface:" << distanceToSurface;
    if (d->distanceToSurface == distanceToSurface)
        return;

    d->distanceToSurface = distanceToSurface;
}

bool SurveyItem::distanceToSurfaceRelative() const
{
    qCWarning(surveyItem) << "distanceToSurfaceRelative";
    return d->distanceToSurfaceRelative;
}

void SurveyItem::setDistanceToSurfaceRelative(bool distanceToSurfaceRelative)
{
    qCWarning(surveyItem) << "setDistanceToSurfaceRelative:" << distanceToSurfaceRelative;
    if (d->distanceToSurfaceRelative == distanceToSurfaceRelative)
        return;

    d->distanceToSurfaceRelative = distanceToSurfaceRelative;
}

bool SurveyItem::fixedOrientation() const
{
    qCWarning(surveyItem) << "fixedOrientation";
    return d->fixedOrientation;
}

void SurveyItem::setFixedOrientation(bool fixedOrientation)
{
    qCWarning(surveyItem) << "setFixedOrientation:" << fixedOrientation;
    if (d->fixedOrientation == fixedOrientation)
        return;

    d->fixedOrientation = fixedOrientation;
}

double SurveyItem::focalLength() const
{
    qCWarning(surveyItem) << "focalLength";
    return d->focalLength;
}

void SurveyItem::setFocalLength(double focalLength)
{
    qCWarning(surveyItem) << "setFocalLength:" << focalLength;
    if (qFuzzyCompare(d->focalLength, focalLength))
        return;

    d->focalLength = focalLength;
}

int SurveyItem::frontalOverlap() const
{
    qCWarning(surveyItem) << "frontalOverlap";
    return d->frontalOverlap;
}

void SurveyItem::setFrontalOverlap(int frontalOverlap)
{
    qCWarning(surveyItem) << "setFrontalOverlap:" << frontalOverlap;
    if (d->frontalOverlap == frontalOverlap)
        return;

    d->frontalOverlap = frontalOverlap;
}

double SurveyItem::imageDensity() const
{
    qCWarning(surveyItem) << "imageDensity";
    return d->imageDensity;
}

void SurveyItem::setImageDensity(double imageDensity)
{
    qCWarning(surveyItem) << "setImageDensity:" << imageDensity;
    if (qFuzzyCompare(d->imageDensity, imageDensity))
        return;

    d->imageDensity = imageDensity;
}

int SurveyItem::imageWidth() const
{
    qCWarning(surveyItem) << "imageWidth";
    return d->imageWidth;
}

void SurveyItem::setImageWidth(int imageWidth)
{
    qCWarning(surveyItem) << "setImageWidth" << imageWidth;
    if (d->imageWidth == imageWidth)
        return;

    d->imageWidth = imageWidth;
}

int SurveyItem::imageHeight() const
{
    qCWarning(surveyItem) << "imageHeight";
    return d->imageHeight;
}

void SurveyItem::setImageHeight(int imageHeight)
{
    qCWarning(surveyItem) << "setImageHeight:" << imageHeight;
    if (d->imageHeight == imageHeight)
        return;

    d->imageHeight = imageHeight;
}

bool SurveyItem::landscape() const
{
    qCWarning(surveyItem) << "landscape";
    return d->landscape;
}

void SurveyItem::setLandscape(bool landscape)
{
    qCWarning(surveyItem) << "setLandscape:" << landscape;
    if (d->landscape == landscape)
        return;

    d->landscape = landscape;
}

int SurveyItem::minTriggerInteral() const
{
    qCWarning(surveyItem) << "minTriggerInteral";
    return d->minTriggerInteral;
}

void SurveyItem::setMinTriggerInteral(int minTriggerInteral)
{
    qCWarning(surveyItem) << "setMinTriggerInteral:" << minTriggerInteral;
    if (d->minTriggerInteral == minTriggerInteral)
        return;

    d->minTriggerInteral = minTriggerInteral;
}

double SurveyItem::sensorWidth() const
{
    qCWarning(surveyItem) << "sensorWidth";
    return d->sensorWidth;
}

void SurveyItem::setSensorWidth(double sensorWidth)
{
    qCWarning(surveyItem) << "setSensorWidth:" << sensorWidth;
    if (qFuzzyCompare(d->sensorWidth, sensorWidth))
        return;

    d->sensorWidth = sensorWidth;
}

double SurveyItem::sensorHeight() const
{
    qCWarning(surveyItem) << "sensorHeight";
    return d->sensorHeight;
}

void SurveyItem::setSensorHeight(double sensorHeight)
{
    qCWarning(surveyItem) << "setSensorHeight:" << sensorHeight;
    if (qFuzzyCompare(d->sensorHeight, sensorHeight))
        return;

    d->sensorHeight = sensorHeight;
}

int SurveyItem::sideOverlap() const
{
    qCWarning(surveyItem) << "sideOverlap";
    return d->sideOverlap;
}

void SurveyItem::setSideOverlap(int sideOverlap)
{
    qCWarning(surveyItem) << "setSideOverlap:" << sideOverlap;
    if (d->sideOverlap == sideOverlap)
        return;

    d->sideOverlap = sideOverlap;
}

bool SurveyItem::valueSetIsDistance() const
{
    qCWarning(surveyItem) << "valueSetIsDistance";
    return d->valueSetIsDistance;
}

void SurveyItem::setValueSetIsDistance(bool valueSetIsDistance)
{
    qCWarning(surveyItem) << "setValueSetIsDistance:" << valueSetIsDistance;
    if (d->valueSetIsDistance == valueSetIsDistance)
        return;

    d->valueSetIsDistance = valueSetIsDistance;
}

QVector<QGeoCoordinate> SurveyItem::items() const
{
    qCWarning(surveyItem) << "items";
    return d->items;
}
void SurveyItem::setItems(const QVector<QGeoCoordinate> &item)
{
    qCWarning(surveyItem) << "setItems";
    d->items = item;
}
