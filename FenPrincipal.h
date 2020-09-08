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

class FenPrincipal: public QWidget
{
 public:
    FenPrincipal();
    QGroupBox *classe =new QGroupBox;
    QGroupBox *option=new QGroupBox;
    QLineEdit *edit=new QLineEdit;
    QCheckBox *commentaire=new QCheckBox;
    QVBoxLayout *layout=new QVBoxLayout;
    QPushButton *bouton1=new QPushButton;
    QPushButton *bouton2=new QPushButton;


 private:
    QGroupBox *m_classe;
    QGroupBox *m_option;
    QLineEdit *m_edit;
    QCheckBox *m_commentaire;
    QVBoxLayout *m_layout;
    QPushButton *m_bouton1;
    QPushButton *m_bouton2;

};

#endif // FENPRINCIPAL_H
