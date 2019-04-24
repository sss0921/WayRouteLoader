#ifndef SURVEYITEMLOADER_H
#define SURVEYITEMLOADER_H

#include "surveyitem.h"

#include <QDialog>

namespace Ui {
class SurveyItemLoader;
}

class SurveyItemLoader : public QDialog
{
    Q_OBJECT

public:
    explicit SurveyItemLoader(QWidget *parent = nullptr);
    ~SurveyItemLoader();

    SurveyItem *surveyItem() const;
    void setSurveyItem(SurveyItem *item);

private:
    void updateData();
    void setData();

    Ui::SurveyItemLoader *ui;

    SurveyItem *m_surveyItem;
};

#endif // SURVEYITEMLOADER_H
