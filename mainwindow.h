#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QMainWindow>
#include"Gameobject.h"
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
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void setgameobject(Gameobject value);

private:
    Ui::MainWindow *ui;
    Gameobject gameobject[21][21];
    bool selected = false;
    int posXselec;
    int posYselec;

};

#endif // MAINWINDOW_H
