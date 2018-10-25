#include "mainwindow.h"
#include"Gameobject.h"
#include "game.h"
#include <QApplication>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    Game& game=Game::Instance();
    game.InitGame(w);
    w.show();
<<<<<<< HEAD

=======
    int x = 5;
    int y = 6;
   
>>>>>>> f213888fbc1a3fec2257f4a6afdaef580b0df084

    return a.exec();

}
