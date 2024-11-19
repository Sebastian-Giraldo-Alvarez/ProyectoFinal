#include "vida.h"
#include <QFont>
Vida::Vida(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    vida=3;
    setPlainText(QString("Vidas: ") + QString::number(vida) +QString("    !EVITA QUE LOS ESCOMBROS CAIGAN A SPRINGFIELD!"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Veces",16));
}

void Vida::Disminuir()
{
    vida--;
    setPlainText(QString("Vidas: ") + QString::number(vida));
}

int Vida::GetVida()
{
    return vida;
}

void Vida::setVida(int newVida)
{
    vida = newVida;
}
