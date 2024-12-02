#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QGraphicsView();//pasos principales para tener la escena
    scene =new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);//tamaño escena
    scene->clearFocus();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Quitar barras
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1280,720);//tamaño vista
    setCentralWidget(view);
    QPixmap bk =  QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Fondo").scaled(1280,720,Qt::KeepAspectRatio);
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(bk);
    if (bk.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del fondo.";
    } else {
        qDebug() << "Imagen del fondo cargada correctamente.";
    }
    fondo->setPos(0, 0);  // Posicionar la imagen en el origen de la escena
    scene->addItem(fondo);
    setWindowTitle(tr("¡The Monorail attack!"));
    QGraphicsRectItem* paredInferior = scene->addRect(0, 700, 1300, 20); // Pared inferior
    QPixmap texturaBloques("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Pasto");
    QBrush brush(texturaBloques.scaled(20,20,Qt::KeepAspectRatio));  // Crear un pincel con la textura cargada
    paredInferior->setBrush(brush);
    QPen pen(Qt::NoPen);        // Sin borde (bordes sin color.)
    paredInferior->setPen(pen);
    puntaje=new Puntaje;
    scene->addItem(puntaje);
    vida=new Vida;
    scene->addItem(vida);
    vida->setPos(120,0);
    Jugador1=new Personaje(30,30, puntaje);
    setFocus();
    scene->addItem(Jugador1);
    monorriel=new Monorriel(vida);
    monorriel->setPos(0,20);
    scene->addItem(monorriel);
    connect(monorriel, &Monorriel::JuegoPerdido, this, &MainWindow::PerderJuego);
    QMediaPlayer *musica = new QMediaPlayer();
    QAudioOutput *audioOutput = new QAudioOutput();
    musica->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.01); // Ajusta el volumen
    musica->setSource(QUrl("qrc:/sounds/Imagenes/SonidoBack.mp3"));
    musica->play();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        Jugador1->Mover('A');
    }
    else if(event->key()==Qt::Key_D){
        Jugador1->Mover('D');
    }
    else if(event->key()==Qt::Key_E){
        Jugador1->Mover('E');
    }

}

void MainWindow::PerderJuego()
{
    /*QMessageBox* mensaje = new QMessageBox(QMessageBox::Information,
                                           "Fin del juego",
                                           "¡Perdiste el juego!",
                                           QMessageBox::NoButton,
                                           this);
    mensaje->show();*/
    this->close();
}
MainWindow::~MainWindow()
{
    delete ui;
}
