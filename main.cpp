#include <QApplication>
#include "FenPrincipal.h"
#include "FenGenerator.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);


    FenPrincipal fenetre;


    fenetre.show();

    return app.exec();
}
