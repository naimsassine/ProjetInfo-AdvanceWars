#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include"Gameobject.h"
#include "game.h"
#include <QApplication>
#include <QHBoxLayout>
#include "player.h"
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    this->close();
    window->show();



}

MainWindow *Menu::getWindow() const
{
    return window;
}

void Menu::setWindow(MainWindow *value)
{
    window = value;
}


void Menu::on_pushButton_2_clicked()
{   window->online();
    window->show();
}
