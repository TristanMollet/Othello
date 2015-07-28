#ifndef PION_H
#define PION_H
#include "Couleur.h"
class Pion
{
private:
    Couleur couleur;
public:
    /*!
     * \brief Pion Construit un pion
     */
    Pion();
    /*!
     * \brief getCouleur Donne la couleur du pion
     * \return la couleur du pion
     */
    inline Couleur getCouleur(){return couleur;}
    /*!
     * \brief setCouleur Mets a jour la couleur du pion
     * \param coul la nouvelle couleur du pion
     */
    inline setCouleur(Couleur coul){this->couleur = coul;}

};

#endif // PION_H
