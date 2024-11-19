#ifndef ESCOMBROS_H
#define ESCOMBROS_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include "vida.h"
class Escombros:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Escombros(int Escom, Vida*vida);
public slots:
    void MoverEscombro();
signals:
    void JuegoPerdido();
private:
    Vida *vida_;
};

#endif // ESCOMBROS_H
