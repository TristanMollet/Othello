#ifndef JETON_H
#define JETON_H
#include "metier/Couleur.h"
#include <ostream>
/*!
 * \brief The Jeton class
 * Represente un jeton du platerau de jeu.
 */
class Jeton
{
private:
    Couleur couleur;
public:
    Jeton();
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
    std::string toString();

    friend std::ostream& operator<<( std::ostream &flux, Jeton const& jeton);

};

#endif // JETON_H
