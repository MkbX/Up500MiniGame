#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

/**
 * @brief The Shot class : creates beam from ship
 */

class Shot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Shot(QGraphicsPixmapItem *parent = nullptr);

private:
     QTimer *timerMoveShot;
     QMediaPlayer *enemyEnd;

private slots:
    void moveShot();
};

#endif // SHOT_H
