#ifndef ESCOMBROS_H
#define ESCOMBROS_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene> // Paquete para control de scena
#include <QGraphicsView> // paquete para vistas.
#include "vida.h"
#include "explosion.h"
#include <QMediaPlayer>
#include <QAudioOutput>
class Escombros:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Escombros(int Escom, Vida*vida);
public slots:
    void MoverEscombro();
signals:
    void JuegoPerdido();
private:
    Vida *vida_;
    int explosion_=0;
    float gravity = 0.9f;
    float velocityY = 0.0f;
    QMediaPlayer *explos;
    QAudioOutput *audioOutput;
};

#endif // ESCOMBROS_H
