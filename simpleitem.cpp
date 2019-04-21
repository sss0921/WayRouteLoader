#include "simpleitem.h"

class SimpleItemPrivate
{
public:
    SimpleItemPrivate()
        : type("SimpleItem")
        , sequence(0)
        , longitude(0.000000)
        , latitude(0.000000)
        , altitude(0)
        , speed(0.0)
        , radius(0)
        , flag(0)
    {
    }
    SimpleItemPrivate(const QString &type, int sequence, double longitude, double latitude,
                      int altitude, double speed, int radius)
        : type(type)
        , sequence(sequence)
        , longitude(longitude)
        , latitude(latitude)
        , altitude(altitude)
        , speed(speed)
        , radius(radius)
    {
    }
    ~SimpleItemPrivate() {}
    QString type;
    int sequence;
    double longitude;
    double latitude;
    int altitude;
    double speed;
    int radius;
    unsigned char flag;
};

SimpleItem::SimpleItem(QObject *parent)
    : QObject(parent)
    , d(new SimpleItemPrivate)
{
}

SimpleItem::~SimpleItem()
{
}

QString SimpleItem::type() const
{
    return d->type;
}

int SimpleItem::sequence() const
{
    return d->sequence;
}

void SimpleItem::setSequence(int sequence)
{
    d->sequence = sequence;
}

double SimpleItem::longitude() const
{
    return d->longitude;
}

void SimpleItem::setLongitude(double longitude)
{
    d->longitude = longitude;
}

double SimpleItem::latitude() const
{
    return d->latitude;
}

void SimpleItem::setLatitude(double latitude)
{
    d->latitude = latitude;
}

int SimpleItem::altitude() const
{
    return d->altitude;
}

void SimpleItem::setAltitude(int altitude)
{
    d->altitude = altitude;
}

double SimpleItem::speed() const
{
    return d->speed;
}

void SimpleItem::setSpeed(double speed)
{
    d->speed = speed;
}

int SimpleItem::radius() const
{
    return d->radius;
}

void SimpleItem::setRadius(int radius)
{
    d->radius = radius;
}

unsigned char SimpleItem::flag() const
{
    return d->flag;
}

void SimpleItem::setFlag(unsigned char flag)
{
    d->flag = flag;
}
