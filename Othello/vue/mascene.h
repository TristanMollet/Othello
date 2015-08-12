#ifndef MASCENE_H
#define MASCENE_H
#include <QGraphicsScene>
#include <QMouseEvent>
#include "pattern/observateur.h"
#include "metier/othello.h"
class maScene : public QGraphicsScene, public Observateur
{
private:
    Othello * ot;
public:
    maScene(Othello *otel, QObject *parent=0);
    ~maScene();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void rafraichir(SujetDObservation *sdo);


};

#endif // MASCENE_H
