#ifndef VISUALITEM_H
#define VISUALITEM_H

#include <QObject>

class VisualItem : public QObject
{
    Q_OBJECT
public:
    explicit VisualItem(QObject *parent = nullptr);

    virtual QString type() const = 0;
    virtual int sequence() const = 0;
    virtual void setSequence(int sequence) = 0;
};

#endif // VISUALITEM_H
