#include "mainwindow.h"

#include <QApplication>
//#include "timer.h"


int main(int argc, char *argv[])
{  
    //Timer timer;
    //timer.setInterval([](){std::cout << "timer" << std::endl;}, 1000);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
