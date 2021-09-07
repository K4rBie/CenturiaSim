#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include <memory>
#include <iostream>

#include "mainscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Simulation simulation;

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    //QGraphicsView  *view;

};
#endif // MAINWINDOW_H
