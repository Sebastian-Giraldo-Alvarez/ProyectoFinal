#include "bala.h"
#include <QTimer>
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem>
Bala::Bala() {
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
    setPos(x(),y()-10);
}
