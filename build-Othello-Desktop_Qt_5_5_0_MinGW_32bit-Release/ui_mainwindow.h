/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *action_fermer;
    QAction *action_texte;
    QAction *action_graphique;
    QAction *action_Quitter;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layGraph;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layTxt;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuObservateur;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1111, 572);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        action_fermer = new QAction(MainWindow);
        action_fermer->setObjectName(QStringLiteral("action_fermer"));
        action_fermer->setCheckable(false);
        action_fermer->setEnabled(false);
        action_texte = new QAction(MainWindow);
        action_texte->setObjectName(QStringLiteral("action_texte"));
        action_texte->setCheckable(true);
        action_texte->setEnabled(false);
        action_graphique = new QAction(MainWindow);
        action_graphique->setObjectName(QStringLiteral("action_graphique"));
        action_graphique->setCheckable(true);
        action_graphique->setChecked(false);
        action_graphique->setEnabled(false);
        action_Quitter = new QAction(MainWindow);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 601, 531));
        layGraph = new QVBoxLayout(verticalLayoutWidget);
        layGraph->setObjectName(QStringLiteral("layGraph"));
        layGraph->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(620, 0, 491, 491));
        layTxt = new QVBoxLayout(verticalLayoutWidget_2);
        layTxt->setObjectName(QStringLiteral("layTxt"));
        layTxt->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1111, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuObservateur = new QMenu(menubar);
        menuObservateur->setObjectName(QStringLiteral("menuObservateur"));
        menuObservateur->setEnabled(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuObservateur->menuAction());
        menuMenu->addAction(actionNouveau);
        menuMenu->addAction(action_fermer);
        menuMenu->addAction(action_Quitter);
        menuObservateur->addAction(action_texte);
        menuObservateur->addAction(action_graphique);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Othello", 0));
        actionNouveau->setText(QApplication::translate("MainWindow", "&Nouveau", 0));
        action_fermer->setText(QApplication::translate("MainWindow", "&Fermer", 0));
        action_texte->setText(QApplication::translate("MainWindow", "&texte", 0));
        action_graphique->setText(QApplication::translate("MainWindow", "&graphique", 0));
        action_Quitter->setText(QApplication::translate("MainWindow", "&Quitter", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "&Menu", 0));
        menuObservateur->setTitle(QApplication::translate("MainWindow", "&Observateur", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
