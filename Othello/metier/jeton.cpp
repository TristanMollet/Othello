#include "jeton.h"
#include <iostream>
using namespace std;

Jeton::Jeton()
{
    cout << "constructeur jeton vide" << std::endl;
}

Jeton::Jeton(Couleur c)
{
    couleur = c;
}

ostream& operator<<( ostream &flux, Jeton const& jeton )
{
    switch (jeton.couleur) {
    case Couleur::VIDE:
        flux << "   ";
        break;
    case Couleur::BLANC:
        flux << " B ";
        break;
    case Couleur::NOIR:
        flux << " N ";
        break;
    default:
        break;
    }
    return flux;
}
