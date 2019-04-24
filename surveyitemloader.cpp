#include "surveyitemloader.h"
#include "ui_surveyitemloader.h"

SurveyItemLoader::SurveyItemLoader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SurveyItemLoader)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this,
            &SurveyItemLoader::onAcceptedActionTriggered);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SurveyItemLoader::rejected);
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

void SurveyItemLoader::onAcceptedActionTriggered()
{
    updateData();
    this->accept();
}

void SurveyItemLoader::updateData()
{
    m_surveyItem = new SurveyItem;
    m_surveyItem->setSequence(ui->sequenceSpinBox->value());
    m_surveyItem->setCameraName(ui->cameraNameLineEdit->text());
    m_surveyItem->setAdjustedFootprintFrontal(ui->footprintFrontaDoubleSpinBox->value());
    m_surveyItem->setAdjustedFootprintSide(ui->footprintSideDoubleSpinBox->value());
    m_surveyItem->setDistanceToSurface(ui->distanceToSurfaceSpinBox->value());
    m_surveyItem->setFocalLength(ui->focalLengthDoubleSpinBox->value());
    m_surveyItem->setMinTriggerInteral(ui->minTriggerInteralSpinBox->value());
    m_surveyItem->setImageDensity(ui->imageDensityDoubleSpinBox->value());
    m_surveyItem->setImageWidth(ui->imageWidthSpinBox->value());
    m_surveyItem->setImageHeight(ui->imageHeightSpinBox->value());
    m_surveyItem->setSensorWidth(ui->sensorWidthDoubleSpinBox->value());
    m_surveyItem->setSensorHeight(ui->sensorHeightDoubleSpinBox->value());
    m_surveyItem->setFrontalOverlap(ui->frontalOverlapSpinBox->value());
    m_surveyItem->setSideOverlap(ui->sideOverlapSpinBox->value());

    if (ui->distanceToSurfaceRelativeComboBox->currentIndex() == 1)
        m_surveyItem->setDistanceToSurfaceRelative(true);
    else
        m_surveyItem->setDistanceToSurfaceRelative(false);

    if (ui->fixedOrientationComboBox->currentIndex() == 1)
        m_surveyItem->setFixedOrientation(true);
    else
        m_surveyItem->setFixedOrientation(false);

    if (ui->landscapeComboBox->currentIndex() == 1)
        m_surveyItem->setLandscape(true);
    else
        m_surveyItem->setLandscape(false);

    if (ui->valueSetIsDistanceComboBox->currentIndex() == 1)
        m_surveyItem->setValueSetIsDistance(true);
    else
        m_surveyItem->setValueSetIsDistance(false);

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
}

void SurveyItemLoader::setData()
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
    ui->frontalOverlapSpinBox->setValue(m_surveyItem->frontalOverlap());
    ui->sideOverlapSpinBox->setValue(m_surveyItem->sideOverlap());

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
