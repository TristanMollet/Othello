#include "plateau.h"
#include <iostream>
Plateau::Plateau(int largeur, int longueur)
{
    plateau.resize(largeur,std::vector<Jeton *>(longueur) );
    for(int i =0;i<largeur;i++){
        for(int j =0; j<longueur;j++){
            plateau[i][j]= new Jeton(Couleur::VIDE);

        }
    }

}

bool Plateau::ajouterJeton(char L, int l, Couleur c)
{
    bool placer =false;
    int colonne = lettreToInt(L);
    l = l-1;
    if(colonne >=0 && colonne < 8 && verifierPosition(l,colonne)){
        plateau[l][colonne]->setCouleur(c);
        placer = true;
    }
    return placer;
}

int Plateau::lettreToInt(char c)
{
    int nb = 0;
    switch (c) {
    case 'a':
        nb =0;
        break;
    case 'b':
        nb = 1;
        break;
    case 'c':
        nb = 2;
        break;
    case 'd':
        nb = 3;
        break;
    case 'e':
        nb = 4;
        break;
    case 'f':
        nb = 5;
        break;
    case 'g':
        nb =6;
        break;
    case 'h':
        nb =7;
        break;
    default:
        nb = -1;
        break;
    }
    return nb;
}
bool Plateau::verifNormal(int ligne,int colonne){
    bool posOK =false;
    if(plateau[ligne -1][colonne -1]->getCouleur() != Couleur::VIDE){
        posOK =true;
    }else if(plateau[ligne -1][colonne]->getCouleur() != Couleur::VIDE){
        posOK = true;
    }else if (plateau[ligne -1][colonne +1]->getCouleur() != Couleur::VIDE) {
        posOK = true;
    }else if (plateau[ligne][colonne -1]->getCouleur() != Couleur::VIDE) {
        posOK = true;
    }else if (plateau[ligne][colonne +1]->getCouleur() != Couleur::VIDE) {
        posOK = true;
    }else if (plateau[ligne+1][colonne -1]->getCouleur() != Couleur::VIDE) {
        posOK = true;
    }else if (plateau[ligne+1][colonne]->getCouleur() != Couleur::VIDE) {
        posOK = true;
    }else if (plateau[ligne+1][colonne +1]->getCouleur() != Couleur::VIDE) {
        posOK  =true;
    }
    return posOK;

}

bool Plateau::verifLigneMax(int ligne, int colonne)
{
    bool posOK = false;
    if(colonne != 0 && colonne !=7){
        std::cout << "Pas dans un coin" << std::endl;
        if(plateau[ligne][colonne-1]->getCouleur() != Couleur::VIDE){
            std::cout << "ligne et colonne -1" << std::endl;
            posOK= true;
        }else if (plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE) {
            std::cout << "ligne et colonne +1" << std::endl;
            posOK =true;
        }else if (plateau[ligne-1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            std::cout << "ligne-1 et colonne -1" << std::endl;
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }
    }else if (colonne == 0) {
        std::cout << "Dans le coin gauche" << std::endl;
        if(plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne -1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK = true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {

        }
    }else if (colonne ==7) {
        std::cout << "Dans le coin droit" << std::endl;
        if(plateau[ligne][colonne -1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne-1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK=true;
        }
    }
    return posOK;
}

bool Plateau::verifCol0(int ligne, int colonne)
{
    bool posOK= false;
    if(ligne != 0 && ligne !=7){
        if(plateau[ligne+1][colonne]->getCouleur() != Couleur::VIDE){
            posOK= true;
        }else if (plateau[ligne+1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }
    }else if (ligne == 0) {
        if(plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne +1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK = true;
        }else if (plateau[ligne+1][colonne+1]->getCouleur()!= Couleur::VIDE) {

        }
    }else if (ligne ==7) {
        if(plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK=true;
        }
    }
    return posOK;
}

bool Plateau::verifColMax(int ligne, int colonne)
{
    bool posOK= false;
    if(ligne != 0 && ligne !=7){
        if(plateau[ligne][colonne-1]->getCouleur() != Couleur::VIDE){
            posOK= true;
        }else if (plateau[ligne+1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne+1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }
    }else if (ligne == 0) {
        if(plateau[ligne][colonne-1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne +1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK = true;
        }else if (plateau[ligne+1][colonne-1]->getCouleur()!= Couleur::VIDE) {

        }
    }else if (ligne ==7) {
        if(plateau[ligne][colonne -1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne-1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK=true;
        }
    }
    return posOK;
}

bool Plateau::verifLigne0(int ligne,int colonne){
    bool posOK= false;
    if(colonne != 0 && colonne !=7){
        if(plateau[ligne][colonne-1]->getCouleur() != Couleur::VIDE){
            posOK= true;
        }else if (plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne+1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne+1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne+1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }
    }else if (colonne == 0) {
        if(plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne +1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK = true;
        }else if (plateau[ligne+1][colonne+1]->getCouleur()!= Couleur::VIDE) {

        }
    }else if (colonne ==7) {
        if(plateau[ligne][colonne -1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne+1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne+1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK=true;
        }
    }
    return posOK;
}

bool Plateau::verifierPosition(int ligne, int colonne)
{
    std::cout << "Dans verifierPosition" << std::endl;
    bool posOK =false;
    if(plateau[ligne][colonne]->getCouleur()==Couleur::VIDE){
        if(ligne - 1 >=0 && colonne -1 >= 0 && ligne +1 <7 && colonne+1 <7){
            std::cout << "Je verifie normalement"<< std::endl;
            posOK =verifNormal(ligne,colonne);
        }else if (ligne == 0) {
            std::cout << "Je verifie ligne0" << std::endl;
            posOK = verifLigne0(ligne,colonne);
        }else if (ligne == 7) {
            std::cout<< "Je verifie ligneMax" << std::endl;
            posOK = verifLigneMax(ligne,colonne);
        }else if (colonne == 0) {
            std::cout << "Je verifie colonne 0" << std::endl;
            posOK  = verifCol0(ligne,colonne);
        }else{
            std::cout << "Je verifie colonneMax" << std::endl;
            posOK = verifColMax(ligne,colonne);
        }

    }
    std::cout << "Fin verifierPosition"<< std::endl;
    return posOK;
}



std::ostream& operator<<(std::ostream &flux, const Plateau &plateau)
{
    int nb =1;
    flux << " --A---B---C---D---E---F---G---H--"<<std::endl;
    //    flux << " ---------------------------------"<<std::endl;
    for (int i = 0 ; i<plateau.largeur;i++){

        flux << nb++ << "|";
        for(int j = 0 ;j<plateau.longueur;j++){
            flux<< *plateau.plateau[i][j]<<"|";
        }
        flux <<std::endl<< " ---------------------------------"<< std::endl;
    }
    return flux;
}
