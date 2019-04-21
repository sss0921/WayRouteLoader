#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QApplication>

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

    if (!filePath.isEmpty())
        doOpenFile(filePath);
}

void MainWindow::onSaveActionTriggered()
{
}

void MainWindow::onSaveAsActionTriggered()
{
}

void MainWindow::doOpenFile(const QString &filePath)
{
}
