#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(mainwindow, "WayRouteLoader.MainWindow")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_simpleItemLoader(new SimpleItemLoader(this))
    , m_missionItem(new MissionItem(this))
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenActionTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveActionTriggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAsActionTriggered);
    connect(ui->actionSimple, &QAction::triggered, this, &MainWindow::onSimpleActionTriggered);
    connect(ui->actionSurvey, &QAction::triggered, this, &MainWindow::onSurveyActionTriggered);

    QString dirPath = qApp->applicationDirPath();
    m_planPath = dirPath + "/" + "Plan";

    QDir dir(m_planPath);
    if (!dir.exists())
        dir.mkpath(m_planPath);
}

MainWindow::~MainWindow()
{
    delete ui;

    for (auto it = m_data.begin(); it != m_data.end(); it++)
        delete *it;

    m_data.clear();
}

void MainWindow::onOpenActionTriggered()
{
    QString filePath =
        QFileDialog::getOpenFileName(this, tr("Open WayRoute File"), m_planPath, tr("File *.plan"));

    if (!filePath.isEmpty()) {
        doOpenFile(filePath);
        m_filePath = filePath;
    }
}

void MainWindow::onSaveActionTriggered()
{
    if (m_filePath.isEmpty()) {
        if (QMessageBox::information(
                this, tr("Info"),
                "Don't open a file, need a file to save, Do you want to Open a file",
                QMessageBox::Yes, QMessageBox::No)
            == QMessageBox::Yes) {

            QString filePath = QFileDialog::getSaveFileName(this, tr("Open Plan File"), m_planPath,
                                                            tr("File *.plan"));
            if (!filePath.isEmpty())
                m_filePath = filePath;
            else
                return;
        } else {
            return;
        }
    }
    doSaveFile(m_filePath);
}

void MainWindow::onSaveAsActionTriggered()
{
    QString filePath =
        QFileDialog::getSaveFileName(this, tr("Open Plan file"), m_planPath, tr("File *.plan"));

    if (!filePath.isEmpty())
        doSaveFile(filePath);
}

void MainWindow::onSimpleActionTriggered()
{
    qCWarning(mainwindow) << "onSimpleActionTriggered";
    if (m_simpleItemLoader->exec() == QDialog::Accepted) {
        qCWarning(mainwindow) << "Accepted";
        SimpleItem *item = m_simpleItemLoader->simpleItem();
        m_data.append(item);
        appendData(item);
    } else {
        qCWarning(mainwindow) << "Rejected";
    }
}

void MainWindow::onSurveyActionTriggered()
{
    qCWarning(mainwindow) << "onSurveyActionTriggered";
}

void MainWindow::doOpenFile(const QString &filePath)
{
    qCWarning(mainwindow) << "doOpenFile";
    qCWarning(mainwindow) << QString("filePath: %1").arg(filePath);
}

void MainWindow::doSaveFile(const QString &filePath)
{
    qCWarning(mainwindow) << "doSaveFile";
    qCWarning(mainwindow) << QString("filePath: %1").arg(filePath);

    m_missionItem->setItemsData(m_data);
    if (m_missionItem->save(filePath))
        QMessageBox::information(this, tr("Info"), tr("Save camera file success!"));
}

void MainWindow::appendData(VisualItem *item)
{
    // judge the current type
    if (item->type() == QString("SimpleItem")) {
        SimpleItem *simpleItem = qobject_cast<SimpleItem *>(item);
        appendSimpleItemData(simpleItem);
    }
}

void MainWindow::appendSimpleItemData(SimpleItem *item)
{
    // sequence
    QTreeWidgetItem *sequenceItem = new QTreeWidgetItem(ui->treeWidget);
    sequenceItem->setText(0, "Sequence:");
    sequenceItem->setText(1, QString::number(item->sequence()));
    // longitude
    QTreeWidgetItem *longitudeItem = new QTreeWidgetItem(sequenceItem);
    longitudeItem->setText(0, "Longitude:");
    longitudeItem->setText(1, QString::number(item->longitude(), 'f', 6));
    // latitude
    QTreeWidgetItem *latitudeItem = new QTreeWidgetItem(sequenceItem);
    latitudeItem->setText(0, "Latitude:");
    latitudeItem->setText(1, QString::number(item->latitude(), 'f', 6));
    // altitude
    QTreeWidgetItem *altitudeItem = new QTreeWidgetItem(sequenceItem);
    altitudeItem->setText(0, "Altitude:");
    altitudeItem->setText(1, QString::number(item->altitude()));
    // speed
    QTreeWidgetItem *speedItem = new QTreeWidgetItem(sequenceItem);
    speedItem->setText(0, "Speed:");
    speedItem->setText(1, QString::number(item->speed(), 'f', 1));
    // raiuds
    QTreeWidgetItem *radiusItem = new QTreeWidgetItem(sequenceItem);
    radiusItem->setText(0, "Radius:");
    radiusItem->setText(1, QString::number(item->radius()));
    // flag
    QTreeWidgetItem *flagItem = new QTreeWidgetItem(sequenceItem);
    flagItem->setText(0, "Flag:");
    flagItem->setText(1, QString::number(item->flag(), 16));
}
