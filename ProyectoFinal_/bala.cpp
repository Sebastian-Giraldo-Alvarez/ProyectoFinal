#include "bala.h"
#include "explosion.h"
#include <QTimer>
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QList>
#include "escombros.h"
class MainWindow;
Bala::Bala(Puntaje*puntaje) {
    Pun=puntaje;
    setRect(0,0,20,20);
    QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Bala");
    QBrush brush(texturaBala.scaled(20,20,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
    setBrush(brush);
    QPen pen(Qt::NoPen);
    setPen(pen);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(MoverBala()));
    timer->start(50);
}
void Bala::MoverBala()
{
    QList<QGraphicsItem *> Colisiones = collidingItems();
    for(int i=0,n=Colisiones.size();i<n;i++){
        if(typeid(*(Colisiones[i]))==typeid(Escombros)){
            Pun->Aumentar();
            scene()->removeItem(Colisiones[i]);
            scene()->removeItem(this);
            delete Colisiones[i];
            delete this;
            return;
        }
    }
    for(int i=0,n=Colisiones.size();i<n;i++){
        if(typeid(*(Colisiones[i]))==typeid(Monorriel)){
            direccion=-1;
        }
    }

    setPos(x(),y()-10*direccion);
    if(pos().y()+rect().height()<0||pos().y()==700){//Cuando la figura pase totalmente la vista
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"Se elimino";
    }
}
