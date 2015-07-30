#ifndef PLATEAU_H
#define PLATEAU_H
#include <vector>
#include <string>
#include "jeton.h"
#include"Couleur.h"
/*!
 * \brief The Plateau class
 * Represente le plateau de jeu.
 */
class Plateau
{
private:
    int largeur=8;
    int longueur=8;
    std::vector<std::vector<Jeton *> > plateau;
public:
    /*!
     * \brief Plateau Construit un plateau de jeu de largeur et longueur donnee.
     * Par default largeur et longueur sont de 8
     * \param largeur La largeur du plateau de jeu
     * \param longueur La longueur du plateau de jeu.
     */
    Plateau(int largeur = 8,int longueur = 8);
    /*!
     * \brief getLargeur Donne la largeur du plateau de jeu
     * \return largeur du plateau.
     */
    inline int getLargeur(){return largeur;}
    /*!
     * \brief getLongueur Donne la longueur du plateau de jeu.
     * \return La longueur du plateau de jeu.?
     */
    inline int getLongueur(){return longueur;}
    /*!
     * \brief getPlateau Donne le plateau de jeu.
     * \return Le plateau de jeu.
     */
    inline std::vector<std::vector<Jeton*> > getPlateau(){return plateau;}

    friend std::ostream &operator<<( std::ostream &flux, Plateau const& plateau);





};

#endif // PLATEAU_H
