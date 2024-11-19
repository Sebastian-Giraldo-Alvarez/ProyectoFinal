#ifndef BALA_H
#define BALA_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include "mainwindow.h"
#include "puntaje.h"
class Bala:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bala(Puntaje*puntaje);

public slots:
    void MoverBala();
private:
    MainWindow *hola;
    Puntaje *Pun;
};

#endif // BALA_H
