#include "stanje.h"
#include "tranzicija.h"
#include<QGraphicsEllipseItem>

stanje::stanje()
{
}
void stanje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPen,QBrush,QPainterPath,QFont za stanja na sceni (ellipse i QString stanja)
    //Dodavanje ellipsi
    QPainterPath path;
    path.addEllipse(50,50,100,100);
    path.addEllipse(200,180,100,100);
    path.addEllipse(450,180,100,100);
    path.addEllipse(600,50,100,100);
    path.addEllipse(325,340,100,100);
    scene()->addPath(path, QPen(QBrush(Qt::black), 2), QBrush(Qt::yellow));

    //Dodavanje kvadratica
    //Kvadrati za start
    QPainterPath path2;
    path2.addRect(71,95,12,12);
    path2.addRect(83,95,12,12);
    path2.addRect(95,95,12,12);
    path2.addRect(107,95,12,12);
    path2.addRect(119,95,12,12);
    //Kvadrati za ready
    path2.addRect(220,225,12,12);
    path2.addRect(232,225,12,12);
    path2.addRect(244,225,12,12);
    path2.addRect(256,225,12,12);
    path2.addRect(268,225,12,12);
    //Kvadrati za run
    path2.addRect(471,225,12,12);
    path2.addRect(483,225,12,12);
    path2.addRect(495,225,12,12);
    path2.addRect(507,225,12,12);
    path2.addRect(519,225,12,12);
    //Kvadrati za stop
    path2.addRect(621,95,12,12);
    path2.addRect(633,95,12,12);
    path2.addRect(645,95,12,12);
    path2.addRect(657,95,12,12);
    path2.addRect(669,95,12,12);
    //Kvadrati za wait
    path2.addRect(346,386,12,12);
    path2.addRect(358,386,12,12);
    path2.addRect(370,386,12,12);
    path2.addRect(382,386,12,12);
    path2.addRect(394,386,12,12);
    scene()->addPath(path2, QPen(QBrush(Qt::black), 1), QBrush(Qt::gray));

    //Dodavanje string-a za naziv stanja
    QPainterPath path3;
    QFont font;
    font.setPixelSize(18);
    font.setBold(false);
    font.setFamily("Arial");
    QString sceneText = "Start";
    QString sceneText2 = "Ready";
    QString sceneText3 = "Run";
    QString sceneText4 = "Wait";
    QString sceneText5 = "Stop";
    path3.addText(82,80,font,sceneText);
    path3.addText(225,210,font,sceneText2);
    path3.addText(485,210,font,sceneText3);
    path3.addText(358,370,font,sceneText4);
    path3.addText(632,80,font,sceneText5);
    scene()->addPath(path3, QPen(QBrush(Qt::black), 1), QBrush(Qt::black));
}
