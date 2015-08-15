#include "monitem.h"

monItem::monItem(int lig, int col, Othello *ot, QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    othello = ot;
    ligne = lig;
    colonne = col;
    setZValue(5);
    ot->attacher(this);
   // setFlag(QGraphicsItem::ItemIsSelectable, true);
    //setFlag(QGraphicsItem::ItemIsMovable,true);

}

void monItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    othello->jouerPion(ligne,colonne);
 QGraphicsPixmapItem::mousePressEvent(event);
}

void monItem::rafraichir(SujetDObservation *sdo){

}
