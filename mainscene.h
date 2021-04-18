#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
//#include <QtSvg>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QTimer>

#include "simulation.h"

class MainScene : public QGraphicsScene
{
public:
    MainScene();
    void startSimulation(int interval);

private:
    QGraphicsSvgItem test;
    Simulation simulation{};
    std::vector<QGraphicsSvgItem*> Qlegionaries{};
    QSvgRenderer* legionaryRenderer {new QSvgRenderer(QLatin1String(":/images/legionary.svg"), this)};
    QTimer *timer;
    void UpdateSimulationData();
};

#endif // MAINSCENE_H
