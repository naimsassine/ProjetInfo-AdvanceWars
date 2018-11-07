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
    QPushButton *bouton;

};

#endif // MAINWINDOW_H

