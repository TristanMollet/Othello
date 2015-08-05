#ifndef VUEGRAPHIQUE_H
#define VUEGRAPHIQUE_H

#include <QWidget>
#include "pattern/observateur.h"
#include "metier/othello.h"

class VueGraphique : public QWidget, public Observateur
{
    Q_OBJECT
public:
    explicit VueGraphique(Othello *sdo, QWidget *parent = 0);
    void rafraichir(SujetDObservation *sdo);
    ~VueGraphique();
private:
    Othello * othello;


signals:

public slots:
};

#endif // VUEGRAPHIQUE_H
