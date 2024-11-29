#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include "mainwindow.h"
class Explosion:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Explosion();
public slots:
    void EliminarExplosion();
};

#endif // EXPLOSION_H
