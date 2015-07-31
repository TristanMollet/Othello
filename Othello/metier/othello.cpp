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
}

void Othello::jouerPion(Couleur c)
{
    cout << "Entree la lettre de la colonne :" << endl;
    char l;
    cin >>l;

    cout << "Entree le numero de ligne: " << endl;

    int ligne;
    cin >> ligne;
    grille->ajouterJeton(l,ligne,c);
}
