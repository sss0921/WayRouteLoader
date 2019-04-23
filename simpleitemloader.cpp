#include "simpleitemloader.h"
#include "ui_simpleitemloader.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(simpleItemLoader, "WayRouteLoader.SimpleItemLoader")

SimpleItemLoader::SimpleItemLoader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SimpleItemLoader)
    , m_simpleItem(nullptr)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this,
            &SimpleItemLoader::onAcceptedActionTriggered);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SimpleItemLoader::rejected);
}

SimpleItemLoader::~SimpleItemLoader()
{
    delete ui;
}

SimpleItem *SimpleItemLoader::simpleItem() const
{
    return m_simpleItem;
}

void SimpleItemLoader::setSimpleItem(SimpleItem *item)
{
    m_simpleItem = item;
    setData();
}

void SimpleItemLoader::onAcceptedActionTriggered()
{
    updateData();
    this->accept();
}

void SimpleItemLoader::updateData()
{
    m_simpleItem = new SimpleItem;
    m_simpleItem->setSequence(ui->sequenceSpinBox->value());
    m_simpleItem->setLongitude(ui->longitudeDoubleSpinBox->value());
    m_simpleItem->setLatitude(ui->latitudeDoubleSpinBox->value());
    m_simpleItem->setAltitude(ui->altitudeSpinBox->value());
    m_simpleItem->setSpeed(ui->speedDoubleSpinBox->value());
    m_simpleItem->setRadius(ui->radiusSpinBox->value());
    m_simpleItem->setFlag(static_cast<unsigned char>(ui->flagSpinBox->value()));
}

void SimpleItemLoader::setData()
{
    ui->sequenceSpinBox->setValue(m_simpleItem->sequence());
    ui->longitudeDoubleSpinBox->setValue(m_simpleItem->longitude());
    ui->latitudeDoubleSpinBox->setValue(m_simpleItem->latitude());
    ui->altitudeSpinBox->setValue(m_simpleItem->altitude());
    ui->speedDoubleSpinBox->setValue(m_simpleItem->speed());
    ui->radiusSpinBox->setValue(m_simpleItem->radius());
    ui->flagSpinBox->setValue(m_simpleItem->flag());
}
