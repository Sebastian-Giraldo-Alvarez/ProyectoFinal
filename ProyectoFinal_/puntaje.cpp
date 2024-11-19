#include "puntaje.h"
#include <QFont>
Puntaje::Puntaje(QGraphicsItem * parent): QGraphicsTextItem(parent){
    puntaje=0;
    setPlainText(QString("Puntaje: ") + QString::number(puntaje));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Veces",16));
}

void Puntaje::Aumentar()
{
    puntaje++;
    setPlainText(QString("Puntaje: ") + QString::number(puntaje));
}

int Puntaje::GetPuntaje()
{
    return puntaje;
}

void Puntaje::setPuntaje(int newPuntaje)
{
    puntaje = newPuntaje;
}
