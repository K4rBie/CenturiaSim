#include "mainwindow.h"
#include "ui_mainwindow.h"

///
/// \brief MainWindow constructor sets up the main window.
/// \param parent   Qt parent
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MainScene(this);


    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
    ui->graphicsView->setScene(scene);

    //simulation.start(1000);

}

///
/// \brief MainWindow destructor
///
MainWindow::~MainWindow()
{
    delete ui;
}

