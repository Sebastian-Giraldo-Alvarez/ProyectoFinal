#ifndef BALA_H
#define BALA_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
class Bala:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bala();
public slots:
    void MoverBala();
};

#endif // BALA_H
