#include "monitem.h"

monItem::monItem(int lig, int col,QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    ligne = lig;
    colonne = col;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    //setFlag(QGraphicsItem::ItemIsMovable,true);

}

