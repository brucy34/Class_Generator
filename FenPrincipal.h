#ifndef FENPRINCIPAL_H
#define FENPRINCIPAL_H


#include <QApplication>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>

class FenPrincipal: public QWidget
{
    Q_OBJECT
 public:
    FenPrincipal();
    
private slots:
    void genererCode();

 private:
    QGroupBox *groupeCommentaires;
    QCheckBox *header;
    QCheckBox *constructeur;
    QCheckBox *destructeur;
    QLineEdit *nom;
    QLineEdit *parent;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    QVBoxLayout *layout3;

};

#endif // FENPRINCIPAL_H
