#include "bouton.h"
#include "game.h"
#include <QPainter>
#include <iostream>
#include <QPushButton>
#include <QMouseEvent>
#include <QTextStream>
#include <QtMath>
#include <math.h>
#include <stdio.h>



Bouton::Bouton(QWidget *parent ){
    setFocusPolicy(Qt::StrongFocus);

}
void Bouton::createButton(){
    QPushButton bouton("Pimp mon bouton !", this);
    bouton.show();
    //*bouton = QPushButton("My Button", this);
}


