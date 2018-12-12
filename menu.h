#ifndef MENU_H
#define MENU_H
#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();




    MainWindow *getWindow() const;
    void setWindow(MainWindow *value);

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Menu *ui;
    MainWindow *window;
};

#endif // MENU_H
