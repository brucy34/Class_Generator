#include "FenPrincipal.h"
#include "FenGenerator.h"

FenPrincipal::FenPrincipal()
{


    nom=new QLineEdit("&Nom:");
    parent=new QLineEdit("Classe &mère:");
    QFormLayout *def=new QFormLayout;
         def->addRow(nom);
         def->addRow(parent);

    QGroupBox *groupe1=new QGroupBox("Définition de la classe");
    groupe1->setLayout(def);

    header=new QCheckBox("Protéger le &header contre les inclusions multiples");
    constructeur=new QCheckBox("Générer un &constructeur par défaut");
    destructeur=new QCheckBox("Générer un &destructeur");
    header->setChecked(true);
    constructeur->setChecked(true);
    QVBoxLayout *option=new QVBoxLayout;
         option->addWidget(header);
         option->addWidget(constructeur);
         option->addWidget(destructeur);

    QGroupBox *groupe2=new QGroupBox("Options");
    groupe2->setLayout(option);



            auteur=new QLineEdit;
            date=new QDateEdit;
            date->setDate(QDate::currentDate());
            role=new QTextEdit;


    QFormLayout *comm=new QFormLayout;
         comm->addRow("&Auteur :",auteur);
         comm->addRow("Da&te de création :", date);
         comm->addRow("&Role de la classe :", role);
     groupeCommentaires=new QGroupBox("Ajouter des commentaires");
     groupeCommentaires->setCheckable(true);
     groupeCommentaires->setChecked(false);
     groupeCommentaires->setLayout(comm);


     bouton1=new QPushButton("Quitter");
     bouton2=new QPushButton("Générer");

     QHBoxLayout *alignerBouton=new QHBoxLayout;
     alignerBouton->setAlignment(Qt::AlignRight);
     alignerBouton->addWidget(bouton1);
     alignerBouton->addWidget(bouton2);


     QVBoxLayout *vbx=new QVBoxLayout;
     vbx->addWidget(groupe1);
     vbx->addWidget(groupe2);
     vbx->addWidget(groupeCommentaires);
     vbx->addLayout(alignerBouton);

     setLayout(vbx);
     setWindowTitle("Générateur de classe");
     resize(400,450);


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

       QString code;
       if (groupeCommentaires->isChecked())
       {
            code +="/*\nAuteur :" +auteur->text()+"\n";
            code +="Date de Création :" +date->date().toString()+ "\n\n";
            code +="Role :\n" +role->toPlainText()+"\n*/\n\n\n";
       }

       if (header->isChecked())
       {
           code +="#ifndef HEADER_"+ nom->text().toUpper() + "\n";
           code +="#define HEADER_"+ nom->text().toUpper() + "\n\n";
       }

       code +="class "+ nom->text() + "\n";

       if (!parent->text().isEmpty())
       {
           code +=" : public"+ parent->text() +"\n";
       }

       code +="\n{\n      public:\n";

       if (constructeur->isChecked())
       {
           code +="         "+ nom->text() + "();\n";
       }

       if (destructeur->isChecked())
       {
           code +="         ~"+ nom->text() + "();\n";
       }

       code +="\n\n    protected:";
       code +="\n\n    private:";
       code +="};\n\n";

       if(header->isChecked())
       {
           code +="#endif\n";
       }



         FenGenerator *fenetreCode=new FenGenerator (code,this);
         fenetreCode->exec();


}
