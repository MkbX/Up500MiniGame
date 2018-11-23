#ifndef PIXSTAR_H
#define PIXSTAR_H

#include <QObject>
#include <QGraphicsEllipseItem>

/**
 * @brief The PixStar class : creates a tiny white circle to simulate a star with an inner timer for movement
 */

class PixStar : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    PixStar();
    QTimer *timerMovePixStar;

private slots:
void movePixStar();

};

#endif // PIXSTAR_H
