
#include <QCoreApplication>
#include "metier/plateau.h"
#include "metier/othello.h"
#include <iostream>
using namespace std;
int main()

{
    bool placer =false;
    Othello *ot;
    ot = new Othello();
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    ot->jouerPion(Couleur::NOIR);
    cout << *ot->getGrille();

    ot->jouerPion(Couleur::BLANC);
    cout << *ot->getGrille();
    //    Plateau p(8,8);

    //     cout << p;
    //     p.ajouterJeton('c',5,Couleur::NOIR);
    //     cout << p;
    //     p.ajouterJeton('f',2,Couleur::BLANC);
    //     cout << p;
    //    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    //    return a.exec();
}
