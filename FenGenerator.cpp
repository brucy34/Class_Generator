#include <FenGenerator.h>


FenGenerator::FenGenerator(QString &code, QWidget *parent=0): QDialog(parent)
{
    codeGenere=new QTextEdit();
    codeGenere->setPlainText(code);
    codeGenere->setReadOnly(true);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    fermer=new QPushButton("Fermer");

    QVboxLayout *vbx=new QVBoxLayout;
    vbx->addWidget(codeGenere);
    vbx->addWidget(fermer);


    resize(350,450);
    setLayout(vbx);

    connect(fermer, SIGNAL(clicked()),this,SLOT(accept()));

}


