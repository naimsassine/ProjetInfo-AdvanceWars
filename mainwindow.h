#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include"Gameobject.h"
#include "map.h"
#include "bouton.h"
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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Map *map;
    Bouton * bouton;


};

#endif // MAINWINDOW_H

