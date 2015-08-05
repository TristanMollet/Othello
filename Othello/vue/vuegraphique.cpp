#include "vuegraphique.h"
#include <QGridLayout>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
VueGraphique::VueGraphique(Othello *sdo, QWidget *parent) : QGraphicsView(parent),othello(sdo)
{
    maScene = new QGraphicsScene(this);
    setScene(maScene);
    //QPixmap image;
    //image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/vide.jpg");
    //maScene->addPixmap(image);
    othello->attacher(this);
    rafraichir(othello);
}

void VueGraphique::rafraichir(SujetDObservation *sdo)
{
    QGraphicsItem *item;

    QPixmap image;

    int   width = 0;
    int   heigth = 0;
    //QGridLayout *gridLayout;
    //gridLayout = new QGridLayout();
    if(othello=dynamic_cast<Othello*>(sdo)){
        for (int i=0;i<othello->getGrille()->getLargeur();i++){
            for(int j=0;j<othello->getGrille()->getLongueur();j++){
                //QLabel * lb;
                //lb = new QLabel;
                if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::VIDE){
                    //charger image vide
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/vide.jpg");
                    image = image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    item =maScene->addPixmap(image);
                    item->setPos(width,heigth);
                    width += 50;
                    //lb->setPixmap(QPixmap{":ressource/imageOthello/vide.jpg"});
                    //gridLayout->addWidget(lb);
                }else if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::NOIR){
                    //charger image noir
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/Noir.jpg");
                    image = image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    item =maScene->addPixmap(image);
                    item->setPos(width,heigth);
                    width += 50;
                    //lb->setPixmap(QPixmap{":ressource/imageOthello/noir.jpg"});
                    //gridLayout->addWidget(lb);
                }else if(othello->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::BLANC){
                    //charger image blanc
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/Blanc.jpg");
                    image = image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    item =maScene->addPixmap(image);
                    item->setPos(width,heigth);
                    width += 50;
                    //lb->setPixmap(QPixmap{":ressource/imageOthello/blanc.jpg"});
                    //gridLayout->addWidget(lb);
                }
                //ajouter au layout
            }
            heigth += 50;
            width = 0;
        }
        heigth += 50;
        width = 0;
        //this->setLayout(gridLayout);
    }
}

VueGraphique::~VueGraphique()
{
    othello->detacher(this);
}


