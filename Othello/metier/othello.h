#ifndef OTHELLO_H
#define OTHELLO_H
#include "plateau.h"
class Othello
{
private:
    Plateau *grille;
public:
    Othello();

    inline Plateau * getGrille(){return grille;}


};

#endif // OTHELLO_H