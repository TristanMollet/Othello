#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connexion();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete othello;
    delete vuetxt;
    delete vueGraph;
}

void MainWindow::connexion()
{
    connect(ui->action_Quitter,&QAction::triggered,
            &QCoreApplication::quit);
    connect(ui->actionNouveau, &QAction::triggered,
            this, &MainWindow::creerPartie);
    connect(ui->action_fermer, &QAction::triggered,
            this, &MainWindow::fermerPartie);
    connect(ui->action_graphique, &QAction::toggled,
            this, &MainWindow::vueGraphique);
    connect(ui->action_texte, &QAction::toggled,
            this, &MainWindow::vueTexte);
}

void MainWindow::creerPartie()
{
    othello = new Othello();
    vuetxt = nullptr;
    vueGraph = nullptr;
    ui->menuObservateur->setEnabled(true);
    ui->action_texte->setEnabled(true);
    ui->action_graphique->setEnabled(true);
    ui->actionNouveau->setEnabled(false);
    ui->action_fermer->setEnabled(true);
}

void MainWindow::fermerPartie()
{
    delete othello;
    othello = nullptr;
    delete vuetxt;
    vuetxt = nullptr;
    ui->actionNouveau->setEnabled(true);
    ui->menuObservateur->setEnabled(false);
    ui->action_fermer->setEnabled(false);
}

void MainWindow::vueGraphique(bool actif)
{
    if(actif){
       if(vueGraph == nullptr){
           vueGraph = new VueGraphique(othello,this);
       }
       setCentralWidget(vueGraph);
       vueGraph->show();
    }else{
        if(vueGraph != nullptr){
            vueGraph->hide();
        }
    }
}

void MainWindow::vueTexte(bool actif)
{
    if(actif){
        if(vuetxt == nullptr){
            vuetxt = new VueTexte(othello,this);

        }
        setCentralWidget(vuetxt);
        vuetxt->show();
    }else{
        if(vuetxt != nullptr){
            vuetxt->hide();
        }
    }
}


