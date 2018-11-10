#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QPushButton>
#include <QMainWindow>
#include"Gameobject.h"
#include "map.h"
#include <QLabel>
class Gameobject;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitMap();
    void redraw();

private slots:
void changeturn();

private:
    Ui::MainWindow *ui;
    Map *map;
    QPushButton *bouton;
    QLabel *lab;
    QLabel *lab2;
    QLabel *lab3;



};

#endif // MAINWINDOW_H

