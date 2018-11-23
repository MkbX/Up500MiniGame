#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

/**
 * @brief The Player class : creates player's ship with sound of shots
 */

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsPixmapItem *parent = nullptr);


private:
    QMediaPlayer *shotSound;
    void keyPressEvent(QKeyEvent *event) override;
    void focusOutEvent(QFocusEvent */*param unused*/) override;

private slots:
    void generatePixStar();
    void generateEnemy();
};

#endif // PLAYER_H
