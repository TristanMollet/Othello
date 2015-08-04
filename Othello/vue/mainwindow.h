#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "metier/othello.h"
#include "vue/vuetexte.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void connexion();
private slots:
    void creerPartie();
    void fermerPartie();
    void vueGraphique(bool actif);
    void vueTexte(bool actif);
private:
    Ui::MainWindow *ui;
    Othello *othello;
    VueTexte *vuetxt;



};

#endif // MAINWINDOW_H
