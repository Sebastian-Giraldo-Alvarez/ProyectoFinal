#include "monorriel.h"
#include <QTimer>
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "escombros.h"
//#include "bala.h"
Monorriel::Monorriel(Vida *vida) {
    vida_=vida;
    setRect(0,0,450,80);
    QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Monorriel");
    QBrush brush(texturaBala.scaled(450,300,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
    setBrush(brush);
    QPen pen(Qt::NoPen);
    setPen(pen);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(MoverMonorriel()));
    timer->start(50);
    QTimer *timer2=new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(GenerarEscombros()));
    timer2->start(1000);
}

void Monorriel::MoverMonorriel()
{
    if(pos().x()>820){
        movimiento=true;
    }
    else if(pos().x()<0){
        movimiento=false;
    }
    if(movimiento==true){
        setPos(x()-10,y());
    }
    else{
        setPos(x()+10,y());
    }
}

void Monorriel::GenerarEscombros()
{
    Escom++;
    Escombros *escombro=new Escombros(Escom,vida_);
    connect(escombro, &Escombros::JuegoPerdido, this, &Monorriel::JuegoPerdido);
    escombro->setPos(x()+230,y()+100);
    scene()->addItem(escombro);
    if(Escom==7){
        Escom=0;
    }
}
