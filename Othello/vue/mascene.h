#ifndef MASCENE_H
#define MASCENE_H
#include <QGraphicsScene>
#include <QMouseEvent>
#include "pattern/observateur.h"
#include "metier/othello.h"
/*!
 * \brief The maScene class
 */
class maScene : public QGraphicsScene, public Observateur
{
private:
    Othello * ot;
public:
    /*!
     * \brief maScene creer une instance de maScene
     * \param otel SujetDObservation
     * \param parent objet parent
     */
    maScene(Othello *otel, QObject *parent=0);
    ~maScene();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void rafraichir(SujetDObservation *sdo);


};

#endif // MASCENE_H
