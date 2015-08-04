#ifndef VUETEXTE_H
#define VUETEXTE_H
#include <QLabel>
#include "pattern/observateur.h"
#include "pattern/sujetdobservation.h"
#include "metier/othello.h"
class VueTexte : public QLabel, public Observateur
{
public:
    VueTexte(Othello *sdo, QWidget *parent=0);
    void rafraichir(SujetDObservation *sdo);
    ~VueTexte();
private:
    Othello *othello;
};

#endif // VUETEXTE_H
