#ifndef SURVEYITEM_H
#define SURVEYITEM_H

#include "visualitem.h"

#include <QGeoCoordinate>
#include <QScopedPointer>

class SurveyItemPrivate;
class SurveyItem : public VisualItem
{
public:
    explicit SurveyItem(QObject *parent = nullptr);
    ~SurveyItem();

    QString type() const;
    int sequence() const;
    void setSequence(int sequence);

    double adjustedFootprintFrontal() const;
    void setAdjustedFootprintFrontal(double adjustedFootprintFrontal);

    double adjustedFootprintSide() const;
    void setAdjustedFootprintSide(double adjustedFootprintSide);

    QString cameraName() const;
    void setCameraName(const QString &cameraName);

    int distanceToSurface() const;
    void setDistanceToSurface(int distanceToSurface);

    bool distanceToSurfaceRelative() const;
    void setDistanceToSurfaceRelative(bool distanceToSurfaceRelative);

    bool fixedOrientation() const;
    void setFixedOrientation(bool fixedOrientation);

    double focalLength() const;
    void setFocalLength(double focalLength);

    int frontalOverlap() const;
    void setFrontalOverlap(int frontalOverlap);

    double imageDensity() const;
    void setImageDensity(double imageDensity);

    int imageWidth() const;
    void setImageWidth(int imageWidth);

    int imageHeight() const;
    void setImageHeight(int imageHeight);

    bool landscape() const;
    void setLandscape(bool landscape);

    int minTriggerInteral() const;
    void setMinTriggerInteral(int minTriggerInteral);

    double sensorWidth() const;
    void setSensorWidth(double sensorWidth);

    double sensorHeight() const;
    void setSensorHeight(double sensorHeight);

    int sideOverlap() const;
    void setSideOverlap(int sideOverlap);

    bool valueSetIsDistance() const;
    void setValueSetIsDistance(bool valueSetIsDistance);

    QVector<QGeoCoordinate> items() const;
    void setItems(const QVector<QGeoCoordinate> &item);

private:
    QScopedPointer<SurveyItemPrivate> d;
};

#endif // SURVEYITEM_H
