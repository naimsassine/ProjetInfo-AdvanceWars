#ifndef BOUTON_H
#define BOUTON_H
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#endif // BOUTON_H

class Bouton : public QPushButton{

    Q_OBJECT

public :
    explicit Bouton(QWidget *parent = nullptr);
    void createButton();
private:
    Bouton();

};

//#endif //BOUTON_H
