#ifndef VUEGRAPHIQUE_H
#define VUEGRAPHIQUE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "pattern/observateur.h"
#include "metier/othello.h"

class VueGraphique : public QGraphicsView, public Observateur
{
    Q_OBJECT
public:
    explicit VueGraphique(Othello *sdo, QWidget *parent = 0);
    void rafraichir(SujetDObservation *sdo);
    ~VueGraphique();
private:
    Othello * othello;
    QGraphicsScene * maScene;

signals:

public slots:
};

#endif // VUEGRAPHIQUE_H
