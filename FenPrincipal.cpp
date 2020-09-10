#include "FenPrincipal.h"
#include "FenGenerator.h"

FenPrincipal::FenPrincipal()
{


    nom=new QLineEdit("&Nom:");
    parent=new QLineEdit("Classe &mère:");
    layout1=new QVBoxLayout;
         layout1->addWidget(nom);
         layout1->addWidget(parent);
         FenPrincipal().setLayout(layout1);

    header=new QCheckBox("Protéger le &header contre les inclusions multiples");
    constructeur=new QCheckBox("Générer un &constructeur par défaut");
    destructeur=new QCheckBox("Générer un &destructeur");
    header->setChecked(true);
    constructeur->setChecked(true);
    layout2=new QVBoxLayout;
         layout2->addWidget(header);
         layout2->addWidget(constructeur);
         layout2->addWidget(destructeur);
         FenPrincipal().setLayout(layout2);


    groupeCommentaires=new QGroupBox("Ajouter des commentaires");

            auteur=new QLineEdit("&Auteur:");
            date=new QDateEdit();
            role=new QTextEdit("&Role de la classe:");

      groupeCommentaires->setChecked(true);
    layout3=new QVBoxLayout;
         layout3->addWidget(auteur);
         layout3->addWidget(date);
         layout3->addWidget(role);
         FenPrincipal().setLayout(layout3);

     bouton1=new QPushButton("Quitter");
     bouton2=new QPushButton("Générer");


     connect(bouton1, SIGNAL(clicked()),qApp, SLOT(quit()));
     connect(bouton2, SIGNAL(clicked()),this, SLOT(genererCode()));

}

void FenPrincipal::genererCode()
{
    if(nom->text().isEmpty())
    {
        QMessageBox::critical(this,"Erreur!!","Veuillez entrez au moins un nom de classe");
        return;
    }
    else
    {
       QString code="/*"
                    "Auteur : "; auteur ;
                    "Date de création : "; date;
                    "Role :"; role;
                    "*/";

         FenGenerator *fenetreCode=new FenGenerator (code,this);
         fenetreCode->exec();

    }
}
