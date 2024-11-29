#include "vida.h"
#include <QFont>
Vida::Vida(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    vida=3;
    setPlainText(QString("Vidas: ") + QString::number(vida+1));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Veces",16));
}

void Vida::Disminuir()
{
    vida--;
    setPlainText(QString("Vidas: ") + QString::number(vida+1));
}

int Vida::GetVida()
{
    return vida;
}

void Vida::setVida(int newVida)
{
    vida = newVida;
}
