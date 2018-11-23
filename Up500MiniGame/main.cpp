#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QApplication>
#include <QPropertyAnimation>
#include <QPushButton>

#include "player.h"
#include "score.h"

//Global variables
Score *gameScore;
QGraphicsScene *spaceScene;

/**
 * @bug Sometimes, at startup, only one star is generated...
 */

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   //Set scene in a fixed view (800*600)
   spaceScene= new QGraphicsScene;
   QGraphicsView *view = new QGraphicsView(spaceScene);
   view->setScene(spaceScene);
   spaceScene->setSceneRect(0,0,800,600);
   spaceScene->setBackgroundBrush(QBrush(Qt::black));
   view->setSceneRect(spaceScene->sceneRect());
   view->setFixedSize(view->sizeHint());


   //Title game and score creation
   QGraphicsTextItem *title = new QGraphicsTextItem("UP-500");
   title->setPos(view->width()/2-50,0);
   title->setFont(QFont("Times", 20, QFont::Bold));
   title->setDefaultTextColor(Qt::white);
   spaceScene->addItem(title);
   gameScore = new Score;
   spaceScene->addItem(gameScore);


   //Title game animation
   QPropertyAnimation animation(title,"pos");
   animation.setDuration(2000);
   animation.setStartValue(QPointF(title->x(), title->y()));
   animation.setKeyValueAt(0.25,QPointF(title->x()-20, title->y()));
   animation.setKeyValueAt(0.5,QPointF(title->x()+10, title->y()));
   animation.setEndValue(QPointF(title->x(), title->y()));
   animation.setLoopCount(-1);
   animation.start();


   //Player creation
   Player *p1 = new Player;
   p1->setFlags(QGraphicsRectItem::ItemIsFocusable);
   p1->setFocus();
   spaceScene->addItem(p1);

   //Creation of stars and enemies
   QTimer *timerE= new QTimer;
   QObject::connect(timerE, SIGNAL(timeout()),p1,SLOT(generateEnemy()));
   timerE->start(1250);
   QTimer *timercreation= new QTimer;
   timercreation->start(1);
   QTimer::singleShot(100, timercreation, SLOT(stop()));
   QObject::connect(timercreation, SIGNAL(timeout()),p1,SLOT(generatePixStar()));
   view->show();
   timerE->start(1250);

    return a.exec();
}
