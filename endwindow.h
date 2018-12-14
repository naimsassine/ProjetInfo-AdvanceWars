#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDialog>


namespace Ui {
class endWindow;
}

class endWindow: public QDialog
{
     Q_OBJECT
public:
    endWindow();
};

#endif // ENDWINDOW_H
