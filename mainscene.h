#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsDropShadowEffect>

#include "simulation.h"
#include "qlegionary.h"
#include "qgraphicsformationbutton.h"
#include "functionenum.h"
#include "qgraphicsground.h"

class QGraphicsFormationButton;

///
/// \brief Qt graphics scene with ui and graphical representation of the simulation.
///
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
    //void changeCenturiaPosition(const double x, const double y);
    void moveCenturia(const Position& requested_position);

private slots:
    void changeCenturiaPosition(QGraphicsSceneMouseEvent *mouseEvent);
    //void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    void UpdateSimulationData();

    QGraphicsSvgItem test;
    Simulation simulation{};
    std::forward_list<QGraphicsSvgItem*> Qlegionaries{};
    std::forward_list<QLegionary*> Qlegionaries2{};
    QSvgRenderer* legionaryRenderer {new QSvgRenderer(QLatin1String(":/images/legionary.svg"), this)};
    QSvgRenderer* decanusRenderer {new QSvgRenderer(QLatin1String(":/images/decanus.svg"), this)};
    QTimer *timer;

    QGraphicsGround* ground;

    QGraphicsFormationButton* m_startButton;
    QGraphicsFormationButton* m_stopButton;
    QGraphicsFormationButton* m_formLineButton;
    QGraphicsFormationButton* m_formTestudoButton;
    QGraphicsFormationButton* m_formSquareButton;
    QGraphicsFormationButton* m_uiBackground1;
    QGraphicsFormationButton* m_uiBackground2;

    QGraphicsTextItem* txt_formation;
    QGraphicsTextItem* txt_simulation;
    //QGraphicsFormationButton* testudoButton {new QGraphicsFormationButton(Function::FORM_TESTUDO, this)};
    QGraphicsDropShadowEffect * shadowEffect1;
    QGraphicsDropShadowEffect * shadowEffect2;


};

#endif // MAINSCENE_H
