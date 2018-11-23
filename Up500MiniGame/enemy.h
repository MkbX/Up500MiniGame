#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

/**
 * @brief The Enemy class : creates a monster with an inner timer for movement and sound when it collides with player
 */
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QGraphicsPixmapItem *parent = nullptr);

private:
        QTimer *timerMoveEnemy;
        QMediaPlayer *playerEnd;
private slots:
        void moveEnemy();
};

#endif // ENEMY_H
