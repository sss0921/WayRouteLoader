#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "visualitem.h"
#include "missionitem.h"
#include "simpleitemloader.h"
#include "surveyitemloader.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onOpenActionTriggered();
    void onSaveActionTriggered();
    void onSaveAsActionTriggered();
    void onSimpleActionTriggered();
    void onSurveyActionTriggered();

    void appendData(VisualItem *item);
    void doOpenFile(const QString &filePath);
    void doSaveFile(const QString &filePath);
    void appendSimpleItemData(SimpleItem *item);
    void appendSurveyItemData(SurveyItem *item);

    Ui::MainWindow *ui;
    QString m_planPath;
    QString m_filePath;

    SimpleItemLoader *m_simpleItemLoader;
    SurveyItemLoader *m_surveyItemLoader;
    MissionItem *m_missionItem;
    QVector<VisualItem *> m_data;
};

#endif // MAINWINDOW_H
