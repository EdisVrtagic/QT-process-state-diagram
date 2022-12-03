#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QBrush>
#include <QMessageBox>
#include "stanje.h"
#include "tranzicija.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    //Scena
    QGraphicsScene *scene;
    QGraphicsEllipseItem *eli1;
    QGraphicsEllipseItem *eli2;
    QGraphicsEllipseItem *eli3;
    QGraphicsEllipseItem *eli4;
    QGraphicsEllipseItem *eli5;
    //Timeri za animacije
    QTimeLine *timers;
    QTimeLine *timers2;
    QTimeLine *timers3;
    QTimeLine *timers4;
    QTimeLine *timers5;
    QTimeLine *timers6;
    QTimeLine *timers7;
    QTimeLine *timers8;
    QTimeLine *timers9;
    QTimeLine *timers10;
    QTimeLine *timers11;
    QTimeLine *timers12;
    QTimeLine *timers13;
    QTimeLine *timers14;
    QTimeLine *timers15;
    QTimeLine *timers16;
    QTimeLine *timers17;
    QTimeLine *timers18;
    QTimeLine *timers19;
    QTimeLine *timers20;
    QTimeLine *timers21;
    QTimeLine *timers22;
    QTimeLine *timers23;
    QTimeLine *timers24;
    QTimeLine *timers25;
    QTimeLine *timers26;
    QTimeLine *timers27;
    QTimeLine *timers28;
    QTimeLine *timers29;
    QTimeLine *timers30;
    //Integeri
    int k = 0;
    int c = 0;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;
    int t5 = 0;
    int opcija = 0;
    int opcija2 = 0;
    int opcija3 = 0;
    int opcija4 = 0;
    int opcija5 = 0;
    int opcija6 = 0;
    int kreirano1 = 0;
    int kreirano2 = 0;
    int kreirano3 = 0;
    int kreirano4 = 0;
    int kreirano5 = 0;
    int kreirano6 = 0;
    int kreirano7 = 0;
    int kreirano8 = 0;
    int kreirano9 = 0;
    int kreirano10 = 0;
    int kreirano11 = 0;
    int kreirano12 = 0;
    int kreirano13 = 0;
    int kreirano14 = 0;
    int kreirano15 = 0;
    int kreirano16 = 0;
    int kreirano17 = 0;
    int kreirano18 = 0;
    int kreirano19 = 0;
    int kreirano20 = 0;
    int kreirano21 = 0;
    int kreirano22 = 0;
    int kreirano23 = 0;
    int kreirano24 = 0;
    int kreirano25 = 0;
    int kreirano26 = 0;
    int kreirano27 = 0;
    int kreirano28 = 0;
    int kreirano29 = 0;
    int kreirano30 = 0;
    int kreirano31 = 0;
    int kreirano32 = 0;
    int kreirano33 = 0;
    int kreirano34 = 0;
    int kreirano35 = 0;
    int postoji1 = 0;
    int postoji2 = 0;
    int postoji3 = 0;
    int postoji4 = 0;
    int postoji5 = 0;
    int postoji6 = 0;
    int postoji7 = 0;
    int postoji8 = 0;
    int postoji9 = 0;
    int postoji10 = 0;
    int postoji11 = 0;
    int postoji12 = 0;
    int postoji13 = 0;
    int postoji14 = 0;
    int postoji15 = 0;
    int postoji16 = 0;
    int postoji17 = 0;
    int postoji18 = 0;
    int postoji19 = 0;
    int postoji20 = 0;
    int postoji21 = 0;
    int postoji22 = 0;
    int postoji23 = 0;
    int postoji24 = 0;
    int postoji25 = 0;
    //Tranzicija za signale
    tranzicija *mTran;
public slots:
    //Funkcije za kreiranje ellipsi i pomjeranje procesa
    void kreirajelipsu1();
    void kreirajelipsu2();
    void kreirajelipsu3();
    void kreirajelipsu4();
    void kreirajelipsu5();
    void moveProcessStartToReady();
    void moveProcessReadyToRun();
    void moveProcessRunToReady();
    void moveProcessRunToWait();
    void moveProcessRunToStop();
    void moveProcessWaitToReady();
private slots:
    //Button za kreiranje i uništavanje procesa
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H
