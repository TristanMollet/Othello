#include "vuegraphique.h"
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
VueGraphique::VueGraphique(Othello *sdo, QWidget *parent) : QWidget(parent),othello(sdo)
{
    othello->attacher(this);
    rafraichir(othello);
}

void VueGraphique::rafraichir(SujetDObservation *sdo)
{

    QGridLayout *gridLayout;
    gridLayout = new QGridLayout();
    if(othello=dynamic_cast<Othello*>(sdo)){
        for (int i=0;i<othello->getGrille()->getLargeur();i++){
            for(int j=0;j<othello->getGrille()->getLongueur();j++){
                QLabel * lb;
                lb = new QLabel;
                if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::VIDE){
                    //charger image vide

                    lb->setPixmap(QPixmap{":ressource/imageOthello/vide.jpg"});
                    gridLayout->addWidget(lb);
                }else if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::NOIR){
                    //charger image noir
                    lb->setPixmap(QPixmap{":ressource/imageOthello/noir.jpg"});
                    gridLayout->addWidget(lb);
                }else if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::BLANC){
                    //charger image blanc
                    lb->setPixmap(QPixmap{":ressource/imageOthello/blanc.jpg"});
                    gridLayout->addWidget(lb);
                }
                //ajouter au layout
            }
        }
        this->setLayout(gridLayout);
    }
}

VueGraphique::~VueGraphique()
{
    othello->detacher(this);
}


