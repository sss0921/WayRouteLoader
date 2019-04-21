#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void doOpenFile(const QString &filePath);

    Ui::MainWindow *ui;
    QString m_planPath;
};

#endif // MAINWINDOW_H
