#include "score.h"

extern QGraphicsScene *spaceScene;

/**
 * @brief Score::Score  : score's text constructed without parent
 * @param parent : null pointer
 */

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    gamePoints=0;
    setPos(0,560);
    QFont scoreFont("Times", 15, QFont::Bold);

    setFont(scoreFont);
    setDefaultTextColor(Qt::white);
    setPlainText(QString("SCORE : %1").arg(gamePoints));
}

/**
 * @brief Score::majScoreEnemyEnd : adds 10 points when enemy defeated, ends game when points greater than 500
 */

void Score::majScoreEnemyEnd()
{
    gamePoints+=10;
    setPlainText(QString("SCORE : %1").arg(gamePoints));

    if (gamePoints>=500){
        spaceScene->clear();
        QGraphicsTextItem *title = new QGraphicsTextItem("You Win!");
        title->setPos(320,230);
        title->setFont(QFont("Times", 20, QFont::Bold));
        title->setDefaultTextColor(Qt::white);
        spaceScene->addItem(title);
    }
}

/**
 * @brief Score::majScoreEnemyEscaped : substracts 5 points when enemy reaches left edge of screen, ends game when points lesser than -200
 */

void Score::majScoreEnemyEscaped()
{
    gamePoints-=5;
    setPlainText(QString("SCORE : %1").arg(gamePoints));

    if (gamePoints<=-200){
        spaceScene->clear();
        QGraphicsTextItem *title = new QGraphicsTextItem("GAME OVER");
        title->setPos(300,250);
        title->setFont(QFont("Georgia", 20, QFont::Bold,QFont::StyleItalic));
        title->setDefaultTextColor(Qt::white);
        spaceScene->addItem(title);

    }

}
