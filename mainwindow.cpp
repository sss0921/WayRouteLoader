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
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenActionTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveActionTriggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAsActionTriggered);

    QString dirPath = qApp->applicationDirPath();
    m_planPath = dirPath + "/" + "Plan";

    QDir dir(m_planPath);
    if (!dir.exists())
        dir.mkpath(m_planPath);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::doOpenFile(const QString &filePath)
{
}

void MainWindow::doSaveFile(const QString &filePath)
{
}
