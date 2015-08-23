#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "metier/othello.h"
#include "vue/vuetexte.h"
#include "vue/mascene.h"
namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow creer une instance de MainWindow
     * \param parent l'objet parent
     */
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
    maScene * scene;
    QGraphicsView * vueGraph;


};

#endif // MAINWINDOW_H
