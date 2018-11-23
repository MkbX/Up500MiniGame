#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "shot.h"
#include "enemy.h"
#include "score.h"

extern Score *gameScore;

/**
 * @brief Shot::Shot : pixmap of shot constructed without parent
 * @param parent : null pointer
 */

Shot::Shot(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/images/tir.png"));

    timerMoveShot = new QTimer(this);
    connect(timerMoveShot, SIGNAL(timeout()),this, SLOT(moveShot()));
    timerMoveShot->start(15);
}

/**
 * @brief Shot::moveShot  : checks collision with enemy and moves shot
 * if collision occurs, suppress enemy and shot
 */

void Shot::moveShot()
{
    QList<QGraphicsItem*> colit = collidingItems();

    for(int i=0; i<collidingItems().size();i++) {
        if(typeid(*(colit[i])) == typeid(Enemy)) {
            enemyEnd = new QMediaPlayer;
            enemyEnd->setMedia(QUrl("qrc:/sound/Asound.wav"));
            enemyEnd->setVolume(25);
            if (enemyEnd->state()==QMediaPlayer::PlayingState) {
                enemyEnd->setPosition(0);
            }

            else if (enemyEnd->state()==QMediaPlayer::StoppedState) {
                enemyEnd->play();
            }
            scene()->removeItem(colit[i]);
            scene()->removeItem(this);
            delete colit[i];
            this->deleteLater();
            gameScore->majScoreEnemyEnd();
            qDebug() << "End of enemy!";
        }

    }
    setPos(x()+15,y());

    if(x()+pixmap().rect().width()>800) {
        //timerMoveShot->stop();
        this->deleteLater();
        qDebug() << "Shot deleted!";
    }
}
