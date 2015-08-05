#ifndef OTHELLO_H
#define OTHELLO_H
#include "plateau.h"
#include "pattern/sujetdobservation.h"
class Othello : public SujetDObservation
{
private:
    Plateau *grille;
    Couleur courant;
    int pionRestant;
public:
    Othello();
    ~Othello();

    inline Plateau * getGrille(){return grille;}

    inline Couleur getCourant(){return courant;}
    inline int getPionRrestant(){return pionRestant;}

    void play();
    std::string afficher();
    bool jouerPion(std::string l, int ligne, Couleur c);
    std::string trouverGagnant();



};

#endif // OTHELLO_H
