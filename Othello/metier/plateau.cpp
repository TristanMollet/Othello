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
