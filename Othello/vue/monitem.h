#ifndef MONITEM_H
#define MONITEM_H
#include <QPixmap>
#include<QGraphicsPixmapItem>
#include "metier/othello.h"
#include "pattern/observateur.h"
/*!
 * \brief The monItem class
 */
class monItem : public QGraphicsPixmapItem, public Observateur
{
private:
    int ligne;
    int colonne;
    Othello *othello;
public:
    /*!
     * \brief monItem creer une instance de monItem
     * \param lig ligne de l'emplacement du jeton
     * \param col colonne de l'emplacement du jeton
     * \param ot SujetDObservation metier
     * \param parent
     */
    monItem(int lig, int col, Othello *ot, QGraphicsItem *parent =0);
    /*!
     * \brief getLigne
     * \return la ligne du jeton
     */
    inline int getLigne(){return ligne;}
    /*!
     * \brief getColonne
     * \return la colonne du jeton
     */
    inline int getColonne(){return colonne;}
protected:
    void rafraichir(SujetDObservation *sdo);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MONITEM_H
