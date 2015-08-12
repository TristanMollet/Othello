#include "othello.h"
#include <iostream>
using namespace std;
Othello::Othello()
{
    pionRestant=64;
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
    SujetDObservation::notifierChangement();
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
            //pionJoue = jouerPion(courant);

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

string Othello::afficher()
{
    std::string st;
    int nb =1;
    st.append("<b> --A---B---C---D---E---F---G---H--</b>");
    st.append("<br>");
    for (int i = 0 ; i< grille->getLargeur();i++){
        st.append(std::to_string(nb++));
        st.append(" <b> | </b> ");
        for(int j = 0 ;j<grille->getLongueur();j++){
            st.append(grille->getPlateau()[i][j]->toString());
            st.append(" <b> | </b>");
        }
        st.append("<br>");
        st.append("<b>--------------------------------------</b>");
        st.append("<br>");

    }
    return st;
}

bool Othello::jouerPion(int ligne, int colonne)
{
    bool ajouter =grille->ajouterJeton(ligne,colonne,courant);
    if(ajouter){
        pionRestant -=1;
        if(courant == Couleur::NOIR){
            courant = Couleur::BLANC;
        }else{
            courant = Couleur::NOIR;
        }
    }
    notifierChangement();
    return ajouter;
}

bool Othello::jouerPion(std::string l,int ligne,Couleur c)
{
//    cout << "Entree la lettre de la colonne :" << endl;
//    char l;
//    cin >>l;

//    cout << "Entree le numero de ligne: " << endl;

//    int ligne;
//    cin >> ligne;

    bool ajouter =grille->ajouterJeton(l,ligne,c);
    if(ajouter){
        pionRestant -=1;
        if(courant == Couleur::NOIR){
            courant = Couleur::BLANC;
        }else{
            courant = Couleur::NOIR;
        }
    }
    notifierChangement();
    return ajouter;
}

std::string Othello::trouverGagnant()
{
    std::string gag;
    Couleur gagnant = grille->gagnant();
    if(gagnant == Couleur::NOIR){
        gag="Le joueur noir a gagne";
    }else{
        gag="Le joueur blanc a gagne";
    }
    return gag;
}
