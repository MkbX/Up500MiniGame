#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "enemy.h"
#include "player.h"
#include "score.h"

extern Score *gameScore;
extern QGraphicsScene *spaceScene;

/**
 * @brief Enemy::Enemy : pixmap of enemy constructed without parent
 * @param parent : null pointer
 */

Enemy::Enemy(QGraphicsPixmapItem *parent): QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/images/alien.png"));

    timerMoveEnemy = new QTimer(this);
    connect(timerMoveEnemy, SIGNAL(timeout()),this, SLOT(moveEnemy()));
    timerMoveEnemy->start(15);
}

/**
 * @brief Enemy::moveEnemy : checks collision with player and move enemy
 * if collision occurs, the game is over
 */

void Enemy::moveEnemy()
{
    QList<QGraphicsItem*> colitPlayer = collidingItems();

    for(int i=0; i<collidingItems().size();i++) {
        if(typeid(*(colitPlayer[i])) == typeid(Player)){
            playerEnd = new QMediaPlayer;
            playerEnd->setMedia(QUrl("qrc:/sound/Pklams.wav"));
            playerEnd->setVolume(25);
            if (playerEnd->state()==QMediaPlayer::PlayingState) {
                playerEnd->setPosition(0);
            }

            else if (playerEnd->state()==QMediaPlayer::StoppedState) {
                playerEnd->play();
            }
            scene()->removeItem(colitPlayer[i]);
            scene()->removeItem(this);
            delete colitPlayer[i];
            this->deleteLater();
            qDebug() << "End of player!";

            spaceScene->clear();
            QGraphicsTextItem *title = new QGraphicsTextItem("GAME OVER");
            title->setPos(300,250);
            title->setFont(QFont("Georgia", 20, QFont::Bold,QFont::StyleItalic));
            title->setDefaultTextColor(Qt::white);
            spaceScene->addItem(title);
        }

    }
    setPos(x()-5,y());

    if(x()+pixmap().rect().width()<0) {        
        this->deleteLater();
        gameScore->majScoreEnemyEscaped();
        qDebug() << "Enemy escaped!";

    }
}
