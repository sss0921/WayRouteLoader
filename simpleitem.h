#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H

#include "visualitem.h"

#include <QObject>
#include <QScopedPointer>

class SimpleItemPrivate;
class SimpleItem : public VisualItem
{
    Q_OBJECT
public:
    explicit SimpleItem(QObject *parent = nullptr);
    ~SimpleItem();

    QString type() const;

    int sequence() const;
    void setSequence(int sequence);

    double longitude() const;
    void setLongitude(double longitude);

    double latitude() const;
    void setLatitude(double latitude);

    int altitude() const;
    void setAltitude(int altitude);

    double speed() const;
    void setSpeed(double speed);

    int radius() const;
    void setRadius(int radius);

    unsigned char flag() const;
    void setFlag(unsigned char flag);

private:
    QScopedPointer<SimpleItemPrivate> d;
};

#endif // SIMPLEITEM_H
