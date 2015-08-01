#ifndef OTHELLO_H
#define OTHELLO_H
#include "plateau.h"
class Othello
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

    bool jouerPion(Couleur c);
    void trouverGagnant();



};

#endif // OTHELLO_H
