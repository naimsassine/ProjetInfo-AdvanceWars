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


private:
    Ui::UsineWindow *ui;
    int x;
    int y;
};

#endif // USINEWINDOW_H
