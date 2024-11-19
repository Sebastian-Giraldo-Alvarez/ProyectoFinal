#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsTextItem>
class Puntaje:public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem * parent=0);
    void Aumentar();
    int GetPuntaje();
    void setPuntaje(int newPuntaje);

private:
    int puntaje;
};

#endif // PUNTAJE_H
