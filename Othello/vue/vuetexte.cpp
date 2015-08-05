#include "vuetexte.h"
#include "pattern/sujetdobservation.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>
VueTexte::VueTexte(Othello *sdo,QWidget *parent ):QWidget(parent),othello(sdo)
{
    setWindowTitle(tr("Vue texte"));
    //Qt::WindowFlags flags {0};
    //setWindowFlags(flags);
    jouer = new QPushButton("Jouer",this);
    QObject::connect(jouer,SIGNAL(clicked()),this,SLOT(clicJouer()));

    label = new QLabel(this);

    ligne = new QComboBox(this);
    ligne->addItem("A");
    ligne->addItem("B");
    ligne->addItem("C");
    ligne->addItem("D");
    ligne->addItem("E");
    ligne->addItem("F");
    ligne->addItem("G");
    ligne->addItem("H");
    colonne = new QComboBox(this);
    for(int nb=1;nb<=8;nb++){
        colonne->addItem(QString::number(nb));
    }


    QHBoxLayout *hLayout;
    hLayout = new QHBoxLayout();
    hLayout->addWidget(ligne);
    hLayout->addWidget(colonne);
    hLayout->addWidget(jouer);
    hLayout->setAlignment(this,Qt::AlignTop);
    QVBoxLayout *vLayout;
    vLayout = new QVBoxLayout();
    courant = new QLabel("");
    QLabel * lb = new QLabel("Joueur courant : ");
    QHBoxLayout *lCourant;
    lCourant = new QHBoxLayout();
    lCourant->addWidget(lb);
    lCourant->addWidget(courant);
    vLayout->addWidget(label);
    vLayout->addLayout(hLayout);
    vLayout->addLayout(lCourant);
    setLayout(vLayout);


    label->setFixedSize(350,450);

    othello->attacher(this);
    rafraichir(othello);
}

void VueTexte::rafraichir(SujetDObservation *sdo){
    label->clear();
    if(othello=dynamic_cast<Othello*>(sdo)){

        QString contenu;
        contenu.append(("<center>"));
        contenu.append(QString::fromStdString(othello->afficher()));

        label->setText(contenu);
        if(othello->getCourant()== Couleur::NOIR){
            courant->setText("Noir");
        }else{
            courant->setText("Blanc");
        }
        if(othello->getPionRrestant()==0){
            label->clear();
            label->setText(QString::fromStdString(othello->trouverGagnant()));
        }
    }
}

VueTexte::~VueTexte(){
    othello->detacher(this);
    delete label;
    delete ligne;
    delete colonne;
    delete jouer;
}

void VueTexte::clicJouer()
{
    int lig = colonne->currentText().toInt();
    std::string col = ligne->currentText().toStdString();
    othello->jouerPion(col,lig,othello->getCourant());
}
