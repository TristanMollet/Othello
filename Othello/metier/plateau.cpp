#include "plateau.h"
#include <algorithm>
#include <string>
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

bool Plateau::ajouterJeton(std::string L, int l, Couleur c)
{
    bool placer =false;
    int colonne = lettreToInt(L);
    l = l-1;
    if(colonne >=0 && colonne < 8 && verifierPosition(l,colonne)){
        plateau[l][colonne]->setCouleur(c);
        placer = true;
        reverse(l,colonne,c);
    }
    return placer;
}

Couleur Plateau::gagnant()
{
    int nbNoir =0;
    int nbBlanc=0;
    for (int i =0; i<largeur;i++){
        for(int j=0;j<longueur;j++){
            if(plateau[i][j]->getCouleur() == Couleur::NOIR){
                nbNoir +=1;
            }else {
                nbBlanc +=1;
            }
        }
    }
    Couleur gagnant(Couleur::VIDE);
    if(nbNoir > nbBlanc){
        gagnant = Couleur::NOIR;
    }else{
        gagnant = Couleur::BLANC;
    }
    return gagnant;
}

void Plateau::reverse(int ligne, int colonne, Couleur c)
{
    reverseHaut(ligne,colonne,c);
    reverseBas(ligne,colonne,c);
    reverseDroite(ligne,colonne+1,c);
    reverseGauche(ligne,colonne-1,c);
    reverseDiaHautDroit(ligne,colonne,c);
    reverseDiaHautGauche(ligne,colonne,c);
    reverseDiaBasDroit(ligne,colonne,c);
    reverseDiaBasGauche(ligne,colonne,c);
}

void Plateau::reverseHaut(int ligne,int colonne,Couleur c){
    if(ligne-1 >= 0){
        if(plateau[ligne-1][colonne]->getCouleur() != Couleur::VIDE &&
                plateau[ligne-1][colonne]->getCouleur() != c){
            reverseHaut(ligne-1,colonne,c);
        }else if (plateau[ligne-1][colonne]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne-1][colonne]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);

        }
    }
}

void Plateau::reverseBas(int ligne,int colonne,Couleur c){
    if(ligne+1 <8){
        if(plateau[ligne+1][colonne]->getCouleur() != Couleur::VIDE &&
                plateau[ligne+1][colonne]->getCouleur() != c){
            reverseBas(ligne+1,colonne,c);
        }else if (plateau[ligne+1][colonne]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne+1][colonne]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}

void Plateau::reverseDroite(int ligne,int colonne,Couleur c){
    if(colonne+1 <8){
        if(plateau[ligne][colonne+1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne][colonne+1]->getCouleur() != c){
            reverseDroite(ligne,colonne+1,c);
        }else if (plateau[ligne][colonne+1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne][colonne+1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}


void Plateau::reverseGauche(int ligne,int colonne,Couleur c){
    if(colonne-1 >=0){
        if(plateau[ligne][colonne-1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne][colonne-1]->getCouleur() != c){
            reverseGauche(ligne,colonne-1,c);
        }else if (plateau[ligne][colonne-1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne][colonne-1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}


void Plateau::reverseDiaHautDroit(int ligne,int colonne,Couleur c){
    if(colonne+1 <8 && ligne -1 >=0){
        if(plateau[ligne-1][colonne+1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne-1][colonne+1]->getCouleur() != c){
            reverseDiaHautDroit(ligne-1,colonne+1,c);
        }else if (plateau[ligne-1][colonne+1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne-1][colonne+1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}

void Plateau::reverseDiaHautGauche(int ligne,int colonne,Couleur c){
    if(colonne-1 >=0 && ligne -1 >=0){
        if(plateau[ligne-1][colonne-1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne-1][colonne-1]->getCouleur() != c){
            reverseDiaHautGauche(ligne-1,colonne-1,c);
        }else if (plateau[ligne-1][colonne-1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne-1][colonne-1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}

void Plateau::reverseDiaBasDroit(int ligne,int colonne,Couleur c){
    if(colonne+1 <8 && ligne +1 <8){
        if(plateau[ligne+1][colonne+1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne+1][colonne+1]->getCouleur() != c){
            reverseDiaBasDroit(ligne+1,colonne+1,c);
        }else if (plateau[ligne+1][colonne+1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne+1][colonne+1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}

void Plateau::reverseDiaBasGauche(int ligne,int colonne,Couleur c){
    if(colonne-1 >=0 && ligne +1 <8){
        if(plateau[ligne+1][colonne-1]->getCouleur() != Couleur::VIDE &&
                plateau[ligne+1][colonne-1]->getCouleur() != c){
            reverseDiaBasGauche(ligne+1,colonne-1,c);
        }else if (plateau[ligne+1][colonne-1]->getCouleur() == c) {
            plateau[ligne][colonne]->setCouleur(c);
        }
        if(plateau[ligne+1][colonne-1]->getCouleur() == c){
            plateau[ligne][colonne]->setCouleur(c);
        }
    }
}

int Plateau::lettreToInt(std::string c)
{
    std::transform(c.begin(),c.end(),c.begin(),::tolower);
    int nb = 0;
    if(c=="a"){
        nb =0;
    }else if(c=="b"){
        nb =1;
    }else if(c=="c"){
        nb=2;
    }else if(c=="d"){
        nb=3;
    }else if(c=="e"){
        nb=4;
    }else if(c=="f"){
        nb =5;
    }else if(c=="g"){
        nb=6;
    }else if(c=="h"){
        nb=7;
    }
//    switch (c) {
//    case "a":
//        nb =0;
//        break;
//    case "b":
//        nb = 1;
//        break;
//    case "c":
//        nb = 2;
//        break;
//    case "d":
//        nb = 3;
//        break;
//    case "e":
//        nb = 4;
//        break;
//    case "f":
//        nb = 5;
//        break;
//    case "g":
//        nb =6;
//        break;
//    case "h":
//        nb =7;
//        break;
//    default:
//        nb = -1;
//        break;
//    }
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
        if(plateau[ligne][colonne-1]->getCouleur() != Couleur::VIDE){
            posOK= true;
        }else if (plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne-1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {
            posOK =true;
        }
    }else if (colonne == 0) {
        if(plateau[ligne][colonne+1]->getCouleur()!= Couleur::VIDE){
            posOK = true;
        }else if (plateau[ligne -1][colonne]->getCouleur()!= Couleur::VIDE) {
            posOK = true;
        }else if (plateau[ligne-1][colonne+1]->getCouleur()!= Couleur::VIDE) {

        }
    }else if (colonne ==7) {
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
    bool posOK =false;
    if((ligne>=0 && ligne <8) && (colonne >=0 && colonne <8) &&
            plateau[ligne][colonne]->getCouleur()==Couleur::VIDE){
        if(ligne - 1 >=0 && colonne -1 >= 0 && ligne +1 <7 && colonne+1 <7){
            posOK =verifNormal(ligne,colonne);
        }else if (ligne == 0) {
            posOK = verifLigne0(ligne,colonne);
        }else if (ligne == 7) {
            posOK = verifLigneMax(ligne,colonne);
        }else if (colonne == 0) {
            posOK  = verifCol0(ligne,colonne);
        }else{
            posOK = verifColMax(ligne,colonne);
        }

    }
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
