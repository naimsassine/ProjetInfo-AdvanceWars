#ifndef AERWINDOW_H
#define AERWINDOW_H

#include <QDialog>

namespace Ui {
class AerWindow;
}

class AerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AerWindow(QWidget *parent = nullptr);
    ~AerWindow();



    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::AerWindow *ui;
    int x;
    int y;
    bool comptachat =true ;
};


#endif // AERWINDOW_H
