#include "mascene.h"
#include "monitem.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>
maScene::maScene(Othello *otel, QObject *parent) : QGraphicsScene(parent)
{
    ot = otel;
    ot->attacher(this);
    rafraichir(ot);
}

maScene::~maScene()
{
    delete ot;
}

void maScene::rafraichir(SujetDObservation *sdo)
{
    int   width = 0;
    int   heigth = 0;
    if(ot=dynamic_cast<Othello*>(sdo)){
        for (int i=0;i<ot->getGrille()->getLargeur();i++){
            for(int j=0;j<ot->getGrille()->getLongueur();j++){
                monItem *monIt = new monItem(i,j);
                if(ot->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::VIDE){
                    //charger image vide
                    QPixmap image;
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/vide.jpg");
                    image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    monIt->setPixmap(image);
                    monIt->setPos(width,heigth);
                    addItem(monIt);
                    width += 50;
                }else if(ot->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::NOIR){
                    //charger image noir
                    QPixmap image;
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/Noir.jpg");
                    image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    monIt->setPos(width,heigth);
                    monIt->setPixmap(image);
                    addItem(monIt);
                    width += 50;
                }else if(ot->getGrille()->getPlateau()[i][j]->getCouleur()==Couleur::BLANC){
                    //charger image blanc
                    QPixmap image;
                    image.load("C:/Users/Tritan/Documents/GitHub/Othello/Othello/imageOthello/Blanc.jpg");
                    image.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
                    monIt->setPos(width,heigth);
                    monIt->setPixmap(image);
                    addItem(monIt);
                    width += 50;

                }

            }
            heigth += 50;
            width = 0;
        }
        heigth += 50;
        width = 0;

    }
}

void maScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     QGraphicsScene::mousePressEvent(event);
    std::cout << "Dans mousePressEvent"<< std::endl;
    monItem *it;
    if(it =dynamic_cast<monItem*>(itemAt(event->pos().x(), event->pos().y(),QTransform()))){
        std::cout<<"C'est monItem a la ligne : " << it->getLigne() << " et colonne : " << it->getColonne() << std::endl;
        ot->jouerPion(it->getLigne(),it->getColonne());
    }

}

