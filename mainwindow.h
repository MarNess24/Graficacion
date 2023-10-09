// Layla Vanessa González Martínez 21130868

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent ( QKeyEvent *evento );

private slots:
    void dragon ( int limite, QPainter *canvas );
    void arabesco ( int limite, QPainter *canvas );
    void henon (  int limite, QPainter *canvas );
    void malthus1 ( int limite, QPainter *canvas );
    void malthus2 ( int limite, QPainter *canvas );
    void mandel ( int limite, QPainter *canvas );

private:
    Ui::MainWindow *ui;

    QTimer *timerG;
    QTimer *timerA;
    QTimer *timerH;
    QTimer *timerM;
    QTimer *timerN;
    QTimer *timerE;

    void paintEvent ( QPaintEvent *evento );
    int li, ls; // límite inferior y límite superior
    bool band;

    void generarDragon ( QPainter * canvas );
    int EjeX[4098], EjeY [4098], paso, signo;
    void generarArabesco ( QPainter * canvas );

    void confinadorHenon ( int limite, QPainter * canvas );
    int maxX, maxY;
    double escalaX, escalaY, despX, despY;

    void crecimientoMalthusiano ( int limite, QPainter * canvas );
    int malMaxX, malMaxY, maxGen = 0x00FF;

    void confinadorMalthus2 ( int limite, QPainter * canvas );
    int mal2MaxX, mal2MaxY;

    int maxiX, maxiY, i, j, pasos;
    bool terminar;
    double pasoX, pasoY, posX, posY, origX, origY, dimX, dimY, iterX, iterY, tempX;

};
#endif // MAINWINDOW_H
