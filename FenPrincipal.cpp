#include "FenPrincipal.h"

FenPrincipal::FenPrincipal(): QWidget()
{
    QWidget Fen;
    QPushButton *bouton1 =new QPushButton("Générer!");
    QPushButton *bouton2 =new QPushButton("Quitter");




    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(bouton1);
    layout->addWidget(bouton2);
    Fen.setLayout(layout);

}
