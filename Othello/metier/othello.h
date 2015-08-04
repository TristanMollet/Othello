#ifndef OTHELLO_H
#define OTHELLO_H
#include "plateau.h"
#include "pattern/sujetdobservation.h"
class Othello : public SujetDObservation
{
private:
    Plateau *grille;
    Couleur courant;
public:
    Othello();
    ~Othello();

    inline Plateau * getGrille(){return grille;}

    inline Couleur getCourant(){return courant;}

    void play();
    std::string afficher();
    bool jouerPion(char l, int ligne, Couleur c);
    void trouverGagnant();



};

#endif // OTHELLO_H
