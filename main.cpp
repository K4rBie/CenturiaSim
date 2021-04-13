#include "mainwindow.h"
#include "string"
#include "iostream"
#include "cmath"
#include "set"
#include "algorithm"
#include <QApplication>

#include "timer.h"

int main(int argc, char *argv[])
{  
    std::set<std::string> dane = {"aaa", "bbb"};


    std::for_each(dane.begin(), dane.end(),
                  [](std::string const& i) { std::cout << i << std::endl; });

    Timer timer;

    timer.setInterval([](){std::cout << "timer" << std::endl;}, 1000);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
