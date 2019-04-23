#ifndef SIMPLEITEMLOADER_H
#define SIMPLEITEMLOADER_H

#include "simpleitem.h"

#include <QDialog>

namespace Ui {
class SimpleItemLoader;
}

class SimpleItemLoader : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleItemLoader(QWidget *parent = nullptr);
    ~SimpleItemLoader();

    SimpleItem *simpleItem() const;
    void setSimpleItem(SimpleItem *item);

private:
    void onAcceptedActionTriggered();
    void updateData();
    void setData();

    Ui::SimpleItemLoader *ui;
    SimpleItem *m_simpleItem;
};

#endif // SIMPLEITEMLOADER_H
