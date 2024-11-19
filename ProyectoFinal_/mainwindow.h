#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "personaje.h"
#include "puntaje.h"
#include "vida.h"
#include "monorriel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void PerderJuego();
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsView * view;
    Personaje *Jugador1;
    Puntaje * puntaje;
    Vida * vida;
    Monorriel * monorriel;
    //void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
