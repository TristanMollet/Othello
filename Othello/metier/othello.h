#ifndef OTHELLO_H
#define OTHELLO_H
#include "plateau.h"
#include "pattern/sujetdobservation.h"

/*!
 * \brief The Othello class Classe metier reprensentant le jeu
 */
class Othello : public SujetDObservation
{
private:
    Plateau *grille;
    Couleur courant;
    int pionRestant;
public:
    /*!
     * \brief Othello constuit le jeu
     */
    Othello();
    ~Othello();

    /*!
     * \brief getGrille Donne la grille de jeu
     * \return la grille de jeu
     */
    inline Plateau * getGrille(){return grille;}

    /*!
     * \brief getCourant Donne la couleur du joueur courant
     * \return la couleur du joueur courant
     */
    inline Couleur getCourant(){return courant;}
    /*!
     * \brief getPionRrestant Donne le nombre de jetons restant
     * \return le nombre de jeton restant
     */
    inline int getPionRrestant(){return pionRestant;}

    /*!
     * \brief play Permet de lancer le jeu en console
     */
    void play();
    /*!
     * \brief afficher affiche la grille
     * \return la grille en string
     */
    std::string afficher();
    /*!
     * \brief jouerPion permet de jouer un jeton
     * \param ligne
     * \param colonne
     * \return true si le jeton a ete jouer
     */
    bool jouerPion(int ligne, int colonne);
    /*!
     * \brief jouerPion permet de joueur un jeton
     * \param l la colonne
     * \param ligne
     * \param c couleur a jouer
     * \return true si le jeton est jouer
     */
    bool jouerPion(std::string l, int ligne, Couleur c);

    /*!
     * \brief trouverGagnant cherche le gagnant
     * \return le gagnant
     */
    std::string trouverGagnant();



};

#endif // OTHELLO_H
