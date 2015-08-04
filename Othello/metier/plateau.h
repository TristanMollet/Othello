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

    /*!
     * \brief ajouterJeton
     * \param L la lettre de la colonne
     * \param l le numéro de ligne
     * \param c la couleur du jeton
     * \return
     */
    bool ajouterJeton(char L,int l, Couleur c);
    Couleur gagnant();
    void reverse(int ligne,int colonne, Couleur c);

private:
    /*!
     * \brief lettreToInt Transforme une lettre en son chiffre correpondant pour les numeros de colonne
     * \param c la lettre
     * \return un entier positif si la lettre est correct, -1 si la lettre est mauvaise.
     */
    int lettreToInt(char c);

    bool verifierPosition(int ligne,int colonne);
    bool verifNormal(int ligne,int colonne);
    bool verifLigne0(int ligne,int colonne);
    bool verifLigneMax(int ligne,int colonne);
    bool verifCol0(int ligne,int colonne);
    bool verifColMax(int ligne,int colonne);

    void reverseHaut(int ligne,int colonne,Couleur c);
    void reverseBas(int ligne,int colonne,Couleur c);
    void reverseDroite(int ligne,int colonne,Couleur c);
    void reverseGauche(int ligne,int colonne,Couleur c);
    void reverseDiaHautDroit(int ligne,int colonne,Couleur c);
    void reverseDiaHautGauche(int ligne,int colonne,Couleur c);
    void reverseDiaBasDroit(int ligne,int colonne,Couleur c);
    void reverseDiaBasGauche(int ligne,int colonne,Couleur c);





};

#endif // PLATEAU_H
