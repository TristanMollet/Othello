#include "vuetexte.h"
#include "pattern/sujetdobservation.h"

VueTexte::VueTexte(Othello *sdo,QWidget *parent ):QLabel(parent),othello(sdo)
{
    setWindowTitle(tr("Vue texte"));
    Qt::WindowFlags flags {0};
        setWindowFlags(flags);
    setFixedSize(350,450);
    othello->attacher(this);
    rafraichir(othello);
}

void VueTexte::rafraichir(SujetDObservation *sdo){
    QString contenu;
    contenu.append(("<center>"));
    contenu.append(QString::fromStdString(othello->afficher()));

    setText(contenu);
}

VueTexte::~VueTexte(){
    othello->detacher(this);
}
