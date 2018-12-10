#ifndef AEROWINDOW_H
#define AEROWINDOW_H

#include <QDialog>

namespace Ui {
class aerowindow;
}

class aerowindow : public QDialog
{
    Q_OBJECT

public:
    explicit aerowindow(QWidget *parent = nullptr);
    ~aerowindow();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::aerowindow *ui;
    int x;
    int y;
    bool comptachat =true ;
};

#endif // AEROWINDOW_H
