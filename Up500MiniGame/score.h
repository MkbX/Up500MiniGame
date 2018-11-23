#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>

/**
 * @brief The Score class : points scored
 */

class Score :  public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = nullptr);
    void majScoreEnemyEnd();
    void majScoreEnemyEscaped();

private:
    int gamePoints;
};

#endif // SCORE_H
