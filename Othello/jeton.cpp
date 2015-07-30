#include "jeton.h"

Jeton::Jeton(Couleur c):couleur{c}
{
}

#ifndef JETON_H
#define JETON_H
#include "metier/Couleur.h"
/*!
 * \brief The Jeton class
 * Represente un jeton du platerau de jeu.
 */
class Jeton
{
private:
    Couleur couleur;
public:
    /*!
     * \brief Jeton Construit un jeton de couleur c
     * \param c
     */
    Jeton(Couleur c);

    /*!
     * \brief getCouleur
     * \return La couleur du jeton.
     */
    inline Couleur getCouleur(){return couleur;}
    /*!
     * \brief setCouleur Met le jeton a la couleur c
     * \param c La nouvelle couleur du jeton.
     */
    inline void setCouleur(Couleur c){couleur = c;}

};

#endif // JETON_H
