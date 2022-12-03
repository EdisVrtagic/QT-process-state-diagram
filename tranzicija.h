#ifndef TRANZICIJA_H
#define TRANZICIJA_H
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPen>
#include <QObject>
#include <QGraphicsObject>
#include <QBrush>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QMatrix>
#include <stdlib.h>


class tranzicija:public QObject,public QGraphicsPolygonItem
{
    Q_OBJECT
public:
    tranzicija();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QPolygonF pol1;
signals:
    void pomjeri_proces();
};
#endif // TRANZICIJA_H
