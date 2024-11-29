#ifndef MONORRIEL_H
#define MONORRIEL_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView>
#include "vida.h"
class Monorriel:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Monorriel(Vida *vida);
public slots:
    void MoverMonorriel();
    void GenerarEscombros();
signals:
    void JuegoPerdido();
private:
    bool movimiento=false;
    int Escom=0;
    Vida *vida_;
    int aumentardificultad=0;
    int dificultad=1;
};

#endif // MONORRIEL_H
