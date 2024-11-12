#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QGraphicsView();//pasos principales para tener la escena
    scene =new QGraphicsScene();
    scene->setSceneRect(0,0,1080,720);//tamaño escena
    scene->clearFocus();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Quitar barras
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1080,720);//tamaño vista
    setCentralWidget(view);
    setWindowTitle(tr("¡The Monorail attack!"));
    setWindowIcon(QPixmap("/Users/sebas/OneDrive/Escritorio/ProyectoFinal/ProyectoFinal_/Imagenes/Logo"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
