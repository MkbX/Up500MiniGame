#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <QKeyEvent>

#include "player.h"
#include "shot.h"
#include "enemy.h"
#include "pixstar.h"

/**
 * @brief Player::Player : pixmap of player constructed without parent
 * @param parent : null pointer
 */

Player::Player(QGraphicsPixmapItem *parent): QGraphicsPixmapItem (parent)
{
    setPos(0,200);
    setPixmap(QPixmap(":/images/ship.png"));
    shotSound = new QMediaPlayer;
    shotSound->setMedia(QUrl("qrc:/sound/Shoot.wav"));
    shotSound->setVolume(25);
}

/**
 * @brief Player::keyPressEvent : changes postion of player when arrow keys pressed and creates shot when space key used
 * @param event : parameter sent to player when input pressed on keyboard
 */

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (x()>0) {
            qDebug() << "Left!";
            setPos(x()-15,y());
        }
    } else if (event->key() == Qt::Key_Right) {
        if (x()+pixmap().rect().width()<800) {
            qDebug() << "Right!";
            setPos(x()+15,y());
        }
    } else if (event->key() == Qt::Key_Up) {
        if (y()>50){
            qDebug() << "Up!";
            setPos(x(),y()-15);
        }
    } else if (event->key() == Qt::Key_Down) {
        if (y()+pixmap().rect().height()<560) {
            qDebug() << "Down!";
            setPos(x(),y()+15);
        }
    }  else if (event->key() == Qt::Key_Space) {
            qDebug() << "Shoot!";
            Shot *blueShot = new Shot();
            blueShot->setPos(this->x()+this->pixmap().rect().width(),this->y()+pixmap().rect().height()/2);
            scene()->addItem(blueShot);

            if (shotSound->state() == QMediaPlayer::PlayingState) {
                shotSound->setPosition(0);
            }
            else if (shotSound->state() == QMediaPlayer::StoppedState) {
                shotSound->play();
            }

    }

}

/**
 * @brief Player::focusOutEvent : if player's focus lost, restores it
 */

void Player::focusOutEvent(QFocusEvent */*param unused*/)
{
    this->setFocus();
}

/**
 * @brief Player::generatePixStar : randomly adds star
 */

void Player::generatePixStar()
{
    int random1, random2;
    random1 = rand() % 800;
    random2 = rand() % 600;

    PixStar *starPoint = new PixStar;
    starPoint->setPos(random1,random2);
    scene()->addItem(starPoint);
}

/**
 * @brief Player::generateEnemy : randomly adds enemies
 */

void Player::generateEnemy()
{
    int random;
    random = 60 + rand() % 480;
    Enemy *enemyA = new Enemy;
    enemyA->setPos(800,random);
    scene()->addItem(enemyA);
}
