#ifndef FENGENERATOR_H
#define FENGENERATOR_H

#include <QApplication>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class FenGenerator: public QDialog
{
public:
    FenGenerator(QString &code,QWidget *parent);


private:
    QTextEdit *codeGenere;
    QPushButton *fermer;
};

#endif // FENGENERATOR_H
