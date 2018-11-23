#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "pixstar.h"

/**
 * @brief PixStar::PixStar : little white star construction
 */

PixStar::PixStar()
{
    setRect(0,0,1,1);
    setPen(QPen (Qt::white));

    timerMovePixStar = new QTimer(this);
    connect(timerMovePixStar, SIGNAL(timeout()),this, SLOT(movePixStar()));
    timerMovePixStar->start(7);
}

/**
 * @brief PixStar::movePixStar : randomly sets position of star right of the screen and moves it left
 * when position reaches left edge of the screen, it gets back to the right ledge
 */

void PixStar::movePixStar()
{
    int randomY;

    randomY=rand() % 600;
    setPos(x()-1,y());

    if(x()<0)
        setPos(800,randomY);

}
