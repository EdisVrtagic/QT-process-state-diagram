#ifndef STANJE_H
#define STANJE_H
#include<QGraphicsEllipseItem>


class stanje:public QGraphicsEllipseItem
{
public:
    stanje();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // STANJE_H
