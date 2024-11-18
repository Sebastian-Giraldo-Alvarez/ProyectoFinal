#include "personaje.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include "bala.h"
Personaje::Personaje(int x, int y, QObject *parent): QObject (parent){
    _x = x;
    _y = y;
    setPos(x*20, y*20);
    Derecha[0]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa1Derecha.PNG");
    Derecha[0] = Derecha[0].scaled(100, 100, Qt::KeepAspectRatio);
    Derecha[1]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa2Derecha.PNG");
    Derecha[1] = Derecha[1].scaled(100, 100, Qt::KeepAspectRatio);
    Derecha[2]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa3Derecha.PNG");
    Derecha[2] = Derecha[2].scaled(100, 100, Qt::KeepAspectRatio);
    Izquierda[0]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa1Izquierda.PNG");
    Izquierda[0] = Izquierda[0].scaled(100, 100, Qt::KeepAspectRatio);
    Izquierda[1]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa2Izquierda.PNG");
    Izquierda[1] = Izquierda[1].scaled(100, 100, Qt::KeepAspectRatio);
    Izquierda[2]=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteLisa3Izquierda.PNG");
    Izquierda[2] = Izquierda[2].scaled(100, 100, Qt::KeepAspectRatio);
    Disparo=QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/SpriteDisparo.PNG");
    Disparo = Disparo.scaled(150, 150, Qt::KeepAspectRatio);
    setPixmap(Derecha[0]);
    UsandoSprite=true;
}
Personaje::~Personaje() {
    scene()->removeItem(this);
}

void Personaje::Mover(char dir)
{
    setFocus();
    if(dir=='A'){
        _x--;
        setPos(_x*20,_y*20);
        CambiarSpriteIzquierda();
    }
    else if(dir=='D'){
        _x++;
        setPos(_x*20,_y*20);
        CambiarSpriteDerecha();
    }
    else if(dir=='E'){
        Bala *bala=new Bala();
        bala->setPos(_x*20,_y*20);
        scene()->addItem(bala);
        CambiarSpriteDisparo();
    }
}

void Personaje::CambiarSpriteDerecha()
{
    if (UsandoSprite&&!UsandoSprite2) {
        setPixmap(Derecha[1]);
        UsandoSprite2=!UsandoSprite2;
    }else if(UsandoSprite&&UsandoSprite2){
        setPixmap(Derecha[0]);
        UsandoSprite = !UsandoSprite;
    }
    else if(!UsandoSprite&&UsandoSprite2){
        setPixmap(Derecha[2]);
        UsandoSprite = !UsandoSprite;
        UsandoSprite2=!UsandoSprite2;
    }
}
void Personaje::CambiarSpriteIzquierda()
{
    if (UsandoSprite&&!UsandoSprite2) {
        setPixmap(Izquierda[1]);
        UsandoSprite2=!UsandoSprite2;
    }else if(UsandoSprite&&UsandoSprite2){
        setPixmap(Izquierda[0]);
        UsandoSprite = !UsandoSprite;
    }
    else if(!UsandoSprite&&UsandoSprite2){
        setPixmap(Izquierda[2]);
        UsandoSprite = !UsandoSprite;
        UsandoSprite2=!UsandoSprite2;
    }
}

void Personaje::CambiarSpriteDisparo()
{
    setPixmap(Disparo);
}

