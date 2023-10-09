// Layla Vanessa González Martínez 21130868

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow ( QWidget *parent )
    : QMainWindow ( parent )
    , ui ( new Ui::MainWindow )
{
    ui -> setupUi ( this );

    li = 0;
    ls = 12;
    band = false;

    // Inicializar los timers
    timerG = new QTimer();
    timerA = new QTimer();
    timerH = new QTimer();
    timerM = new QTimer();
    timerN = new QTimer();
    timerE = new QTimer();

    // Conectarlos
    connect ( timerG, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );
    connect ( timerA, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );
    connect ( timerH, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );
    connect ( timerM, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );
    connect ( timerN, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );
    connect ( timerE, SIGNAL ( timeout() ), this, SLOT ( repaint() ) );

    // Agregar iniciar, detener y salir. Tambi[en los demás para hacer los fractales
    ui -> statusbar -> addPermanentWidget ( ui -> label_Dragon, 1 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Arabesco, 2 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Henon, 3 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Malthus1, 4 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Malthus2, 5 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Mandel, 5 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Detener, 7 );
    ui -> statusbar -> addPermanentWidget ( ui -> label_Salir, 8 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent ( QKeyEvent *evento )
{
    // Detener cada timer cuando inicie otro
    timerG -> stop();
    timerA -> stop();
    timerH -> stop();
    timerM -> stop();
    timerN -> stop();
    timerE -> stop();

    if ( evento -> key() == Qt::Key_G ) {
        band = true;
        timerG -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_A ) {
        band = true;
        timerA -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_H ) {
        band = true;
        timerH -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_M ) {
        band = true;
        timerM -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_N ) {
        band = true;
        timerN -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_E ) {
        band = true;
        timerE -> start ( 50 );
        update();
    }

    if ( evento -> key() == Qt::Key_D ) {
        timerG -> stop();
        timerA -> stop();
        timerH -> stop();
        timerM -> stop();
        timerN -> stop();
        timerE -> stop();
    }

    if ( evento -> key() == Qt::Key_S ) {
        close();
    }
}

void MainWindow::dragon ( int limite, QPainter *canvas )
{
    int i;
    paso = 4096;
    signo = -1;

    EjeX[1] = 800 / 4;
    EjeX[4097] = 3 * 800 / 4;

    EjeY[1] = EjeY[4097] = 2 * 550 / 3;

    canvas -> setPen ( QColor::fromRgb( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas -> font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont ( "RockWell", 20 ) );
    canvas -> drawText ( 200, 50, "CURVA FRACTAL DEL DRAGÓN" );
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    canvas -> drawLine ( EjeX[1], EjeY[1], EjeX[4097], EjeY[4097] );

    for ( i=1; i<=limite; i++ ) {
        canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
        generarDragon ( canvas );
        paso /= 2;
    }
}

void MainWindow::arabesco ( int limite, QPainter *canvas )
{
    int i;
    paso = 4096;
    signo = -1;

    EjeX[1] = canvas -> window().width() / 4;
    EjeX[4097] = 3 * canvas -> window().width() / 4;

    EjeY[1] = EjeY[4097] = 2 * 675 / 3;

    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas -> font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont ( "RockWell", 20 ) );
    canvas -> drawText( 360, 520, "ARABESCO" );
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    canvas -> drawLine ( EjeX[1], EjeY[1], EjeX[4097], EjeY[4097] );

    for ( i=1; i<=limite; i++ ){
        canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
        generarArabesco ( canvas );
        paso /= 2;
    }
}

void MainWindow::henon ( int limite, QPainter *canvas )
{
    escalaX = 1;
    escalaY = 1;
    despX = 0;
    despY = 0;
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas -> font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont ( "RockWell", 20 ) );
    canvas -> drawText ( 250, 50, "CONFINADOR DE HENON" );

    canvas -> setFont ( QFont ( "RockWell", 12 ) );
    canvas -> drawText ( 180, 290, QString ( "EscalaX = %1" ).arg ( escalaX, 5, 'f', 2 ) );
    canvas -> setFont ( QFont ( "RockWell", 12 ) );
    canvas -> drawText ( 180, 315, QString ( "EscalaY = %1" ).arg ( escalaY, 5, 'f', 2 ) );
    canvas -> setFont ( QFont ( "RockWell", 12 ) );
    canvas -> drawText ( 180, 340, QString ( "DespX = %1" ).arg ( despX, 8, 'f', 2 ) );
    canvas -> setFont ( QFont ( "RockWell", 12 ) );
    canvas -> drawText ( 180, 365, QString ( "DespY = %1" ).arg ( despY, 8, 'f', 2 ) );

    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    confinadorHenon (limite, canvas );
}

void MainWindow::malthus1 ( int limite, QPainter *canvas )
{
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas->font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont( "RockWell", 20 ) );
    canvas -> drawText ( 295, 520, "FLUJO MALTUSIANO" );

    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    crecimientoMalthusiano (limite, canvas );
}

void MainWindow::malthus2( int limite, QPainter *canvas )
{
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas -> font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont ( "RockWell", 20 ) );
    canvas -> drawText ( 285, 70, "FLUJO MALTUSIANO 2" );

    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    confinadorMalthus2 (limite, canvas );
}

void MainWindow::mandel(int limite, QPainter *canvas )
{
    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
    QFont fuente = canvas -> font();
    fuente.setPointSize ( fuente.pointSize() * 2 );
    canvas -> setFont ( QFont( "RockWell", 20 ) );
    canvas -> drawText ( 350, 530, "MANDELBROT" );

    maxiX = 900;
    maxiY = 600;

    origX = -2.0;
    origX = -1.25;
    dimX = 0.5;
    dimY = 1.25;

    pasoX = ( dimX - origX ) / maxiX;
    pasoY = ( dimY - origY ) / maxiY;

    for ( i=0; i <= maxiX; i++ ) {

        for ( j=0; j <= maxiY; j++ ) {

            // Inicia el valor para la posición
            posX = origX + i * pasoX;
            posY = origY + j * pasoY;

            // Darles de valor inicial 0 a iterX, iterY y los pasos
            iterX = 0.0;
            iterY = 0.0;
            pasos = 0;
            terminar = false;

            while ( !terminar ) {

                tempX = ( iterX * iterX ) - ( iterY * iterY ) + posX;
                iterY = 2 * ( iterX * iterY ) + posY;
                iterX = tempX;
                pasos++;

                if ( hypot ( fabs ( iterX ), fabs ( iterY ) ) >= 2.0 || pasos >= limite) {
                    terminar = true;
                }

                if ( pasos >= limite ) {
                    canvas -> setPen ( QColor::fromRgb ( rand()%255, rand()%255, rand()%255 ) );
                } else {
                    canvas -> setPen ( QColor ( 255, 255, 255 ) );
                }

                 canvas -> drawPoint( i, j );
            }
        }
    }
}

void MainWindow::paintEvent ( QPaintEvent *evento )
{
    Q_UNUSED ( evento );

    QPainter *Canvas = new QPainter ( this );

    li = 0;

    if ( band ) {
        if ( li <= ls ) {

            if ( timerG -> isActive() ) {
                dragon ( li, Canvas );
                ls = 12;
                li++;
            }

            if ( timerA -> isActive() ) {
                arabesco ( li, Canvas );
                ls = 12;
                li++;
            }

            if ( timerH -> isActive() ) {
                ls = 0x02FF;
                henon ( li, Canvas );
                li++;
            }

            if ( timerM -> isActive() ) {
                ls = 151;
                malthus1 ( li, Canvas );
                li++;
            }

            if ( timerN -> isActive() ) {
                ls = 1000;
                malthus2 ( li, Canvas );
                li++;
            }

            if ( timerE -> isActive() ) {
                ls = 10;
                mandel ( li, Canvas);
                li++;
            }

        }

        else {
            band = false;
        }

    }

    if ( !band ) {
        li--;

        if ( timerG -> isActive() ) {
            dragon ( li, Canvas );
        }

        if ( timerA -> isActive() ) {
            arabesco ( li, Canvas );
        }

        if ( timerH -> isActive() ) {
            henon ( li, Canvas );
        }

        if ( timerM -> isActive() ) {
            malthus1 ( li, Canvas );
        }

        if ( timerN -> isActive() ) {
            malthus2 ( li, Canvas );
        }

        if ( timerE -> isActive() ) {
            mandel ( li, Canvas );
        }

        if ( li == 0 ) {
            band = true;
        }

    }

    Canvas -> end();
}

void MainWindow::generarDragon ( QPainter *canvas )
{
    int j, dx, dy;

    j = paso / 2;

    for ( int i=1; i <= 4096; i += paso ) {
        dx = EjeX [paso + i] - EjeX[i];
        dy = EjeY [paso + i] - EjeY[i];
        signo *= -1;
        EjeX[i + j] = EjeX[i] + ( dx + ( dy * signo ) ) / 2;
        EjeY[i + j] = EjeY[i] + ( dy - ( dx * signo ) ) / 2;

        canvas -> drawLine ( EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j] );
        canvas -> drawLine ( EjeX[i+j], EjeY[i+j], EjeX[i+paso], EjeY[i+paso] );
    }
}

void MainWindow::generarArabesco ( QPainter *canvas )
{
    int j, dx, dy;

    j = paso / 2;

    for ( int i=1; i <= 4096; i += paso ) {
        dx = EjeX [paso + i] - EjeX[i];
        dy = EjeY [paso + i] - EjeY[i];
        signo = 1;
        signo *= 1;

        EjeX[i + j] = EjeX[i] + ( dx + ( dy * signo ) ) / 2;
        EjeY[i + j] = EjeY[i] + ( dy - ( dx * signo ) ) / 2;

        canvas -> drawLine ( EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j] );
        canvas -> drawLine ( EjeX[i+j], EjeY[i+j], EjeX[i+paso], EjeY[i+paso] );
    }
}

void MainWindow::confinadorHenon( int limite, QPainter *canvas )
{
    int posX, posY, color;
    double Xant, Xnuevo, Yant, Ynuevo;
    maxX = 800;
    maxY = 600;
    Xant = Xnuevo = Yant = Ynuevo = 0;

    for ( color = 1; color <= 15; color++ ) {
        for ( int i = 1; i <= limite; i++ ) {
            Xnuevo = Yant + 1 - ( 1.4 * Xant * Xant );
            Ynuevo = 0.3 * Xant;

            despX = ( canvas -> window().width() - maxX * escalaX ) / 2;
            despY = ( 650 - maxY * escalaY ) / 2;

            posX = ( Xnuevo * maxX / 3 * escalaX ) + maxX / 2 + despX;
            posY = ( Ynuevo * maxY * escalaY ) + maxY / 2 + despY;


            if ( ( posX >= 0 ) && ( posX <= maxX ) && ( posY >= 0 ) && ( posY <= maxY ) ) {
                canvas -> drawPoint ( posX, posY );
            }

            Yant = Ynuevo;
            Xant = Xnuevo;

        }
    }
}

void MainWindow::crecimientoMalthusiano ( int limite, QPainter *canvas )
{
    int cont, x, y;
    double pobAnt, pobNueva, razon;

    malMaxX = 850;
    malMaxY = 600;

    razon = 2.3;

    despX = ( canvas -> window().width() - malMaxX * escalaX ) / 2;
    despY = ( canvas -> window().height() - malMaxY * escalaY ) / 2;

    for ( int j = 1; j <= 151; j++ ) {
        cont = 0;
        razon += 0.01;
        pobAnt = 0.01;

        for ( int i = 1; i <= limite; i++ ) {
            pobNueva = razon * ( pobAnt * ( 1 - pobAnt ) );
            x = pobAnt * malMaxX;
            y = malMaxY - (pobNueva * malMaxY);

            canvas -> drawPoint ( x, y );

            if ( pobAnt == pobNueva ) {
                cont++;
            } else {
                cont = 0;
            }

            if ( cont > 10 ) {
                i = maxGen;
            }

            pobAnt = pobNueva;
        }

    }
}

void MainWindow::confinadorMalthus2 ( int limite, QPainter *canvas )
{
    int cont;
    double pobAnt, pobNueva, x, y, razon;
    mal2MaxX = 1000;
    mal2MaxY = 600;

    razon = 2.3;
    y = 0;

    for ( int j = 1; j <= 15; j++ ) {

        for ( int k = 1; k <= limite; k++ ) {
            cont = 0;
            razon += 0.01;
            pobAnt = 0.1;

            for ( int i = 1; i <= 1000; i++ ) {
                pobNueva = razon * ( pobAnt * ( 1 - pobAnt ) );
                x = pobNueva - pobAnt;

                canvas -> drawPoint ( ( x * mal2MaxX / 2 ) + mal2MaxX / 2, ( mal2MaxY / 2 ) - ( y * mal2MaxY / 2 ) );

                if ( pobAnt == pobNueva ) {
                    cont++;
                } else {
                    cont = 0;
                }

                if( cont > 100 ) {
                    i = 10000;
                }

                pobAnt = pobNueva;
                y = x;
            }
        }
    }
}
