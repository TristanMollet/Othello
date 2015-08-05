
#include <QApplication>
#include "metier/plateau.h"
#include "metier/othello.h"
#include "vue/mainwindow.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    //Othello *ot;
    //ot=new Othello();
    //cout << ot->afficher();
    //    ot->play();



    MainWindow windows;
    windows.show();
    return a.exec();
}
