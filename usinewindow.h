#ifndef USINEWINDOW_H
#define USINEWINDOW_H

#include <QDialog>

namespace Ui {
class UsineWindow;
}

class UsineWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UsineWindow(QWidget *parent = nullptr);
    ~UsineWindow();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::UsineWindow *ui;
    int x;
    int y;
    bool comptachat =true ;
};

#endif // USINEWINDOW_H
