#include "surveyitemloader.h"
#include "ui_surveyitemloader.h"

SurveyItemLoader::SurveyItemLoader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SurveyItemLoader)
{
    ui->setupUi(this);
}

SurveyItemLoader::~SurveyItemLoader()
{
    delete ui;
}

SurveyItem *SurveyItemLoader::surveyItem() const
{
    return m_surveyItem;
}

void SurveyItemLoader::setSurveyItem(SurveyItem *item)
{
    m_surveyItem = item;
}

void SurveyItemLoader::updateData()
{
    ui->sequenceSpinBox->setValue(m_surveyItem->sequence());
    ui->cameraNameLineEdit->setText(m_surveyItem->cameraName());
    ui->footprintFrontaDoubleSpinBox->setValue(m_surveyItem->adjustedFootprintFrontal());
    ui->footprintSideDoubleSpinBox->setValue(m_surveyItem->adjustedFootprintSide());
    ui->distanceToSurfaceSpinBox->setValue(m_surveyItem->distanceToSurface());
    ui->focalLengthDoubleSpinBox->setValue(m_surveyItem->focalLength());
    ui->minTriggerInteralSpinBox->setValue(m_surveyItem->minTriggerInteral());
    ui->imageDensityDoubleSpinBox->setValue(m_surveyItem->imageDensity());
    ui->imageWidthSpinBox->setValue(m_surveyItem->imageWidth());
    ui->imageHeightSpinBox->setValue(m_surveyItem->imageHeight());
    ui->sensorWidthDoubleSpinBox->setValue(m_surveyItem->sensorWidth());
    ui->sensorHeightDoubleSpinBox->setValue(m_surveyItem->sensorHeight());
    ui->frontIOverlapSpinBox->setValue(m_surveyItem->frontalOverlap());
    ui->sideOverlapSpinBox->setValue(m_surveyItem->sideOverlap());

    int itemNum = ui->itemsSpinBox->value();
    for (int i = 0; i < itemNum; i++) {
        SimpleItem *simpleItem = new SimpleItem;
        simpleItem->setLongitude(ui->longitudeDoubleSpinBox->value());
        simpleItem->setLatitude(ui->latitudeDoubleSpinBox->value());
        simpleItem->setAltitude(ui->altitudeSpinBox->value());
        simpleItem->setSpeed(ui->speedDoubleSpinBox->value());
        simpleItem->setRadius(ui->radiusSpinBox->value());
        simpleItem->setFlag(static_cast<unsigned char>(ui->flagSpinBox->value()));
        m_surveyItem->appendItem(simpleItem);
    }

    if (m_surveyItem->distanceToSurfaceRelative())
        ui->distanceToSurfaceRelativeComboBox->setCurrentIndex(1);
    else
        ui->distanceToSurfaceRelativeComboBox->setCurrentIndex(0);

    if (m_surveyItem->fixedOrientation())
        ui->fixedOrientationComboBox->setCurrentIndex(1);
    else
        ui->fixedOrientationComboBox->setCurrentIndex(0);

    if (m_surveyItem->landscape())
        ui->landscapeComboBox->setCurrentIndex(1);
    else
        ui->landscapeComboBox->setCurrentIndex(0);

    if (m_surveyItem->valueSetIsDistance())
        ui->valueSetIsDistanceComboBox->setCurrentIndex(1);
    else
        ui->valueSetIsDistanceComboBox->setCurrentIndex(0);
}

void SurveyItemLoader::setData()
{
}
