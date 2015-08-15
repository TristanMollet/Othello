#ifndef MONITEM_H
#define MONITEM_H
#include <QPixmap>
#include<QGraphicsPixmapItem>
#include "metier/othello.h"
#include "pattern/observateur.h"
class monItem : public QGraphicsPixmapItem, public Observateur
{
private:
    int ligne;
    int colonne;
    Othello *othello;
public:
    monItem(int lig, int col, Othello *ot, QGraphicsItem *parent =0);
    inline int getLigne(){return ligne;}
    inline int getColonne(){return colonne;}
protected:
    void rafraichir(SujetDObservation *sdo);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MONITEM_H
