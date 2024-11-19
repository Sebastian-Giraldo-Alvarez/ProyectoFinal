#ifndef VIDA_H
#define VIDA_H
#include <QGraphicsTextItem>
class Vida:public QGraphicsTextItem
{
public:
    Vida(QGraphicsItem * parent=0);
    void Disminuir();
    int GetVida();
    void setVida(int newVida);

private:
    int vida;
};

#endif // VIDA_H
