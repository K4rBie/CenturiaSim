#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QTimer>

#include "simulation.h"
#include "qlegionary.h"
#include "qgraphicsformationbutton.h"
#include "functionenum.h"

class QGraphicsFormationButton;

class MainScene : public QGraphicsScene
{
    Q_OBJECT
public:


    MainScene(QObject *parent = nullptr);
    ~MainScene();
    //MainScene();

    void startSimulation(int interval);
    void stopSimulation();
    void changeCenturiaFormation(const enum Formation& new_formation);
    void moveCenturia(const Position& requested_position);

private:
    QGraphicsSvgItem test;
    Simulation simulation{};
    std::forward_list<QGraphicsSvgItem*> Qlegionaries{};
    std::forward_list<QLegionary*> Qlegionaries2{};
    QSvgRenderer* legionaryRenderer {new QSvgRenderer(QLatin1String(":/images/legionary.svg"), this)};
    QSvgRenderer* decanusRenderer {new QSvgRenderer(QLatin1String(":/images/decanus.svg"), this)};
    QTimer *timer;

    QGraphicsFormationButton* m_startButton;
    QGraphicsFormationButton* m_stopButton;
    QGraphicsFormationButton* m_formLineButton;
    QGraphicsFormationButton* m_formTestudoButton;
    QGraphicsFormationButton* m_formSquareButton;
    //QGraphicsFormationButton* testudoButton {new QGraphicsFormationButton(Function::FORM_TESTUDO, this)};


    void UpdateSimulationData();
};

#endif // MAINSCENE_H
