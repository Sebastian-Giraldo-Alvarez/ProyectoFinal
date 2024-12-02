#include "escombros.h"
#include <QTimer>
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "explosion.h"
Escombros::Escombros(int Escom, Vida *vida) {
    vida_=vida;
    explos= new QMediaPlayer();
    audioOutput = new QAudioOutput();
    explos->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.01); // Ajusta el volumen
    explos->setSource(QUrl("qrc:/sounds/Imagenes/Explosionmus.mp3"));
    if(Escom==1){
        setRect(0,0,100,50);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro1");
        QBrush brush(texturaBala.scaled(100,100,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==2){
        setRect(0,0,100,60);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro2");
        QBrush brush(texturaBala.scaled(100,100,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==3){
        setRect(0,0,75,100);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro3");
        QBrush brush(texturaBala.scaled(100,100,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==4){
        setRect(0,0,40,80);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro4");
        QBrush brush(texturaBala.scaled(80,80,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==5){
        setRect(0,0,40,40);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro5");
        QBrush brush(texturaBala.scaled(40,40,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==6){
        setRect(0,0,40,80);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro6");
        QBrush brush(texturaBala.scaled(80,80,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(50);
    }
    else if(Escom==7){
        setRect(0,0,30,40);
        QPixmap texturaBala("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Escombro7");
        QBrush brush(texturaBala.scaled(40,40,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
        setBrush(brush);
        QPen pen(Qt::NoPen);
        setPen(pen);
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(MoverEscombro()));
        timer->start(500);
    }

}

void Escombros::MoverEscombro()
{
    int vidas=vida_->GetVida();
    velocityY += gravity;
    setPos(x(),y()+velocityY);
    explosion_++;
    Explosion * explosion=new Explosion;
    explosion->setPos(x(),613);
    if(pos().y()>650){//Cuando la figura pase totalmente la vista
        scene()->addItem(explosion);
        explos->play();
        if(vidas==0){
            emit JuegoPerdido();
        }
        else{
            vida_->Disminuir();
            scene()->removeItem(this);
            delete this;
        }

        //qDebug()<<"Se elimino";
    }
}

