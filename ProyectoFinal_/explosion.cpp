#include "explosion.h"
#include <QTimer>
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QList>
Explosion::Explosion() {
    setRect(0,0,100,85);
    QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Explosion");
    QBrush brush(texturaBala.scaled(100,100,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
    setBrush(brush);
    QPen pen(Qt::NoPen);
    setPen(pen);
    QTimer *timer_=new QTimer();
    connect(timer_,SIGNAL(timeout()),this,SLOT(EliminarExplosion()));
    timer_->start(500);
}

void Explosion::EliminarExplosion()
{
    delete this;
}
