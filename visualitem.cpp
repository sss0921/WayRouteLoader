#include "visualitem.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(visualItem, "WayRouteLoader.VisualItem")

VisualItem::VisualItem(QObject *parent)
    : QObject(parent)
{
    qCWarning(visualItem) << "VisualItem";
}

VisualItem::~VisualItem()
{
    qCWarning(visualItem) << "~VisualItem";
}
