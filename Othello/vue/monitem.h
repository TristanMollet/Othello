#ifndef MONITEM_H
#define MONITEM_H
#include <QPixmap>
#include<QGraphicsPixmapItem>

class monItem : public QGraphicsPixmapItem
{
private:
    int ligne;
    int colonne;
public:
    monItem(int lig, int col, QGraphicsItem *parent =0);
    inline int getLigne(){return ligne;}
    inline int getColonne(){return colonne;}


};

#endif // MONITEM_H
