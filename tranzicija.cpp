#include "tranzicija.h"
#include "dialog.h"
#include <QDebug>
#include <QGraphicsPolygonItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>

tranzicija::tranzicija()
{
    pol1 << QPoint(0,45)  << QPoint(60,45) << QPoint(60,35) << QPoint(100, 50)
         << QPoint(60,65) << QPoint(60,55) << QPoint(0,55)  << QPoint(0,45);
    QBrush pen(Qt::green);
    setBrush(pen);
    setPolygon(pol1);
}

void tranzicija::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit pomjeri_proces();
}
