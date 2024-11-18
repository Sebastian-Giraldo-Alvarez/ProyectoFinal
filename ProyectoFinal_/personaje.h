#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
class Personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Personaje(int x, int y, QObject *parent = nullptr);
    ~Personaje();
    void Mover(char dir);
    QPixmap SepararSpirte(int X_,int Y_, int Alto, int Ancho, char * path);
    void CambiarSpriteDerecha();
    void CambiarSpriteIzquierda();
    void CambiarSpriteDisparo();

private:
    int _x;
    int _y;
    QPixmap Derecha[3];
    QPixmap Izquierda[3];
    QPixmap Disparo;
    bool UsandoSprite=false,UsandoSprite2=false;
};

#endif // PERSONAJE_H
