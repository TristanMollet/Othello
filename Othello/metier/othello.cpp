#include "othello.h"
#include <iostream>
using namespace std;
Othello::Othello()
{
    grille = new Plateau();
    grille->getPlateau()[3][4]->setCouleur(Couleur::NOIR);
    //grille->ajouterJeton('e',4,Couleur::NOIR);
    grille->getPlateau()[4][3]->setCouleur(Couleur::NOIR);
    //grille->ajouterJeton('d',5,Couleur::NOIR);
    grille->getPlateau()[4][4]->setCouleur(Couleur::BLANC);
    //grille->ajouterJeton('d',4,Couleur::BLANC);
    grille->getPlateau()[3][3]->setCouleur(Couleur::BLANC);
    //grille->ajouterJeton('e',5,Couleur::BLANC);

    courant = Couleur::NOIR;
}

Othello::~Othello()
{
    delete grille;
}

void Othello::play()
{
    int nbRest = 60;
    while(nbRest >=0){
        std::cout<<*grille;
        bool pionJoue = false;
        while (!pionJoue) {
            pionJoue = jouerPion(courant);

        }
        if(pionJoue){
            nbRest -=1 ;
        }
        if(courant == Couleur::NOIR){
            courant = Couleur::BLANC;
        }else{
            courant = Couleur::NOIR;
        }
    }
    if(nbRest ==0){
        trouverGagnant();
    }
}

bool Othello::jouerPion(Couleur c)
{
    cout << "Entree la lettre de la colonne :" << endl;
    char l;
    cin >>l;

    cout << "Entree le numero de ligne: " << endl;

    int ligne;
    cin >> ligne;
    return grille->ajouterJeton(l,ligne,c);
}

void Othello::trouverGagnant()
{
    Couleur gagnant = grille->gagnant();
    if(gagnant == Couleur::NOIR){
        std::cout<<"Le joueur noir a gagne"<<std::endl;
    }else{
        std::cout<<"Le joueur blanc a gagne"<<std::endl;
    }
}
