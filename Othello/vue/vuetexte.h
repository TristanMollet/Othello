#ifndef VUETEXTE_H
#define VUETEXTE_H
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include "pattern/observateur.h"
#include "pattern/sujetdobservation.h"
#include "metier/othello.h"
class VueTexte : public QWidget, public Observateur
{
    Q_OBJECT
public:
    VueTexte(Othello *sdo, QWidget *parent=0);
    void rafraichir(SujetDObservation *sdo);
    ~VueTexte();
private:
    Othello *othello;
    QPushButton *jouer;
    QComboBox *colonne;
    QComboBox *ligne;
    QLabel *label;
    QLabel *courant;
private slots:
    void clicJouer();

};

#endif // VUETEXTE_H
