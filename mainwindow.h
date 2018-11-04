#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
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

private:
    Ui::MainWindow *ui;
    Map *map;


};

#endif // MAINWINDOW_H

