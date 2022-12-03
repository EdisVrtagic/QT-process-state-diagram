#include "dialog.h"
#include "stanje.h"
#include "tranzicija.h"
#include "ui_dialog.h"
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsObject>
#include <QBrush>
#include <QKeyEvent>
#include <stdlib.h>
#include <QGraphicsItemAnimation>
#include<QPropertyAnimation>
#include <QDebug>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Kreiranje scene i boja pozadine
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::blue);

    //Poligon start => ready
    tranzicija *tr = new tranzicija();
    tr->setRotation(45);
    tr->setPos(170,125);
    tr->setScale(0.8);
    scene->addItem(tr);
    mTran->connect(tr, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessStartToReady()));
    //Poligon wait => ready
    tranzicija *tr2 = new tranzicija;
    tr2->setRotation(225);
    tr2->setPos(300,375);
    tr2->setScale(0.8);
    scene->addItem(tr2);
    mTran->connect(tr2, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessWaitToReady()));
    //Poligon run => wait
    tranzicija *tr3 = new tranzicija();
    tr3->setRotation(125);
    tr3->setPos(500,310);
    tr3->setScale(0.8);
    scene->addItem(tr3);
    mTran->connect(tr3, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessRunToWait()));
    //Poligon run => stop
    tranzicija *tr4 = new tranzicija;
    tr4->setRotation(305);
    tr4->setPos(525,180);
    tr4->setScale(0.8);
    scene->addItem(tr4);
    mTran->connect(tr4, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessRunToStop()));
    //Poligon ready => run
    tranzicija *tr5 = new tranzicija;
    tr5->setRotation(0);
    tr5->setPos(337,215);
    tr5->setScale(0.8);
    scene->addItem(tr5);
    mTran->connect(tr5, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessReadyToRun()));
    //Poligon run => ready
    tranzicija *tr6 = new tranzicija;
    tr6->setRotation(180);
    tr6->setPos(412,255);
    tr6->setScale(0.8);
    scene->addItem(tr6);
    mTran->connect(tr6, SIGNAL(pomjeri_proces()),this, SLOT(moveProcessRunToReady()));

    //Dodavanje svi elemenata iz konstruktora stanja
    stanje *st = new stanje;
    scene->addItem(st);
}
Dialog::~Dialog()
{
    delete ui;
}
//Button za dodavanje procesa u stanje start
void Dialog::on_pushButton_clicked()
{
    k++;
    if(k == 1)
    {
        if(t1 == 1)
        {
           qDebug()<<"Prvi proces je već kreiran!";
        }
        else
        {
           kreirajelipsu1();
        }
    }
    else if(k == 2)
    {
        if(t2 == 1)
        {
           qDebug()<<"Drugi proces je već kreiran!";
        }
        else
        {
            kreirajelipsu2();
        }
    }
    else if(k == 3)
    {
        if(t3 == 1)
        {
           qDebug()<<"Treći proces je već kreiran!";
        }
        else
        {
            kreirajelipsu3();
        }
    }
    else if(k == 4)
    {
        if(t4 == 1)
        {
           qDebug()<<"Četvrti proces je već kreiran!";
        }
        else
        {
        kreirajelipsu4();
        }
    }
    else if(k == 5)
    {
        if(t5 == 1)
        {
           qDebug()<<"Peti proces je već kreiran!";
        }
        else
        {
        kreirajelipsu5();
        }
        k = 0;
    }
  }
//Kreiranje stanja ellipsa 1
void Dialog::kreirajelipsu1()
{
    QBrush crvenacetka(Qt::red);
    QPen crnaolovka2(Qt::black);
    crnaolovka2.setWidth(0);
    eli1=scene->addEllipse(73,97,8,8,crnaolovka2,crvenacetka);
    t1 = 1;
    kreirano1 = 1;
}
//Kreiranje stanja ellipsa 2
void Dialog::kreirajelipsu2()
{
    QBrush crvenacetka(Qt::red);
    QPen crnaolovka2(Qt::black);
    crnaolovka2.setWidth(0);
    eli2=scene->addEllipse(85,97,8,8,crnaolovka2,crvenacetka);
    t2 = 1;
    kreirano2 = 1;
}
//Kreiranje stanja ellipsa 3
void Dialog::kreirajelipsu3()
{
    QBrush crvenacetka(Qt::red);
    QPen crnaolovka2(Qt::black);
    crnaolovka2.setWidth(0);
    eli3=scene->addEllipse(97,97,8,8,crnaolovka2,crvenacetka);
    t3 = 1;
    kreirano3 = 1;
}
//Kreiranje stanja ellipsa 4
void Dialog::kreirajelipsu4()
{
    QBrush crvenacetka(Qt::red);
    QPen crnaolovka2(Qt::black);
    crnaolovka2.setWidth(0);
    eli4=scene->addEllipse(109,97,8,8,crnaolovka2,crvenacetka);
    t4 = 1;
    kreirano4 = 1;
}
//Kreiranje stanja ellipsa 5
void Dialog::kreirajelipsu5()
{
    QBrush crvenacetka(Qt::red);
    QPen crnaolovka2(Qt::black);
    crnaolovka2.setWidth(0);
    eli5=scene->addEllipse(121,97,8,8,crnaolovka2,crvenacetka);
    t5 = 1;
    kreirano5 = 1;
}
//Proces Start to Ready
void Dialog::moveProcessStartToReady()
{
    opcija++;
    if(opcija == 1)
    {
        if(kreirano1 == 0)
        {
            qDebug() << "Proces 1 ne postoji u stanju start!";
        }
        if(postoji1 == 1)
        {
            qDebug() << "Mjesto 1 za proces je zauzeto!";
        }
        else if(kreirano1 == 1)
        {
            if(postoji1 == 0)
            {
            timers = new QTimeLine(4000);
            QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
            animation->setItem(eli1);
            animation->setTimeLine(timers);
            animation->setPosAt(80 / 130.0, QPointF(149, 130));
            qDebug() << "Proces Start to Ready pokrenut!";
            timers->start();
            kreirano1 = 0;
            postoji1 = 1;
            kreirano6 = 1;
            t1 = 0;
            }
        }
      }
    else if(opcija == 2)
    {
        if(kreirano2 == 0)
        {
            qDebug() << "Proces 2 ne postoji u stanju start!";
        }
        if(postoji2 == 1)
        {
            qDebug() << "Mjesto 2 za proces je zauzeto!";
        }
        else if(kreirano2 == 1)
        {
            if(postoji2 == 0)
            {
        timers2 = new QTimeLine(4000);
        timers2->start();
        QGraphicsItemAnimation *animation2 = new QGraphicsItemAnimation;
        animation2->setItem(eli2);
        animation2->setTimeLine(timers2);
        animation2->setPosAt(80 / 130.0, QPointF(149, 130));
        qDebug() << "Proces Start to Ready pokrenut!";
        kreirano2 = 0;
        postoji2 = 1;
        kreirano7 = 1;
        t2 = 0;
            }
        }
    }
    else if(opcija == 3)
    {
        if(kreirano3 == 0)
        {
            qDebug() << "Proces 3 ne postoji u stanju start!";
        }
        if(postoji3 == 1)
        {
            qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano3 == 1)
        {
            if(postoji3 == 0)
            {
        timers3 = new QTimeLine(4000);
        timers3->start();
        QGraphicsItemAnimation *animation3 = new QGraphicsItemAnimation;
        animation3->setItem(eli3);
        animation3->setTimeLine(timers3);
        animation3->setPosAt(80 / 130.0, QPointF(149, 130));
        qDebug() << "Proces Start to Ready pokrenut!";
        kreirano3 = 0;
        postoji3 = 1;
        kreirano8 = 1;
        t3 = 0;
        }
        }
    }
    else if(opcija == 4)
    {
        if(kreirano4 == 0)
        {
            qDebug() << "Proces 4 ne postoji u stanju start!";
        }
        if(postoji4 == 1)
        {
            qDebug() << "Mjesto 4 za proces je zauzeto!";
        }
        else if(kreirano4 == 1)
        {
            if(postoji4 == 0)
            {
        timers4 = new QTimeLine(4000);
        timers4->start();
        QGraphicsItemAnimation *animation4 = new QGraphicsItemAnimation;
        animation4->setItem(eli4);
        animation4->setTimeLine(timers4);
        animation4->setPosAt(80 / 130.0, QPointF(149, 130));
        qDebug() << "Proces Start to Ready pokrenut!";
        kreirano4 = 0;
        postoji4 = 1;
        kreirano9 = 1;
        t4 = 0;
            }
        }
    }
    else if(opcija == 5)
    {
        if(kreirano5 == 0)
        {
            qDebug() << "Proces 5 ne postoji u stanju start!";
        }
        if(postoji5 == 1)
        {
            qDebug() << "Mjesto 5 za proces je zauzeto!";
        }
        else if(kreirano5 == 1)
        {
            if(postoji5 == 0)
            {
        timers5 = new QTimeLine(4000);
        timers5->start();
        QGraphicsItemAnimation *animation5 = new QGraphicsItemAnimation;
        animation5->setItem(eli5);
        animation5->setTimeLine(timers5);
        animation5->setPosAt(80 / 130.0, QPointF(149, 130));
        qDebug() << "Proces Start to Ready pokrenut!";
        kreirano5 = 0;
        postoji5 = 1;
        kreirano10 = 1;
        t5 = 0;
        }
        }
        k = 0;
        opcija = 0;
    }
}
//Proces Ready to Run
void Dialog::moveProcessReadyToRun()
{
    opcija2++;
    if(opcija2 == 1)
    {
        if(kreirano6 == 0)
        {
            qDebug() << "Proces 1 ne postoji u stanju ready!";
        }
        if(postoji6 == 1)
        {
            qDebug() << "Mjesto 1 za proces je zauzeto!";
        }
        else if(kreirano6 == 1)
        {
        if(postoji6 == 0)
        {
        timers6 = new QTimeLine(4000);
        timers6->start();
        QGraphicsItemAnimation *animation6 = new QGraphicsItemAnimation;
        animation6->setItem(eli1);
        animation6->setTimeLine(timers6);
        animation6->setPosAt(80 / 130.0, QPointF(400, 130));
        qDebug() << "Proces Ready to Run pokrenut!";
        postoji6 = 1;
        kreirano6 = 0;
        kreirano11 = 1;
        postoji1 = 0;
        kreirano16 = 1;
        kreirano26 = 1;
        postoji16 = 1;
        }
      }
    }
    else if(opcija2 == 2)
    {
        if(kreirano7 == 0)
        {
            qDebug() << "Proces 2 ne postoji u stanju ready!";
        }
        if(postoji7 == 1)
        {
            qDebug() << "Mjesto 2 za proces je zauzeto!";
        }
        else if(kreirano7 == 1)
        {
        if(postoji7 == 0)
        {
        timers7 = new QTimeLine(4000);
        timers7->start();
        QGraphicsItemAnimation *animation7 = new QGraphicsItemAnimation;
        animation7->setItem(eli2);
        animation7->setTimeLine(timers7);
        animation7->setPosAt(80 / 130.0, QPointF(400, 130));
        postoji7 = 1;
        kreirano7 = 0;
        kreirano12 = 1;
        postoji2 = 0;
        kreirano17 = 1;
        kreirano27 = 1;
        postoji17 = 1;
        }
      }
    }
    else if(opcija2 == 3)
    {
        if(kreirano8 == 0)
        {
            qDebug() << "Proces 3 ne postoji u stanju ready!";
        }
        if(postoji8 == 1)
        {
            qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano8 == 1)
        {
        if(postoji8 == 0)
        {
        timers8 = new QTimeLine(4000);
        timers8->start();
        QGraphicsItemAnimation *animation8 = new QGraphicsItemAnimation;
        animation8->setItem(eli3);
        animation8->setTimeLine(timers8);
        animation8->setPosAt(80 / 130.0, QPointF(400, 130));
        postoji8 = 1;
        kreirano8 = 0;
        kreirano13 = 1;
        postoji3 = 0;
        kreirano18 = 1;
        kreirano28 = 1;
        postoji18 = 1;
        }
      }
    }
    else if(opcija2 == 4)
    {
        if(kreirano9 == 0)
        {
            qDebug() << "Proces 4 ne postoji u stanju ready!";
        }
        if(postoji9 == 1)
        {
            qDebug() << "Mjesto 4 za proces je zauzeto!";
        }
        else if(kreirano9 == 1)
        {
        if(postoji9 == 0)
        {
        timers9 = new QTimeLine(4000);
        timers9->start();
        QGraphicsItemAnimation *animation9 = new QGraphicsItemAnimation;
        animation9->setItem(eli4);
        animation9->setTimeLine(timers9);
        animation9->setPosAt(80 / 130.0, QPointF(400, 130));
        postoji9 = 1;
        kreirano9 = 0;
        kreirano14 = 1;
        postoji4 = 0;
        kreirano19 = 1;
        kreirano29 = 1;
        postoji19 = 1;
        }
      }
    }
    else if(opcija2 == 5)
    {
        if(kreirano10 == 0)
        {
            qDebug() << "Proces 5 ne postoji u stanju ready!";
        }
        if(postoji10 == 1)
        {
            qDebug() << "Mjesto 5 za proces je zauzeto!";
        }
        else if(kreirano10 == 1)
        {
        if(postoji10 == 0)
        {
        timers10 = new QTimeLine(4000);
        timers10->start();
        QGraphicsItemAnimation *animation10 = new QGraphicsItemAnimation;
        animation10->setItem(eli5);
        animation10->setTimeLine(timers10);
        animation10->setPosAt(80 / 130.0, QPointF(400, 130));
        postoji10 = 1;
        kreirano10 = 0;
        kreirano15 = 1;
        postoji5 = 0;
        kreirano20 = 1;
        kreirano30 = 1;
        postoji20 = 1;
        }
     }
        opcija2 = 0;
   }
}
//Proces Run To Ready
void Dialog::moveProcessRunToReady()
{
    opcija3++;
    if(opcija3 == 1)
    {
        if(kreirano11 == 0)
        {
            qDebug() << "Proces 1 ne postoji u stanju run!";
        }
        if(postoji1 == 1)
        {
            qDebug() << "Mjesto 1 za proces je zauzeto!";
        }
        else if(kreirano11 == 1)
        {
        if(postoji1 == 0)
        {
        timers11 = new QTimeLine(4000);
        timers11->start();
        QGraphicsItemAnimation *animation11 = new QGraphicsItemAnimation;
        animation11->setItem(eli1);
        animation11->setTimeLine(timers11);
        animation11->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano11 = 0;
        postoji6 = 0;
        kreirano6 = 1;
        qDebug() << "Proces Run to Ready pokrenut!";
        }
      }
    }
    else if(opcija3 == 2)
    {
        if(kreirano12 == 0)
        {
            qDebug() << "Proces 2 ne postoji u stanju run!";
        }
        if(postoji2 == 1)
        {
            qDebug() << "Mjesto 2 za proces je zauzeto!";
        }
        else if(kreirano12 == 1)
        {
        if(postoji2 == 0)
        {
        timers12 = new QTimeLine(4000);
        timers12->start();
        QGraphicsItemAnimation *animation12 = new QGraphicsItemAnimation;
        animation12->setItem(eli2);
        animation12->setTimeLine(timers12);
        animation12->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano12 = 0;
        postoji7 = 0;
        kreirano7 = 1;
        qDebug() << "Proces Run to Ready pokrenut!";
        }
        }
    }
    else if(opcija3 == 3)
    {
        if(kreirano13 == 0)
        {
            qDebug() << "Proces 3 ne postoji u stanju run!";
        }
        if(postoji3 == 1)
        {
            qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano13 == 1)
        {
        if(postoji3 == 0)
        {
        timers13 = new QTimeLine(4000);
        timers13->start();
        QGraphicsItemAnimation *animation13 = new QGraphicsItemAnimation;
        animation13->setItem(eli3);
        animation13->setTimeLine(timers13);
        animation13->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano13 = 0;
        postoji8 = 0;
        kreirano8 = 1;
        qDebug() << "Proces Run to Ready pokrenut!";
        }
        }
    }
    else if(opcija3 == 4)
    {
        if(kreirano14 == 0)
        {
            qDebug() << "Proces 4 ne postoji u stanju run!";
        }
        if(postoji4 == 1)
        {
            qDebug() << "Mjesto 4 za proces je zauzeto!";
        }
        else if(kreirano14 == 1)
        {
        if(postoji4 == 0)
        {
        timers14 = new QTimeLine(4000);
        timers14->start();
        QGraphicsItemAnimation *animation14 = new QGraphicsItemAnimation;
        animation14->setItem(eli4);
        animation14->setTimeLine(timers14);
        animation14->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano14 = 0;
        postoji9 = 0;
        kreirano9 = 1;
        qDebug() << "Proces Run to Ready pokrenut!";
        }
      }
    }
    else if(opcija3 == 5)
    {
        if(kreirano15 == 0)
        {
            qDebug() << "Proces 5 ne postoji u stanju run!";
        }
        if(postoji5 == 1)
        {
            qDebug() << "Mjesto 5 za proces je zauzeto!";
        }
        else if(kreirano15 == 1)
        {
        if(postoji5 == 0)
        {
        timers15 = new QTimeLine(4000);
        timers15->start();
        QGraphicsItemAnimation *animation15 = new QGraphicsItemAnimation;
        animation15->setItem(eli5);
        animation15->setTimeLine(timers15);
        animation15->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano15 = 0;
        postoji10 = 0;
        kreirano10 = 1;
        qDebug() << "Proces Run to Ready pokrenut!";
        }
      }
        opcija3 = 0;
    }
}
//Proces Run to Stop
void Dialog::moveProcessRunToStop()
{
    opcija4++;
    if(opcija4 == 1)
    {
        if(kreirano16 == 0)
        {
            qDebug() << "Proces 1 ne postoji u stanju run!";
        }
        if(postoji11 == 1)
        {
            qDebug() << "Mjesto 1 za proces je zauzeto!";
        }
        else if(kreirano16 == 1)
        {
        if(postoji11 == 0)
        {
        timers16 = new QTimeLine(4000);
        timers16->start();
        QGraphicsItemAnimation *animation16 = new QGraphicsItemAnimation;
        animation16->setItem(eli1);
        animation16->setTimeLine(timers16);
        animation16->setPosAt(80 / 130.0, QPointF(550, 0));
        postoji11 = 1;
        kreirano16 = 0;
        postoji6 = 0;
        kreirano21 = 1;
        qDebug() << "Proces Run to Stop pokrenut!";
        }
      }
    }
    else if(opcija4 == 2)
    {
        if(kreirano17 == 0)
        {
            qDebug() << "Proces 2 ne postoji u stanju run!";
        }
        if(postoji12 == 1)
        {
            qDebug() << "Mjesto 2 za proces je zauzeto!";
        }
        else if(kreirano17 == 1)
        {
        if(postoji12 == 0)
        {
        timers17 = new QTimeLine(4000);
        timers17->start();
        QGraphicsItemAnimation *animation17 = new QGraphicsItemAnimation;
        animation17->setItem(eli2);
        animation17->setTimeLine(timers17);
        animation17->setPosAt(80 / 130.0, QPointF(550, 0));
        postoji12 = 1;
        kreirano17 = 0;
        postoji7 = 0;
        kreirano22 = 1;
        qDebug() << "Proces Run to Stop pokrenut!";
        }
        }
    }
    else if(opcija4 == 3)
    {
        if(kreirano18 == 0)
        {
            qDebug() << "Proces 3 ne postoji u stanju run!";
        }
        if(postoji13 == 1)
        {
            qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano18 == 1)
        {
        if(postoji13 == 0)
        {
        timers18 = new QTimeLine(4000);
        timers18->start();
        QGraphicsItemAnimation *animation18 = new QGraphicsItemAnimation;
        animation18->setItem(eli3);
        animation18->setTimeLine(timers18);
        animation18->setPosAt(80 / 130.0, QPointF(550, 0));
        postoji13 = 1;
        kreirano18 = 0;
        postoji8 = 0;
        kreirano23 = 1;
        qDebug() << "Proces Run to Stop pokrenut!";
        }
        }
    }
    else if(opcija4 == 4)
    {
        if(kreirano19 == 0)
        {
            qDebug() << "Proces 4 ne postoji u stanju run!";
        }
        if(postoji14 == 1)
        {
            qDebug() << "Mjesto 4 za proces je zauzeto!";
        }
        else if(kreirano19 == 1)
        {
        if(postoji14 == 0)
        {
        timers19 = new QTimeLine(4000);
        timers19->start();
        QGraphicsItemAnimation *animation19 = new QGraphicsItemAnimation;
        animation19->setItem(eli4);
        animation19->setTimeLine(timers19);
        animation19->setPosAt(80 / 130.0, QPointF(550, 0));
        postoji14 = 1;
        kreirano19 = 0;
        postoji9 = 0;
        kreirano24 = 1;
        qDebug() << "Proces Run to Stop pokrenut!";
        }
        }
    }
    else if(opcija4 == 5)
    {
        if(kreirano20 == 0)
        {
            qDebug() << "Proces 5 ne postoji u stanju run!";
        }
        if(postoji15 == 1)
        {
            qDebug() << "Mjesto 5 za proces je zauzeto!";
        }
        else if(kreirano20 == 1)
        {
        if(postoji15 == 0)
        {
        timers20 = new QTimeLine(4000);
        timers20->start();
        QGraphicsItemAnimation *animation20 = new QGraphicsItemAnimation;
        animation20->setItem(eli5);
        animation20->setTimeLine(timers20);
        animation20->setPosAt(80 / 130.0, QPointF(550, 0));
        postoji15 = 1;
        kreirano20 = 0;
        postoji10 = 0;
        kreirano25 = 1;
        qDebug() << "Proces Run to Stop pokrenut!";
        }
        }
        opcija4 = 0;
    }
}
//Proces Run To Wait
void Dialog::moveProcessRunToWait()
{
    opcija5++;
    if(opcija5 == 1)
    {
        if(kreirano26 == 0)
        {
            qDebug() << "Proces 1 ne postoji u stanju run!";
        }
        if(postoji21 == 1)
        {
            qDebug() << "Mjesto 1 za proces je zauzeto!";
        }
        else if(kreirano26 == 1)
        {
        if(postoji21 == 0)
        {
        timers21 = new QTimeLine(4000);
        timers21->start();
        QGraphicsItemAnimation *animation21 = new QGraphicsItemAnimation;
        animation21->setItem(eli1);
        animation21->setTimeLine(timers21);
        animation21->setPosAt(80 / 130.0, QPointF(275, 291));
        postoji21 = 0;
        kreirano26 = 0;
        kreirano31 = 1;
        qDebug() << "Proces Run to Wait pokrenut!";
        }
        }
    }
    else if(opcija5 == 2)
    {
        if(kreirano27 == 0)
        {
            qDebug() << "Proces 2 ne postoji u stanju run!";
        }
        if(postoji22 == 1)
        {
            qDebug() << "Mjesto 2 za proces je zauzeto!";
        }
        else if(kreirano27 == 1)
        {
        if(postoji22 == 0)
        {
        timers22 = new QTimeLine(4000);
        timers22->start();
        QGraphicsItemAnimation *animation22 = new QGraphicsItemAnimation;
        animation22->setItem(eli2);
        animation22->setTimeLine(timers22);
        animation22->setPosAt(80 / 130.0, QPointF(275, 291));
        postoji22 = 1;
        kreirano27 = 0;
        kreirano32 = 1;
        qDebug() << "Proces Run to Wait pokrenut!";
        }
      }
    }
    else if(opcija5 == 3)
    {
        if(kreirano28 == 0)
        {
           qDebug() << "Proces 3 ne postoji u stanju run!";
        }
        if(postoji23 == 1)
        {
           qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano28 == 1)
        {
        if(postoji23 == 0)
        {
        timers23 = new QTimeLine(4000);
        timers23->start();
        QGraphicsItemAnimation *animation23 = new QGraphicsItemAnimation;
        animation23->setItem(eli3);
        animation23->setTimeLine(timers23);
        animation23->setPosAt(80 / 130.0, QPointF(275, 291));
        postoji23 = 1;
        kreirano28 = 0;
        kreirano33 = 1;
        qDebug() << "Proces Run to Wait pokrenut!";
        }
        }
    }
    else if(opcija5 == 4)
    {
       if(kreirano29 == 0)
       {
         qDebug() << "Proces 4 ne postoji u stanju run!";
       }
       if(postoji24 == 1)
       {
         qDebug() << "Mjesto 4 za proces je zauzeto!";
       }
       else if(kreirano29 == 1)
       {
       if(postoji19 == 0)
       {
        timers24 = new QTimeLine(4000);
        timers24->start();
        QGraphicsItemAnimation *animation24 = new QGraphicsItemAnimation;
        animation24->setItem(eli4);
        animation24->setTimeLine(timers24);
        animation24->setPosAt(80 / 130.0, QPointF(275, 291));
        postoji19 = 1;
        kreirano29 = 0;
        kreirano34 = 1;
        qDebug() << "Proces Run to Wait pokrenut!";
        }
       }
    }
    else if(opcija5 == 5)
    {
       if(kreirano30 == 0)
       {
              qDebug() << "Proces 5 ne postoji u stanju run!";
       }
       if(postoji20 == 1)
       {
              qDebug() << "Mjesto 5 za proces je zauzeto!";
       }
       else if(kreirano30 == 1)
       {
       if(postoji20 == 0)
       {
        timers25 = new QTimeLine(4000);
        timers25->start();
        QGraphicsItemAnimation *animation25 = new QGraphicsItemAnimation;
        animation25->setItem(eli5);
        animation25->setTimeLine(timers25);
        animation25->setPosAt(80 / 130.0, QPointF(275, 291));
        postoji20 = 1;
        kreirano30 = 0;
        kreirano35 = 1;
        qDebug() << "Proces Run to Wait pokrenut!";
        }
       }
        opcija5 = 0;
    }
}
//Proces Wait to Ready
void Dialog::moveProcessWaitToReady()
{
    opcija6++;
    if(opcija6 == 1)
    {
    if(kreirano31 == 0)
    {
        qDebug() << "Proces 1 ne postoji u stanju wait!";
    }
    if(postoji1 == 1)
    {
        qDebug() << "Mjesto 1 za proces je zauzeto!";
    }
    else if(kreirano31 == 1)
    {
        if(postoji1 == 0)
    {
        timers26 = new QTimeLine(4000);
        timers26->start();
        QGraphicsItemAnimation *animation26 = new QGraphicsItemAnimation;
        animation26->setItem(eli1);
        animation26->setTimeLine(timers26);
        animation26->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano31 = 1;
        postoji6 = 0;
        kreirano6 = 1;
       }
     }
    }
    else if(opcija6 == 2)
    {
     if(kreirano32 == 0)
     {
       qDebug() << "Proces 2 ne postoji u stanju wait!";
     }
     if(postoji2 == 1)
     {
       qDebug() << "Mjesto 2 za proces je zauzeto!";
     }
     else if(kreirano32 == 1)
     {
     if(postoji2 == 0)
     {
        timers27 = new QTimeLine(4000);
        timers27->start();
        QGraphicsItemAnimation *animation27 = new QGraphicsItemAnimation;
        animation27->setItem(eli2);
        animation27->setTimeLine(timers27);
        animation27->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano32 = 0;
        postoji7 = 0;
        kreirano7 = 1;
      }
     }
    }
    else if(opcija6 == 3)
    {
        if(kreirano33 == 0)
        {
          qDebug() << "Proces 3 ne postoji u stanju wait!";
        }
        if(postoji3 == 1)
        {
          qDebug() << "Mjesto 3 za proces je zauzeto!";
        }
        else if(kreirano33 == 1)
        {
        if(postoji3 == 0)
        {
        timers28 = new QTimeLine(4000);
        timers28->start();
        QGraphicsItemAnimation *animation28 = new QGraphicsItemAnimation;
        animation28->setItem(eli3);
        animation28->setTimeLine(timers28);
        animation28->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano33 = 0;
        postoji8 = 0;
        kreirano8 = 0;
       }
      }
    }
    else if(opcija6 == 4)
    {
        if(kreirano34 == 0)
        {
          qDebug() << "Proces 4 ne postoji u stanju wait!";
        }
        if(postoji4 == 1)
        {
          qDebug() << "Mjesto 4 za proces je zauzeto!";
        }
        else if(kreirano34 == 1)
        {
        if(postoji4 == 0)
        {
        timers29 = new QTimeLine(4000);
        timers29->start();
        QGraphicsItemAnimation *animation29 = new QGraphicsItemAnimation;
        animation29->setItem(eli4);
        animation29->setTimeLine(timers29);
        animation29->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano34 = 0;
        postoji9 = 0;
        kreirano9 = 0;
       }
     }
    }
    else if(opcija6 == 5)
    {
        if(kreirano35 == 0)
        {
          qDebug() << "Proces 5 ne postoji u stanju wait!";
        }
        if(postoji5 == 1)
        {
          qDebug() << "Mjesto 5 za proces je zauzeto!";
        }
        else if(kreirano35 == 1)
        {
        if(postoji5 == 0)
        {
        timers30 = new QTimeLine(4000);
        timers30->start();
        QGraphicsItemAnimation *animation30 = new QGraphicsItemAnimation;
        animation30->setItem(eli5);
        animation30->setTimeLine(timers30);
        animation30->setPosAt(80 / 130.0, QPointF(149, 130));
        kreirano35 = 0;
        postoji10 = 0;
        kreirano10 = 1;
        }
        }
        opcija6 = 0;
    }
}
//Button za uništavanje procesa
void Dialog::on_pushButton_2_clicked()
{
    c++;
    if(c == 1)
    {
    if(kreirano21 == 0)
    {
      qDebug() << "Proces 1 ne postoji u stanju stop!";
    }
    else
    {
      scene->removeItem(eli1);
      postoji11 = 0;
      qDebug() << "Proces 1 uništen!";
    }
    }
    else if(c == 2)
    {
    if(kreirano22 == 0)
    {
      qDebug() << "Proces 2 ne postoji u stanju stop!";
    }
    else
    {
      scene->removeItem(eli2);
      postoji12 = 0;
      qDebug() << "Proces 2 uništen!";
    }
    }
    else if(c == 3)
    {
    if(kreirano23 == 0)
    {
      qDebug() << "Proces 3 ne postoji u stanju stop!";
    }
    else
    {
      scene->removeItem(eli3);
      postoji13 = 0;
      qDebug() << "Proces 3 uništen!";
    }
    }
    else if(c == 4)
    {
    if(kreirano24 == 0)
    {
      qDebug() << "Proces 4 ne postoji u stanju stop!";
    }
    else
    {
      scene->removeItem(eli4);
      postoji14 = 0;
      qDebug() << "Proces 4 uništen!";
    }
    }
    else if(c == 5)
    {
    if(kreirano25 == 0)
    {
      qDebug() << "Proces 5 ne postoji u stanju stop!";
    }
    else
    {
      scene->removeItem(eli5);
      postoji15 = 0;
      qDebug() << "Proces 5 uništen!";
    }
    c = 0;
  }
}
