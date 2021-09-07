#include "mainscene.h"
#include "iostream"

///
/// \brief Creates a graphical representation (based on QGraphicsScene) of the simulated environment.
/// \param parent   A pointer to a parent object (standard Qt stuff)
///
MainScene::MainScene(QObject *parent) {

    QGraphicsScene(this);
    setSceneRect(-400, -300, 800, 600);

    ground = new QGraphicsGround();
    ground->setPos(-750, -600);
    addItem(ground);

    shadowEffect1 = new QGraphicsDropShadowEffect();
    shadowEffect1->setOffset(0,0);
    shadowEffect1->setBlurRadius(50);
    shadowEffect2 = new QGraphicsDropShadowEffect();
    shadowEffect2->setOffset(0,0);
    shadowEffect2->setBlurRadius(50);

    //connect(ground, &QGraphicsGround::mousePressSignal, this, SLOT(MainScene::changeCenturiaPosition(ground->mousePosition())));

    connect(ground, &QGraphicsGround::mousePressEvent, this, &MainScene::changeCenturiaPosition);
    double menu_x = -400;
    double menu_y = -300;

    //QPointF new_position = viewParent->mapToScene(10, 10);
    //std::cout << new_position.x() << ", " << new_position.y() << "\n";

    m_uiBackground1 = new QGraphicsFormationButton(Function::NONE, ":/images/ui_background.svg" , this);
    m_uiBackground1->setPos(menu_x - 270, menu_y -35);
    m_uiBackground1->setGraphicsEffect(shadowEffect1);
    addItem(m_uiBackground1);

    m_uiBackground2 = new QGraphicsFormationButton(Function::NONE, ":/images/ui_background.svg" , this);
    m_uiBackground2->setPos(menu_x - 270, menu_y + 65);
    m_uiBackground2->setGraphicsEffect(shadowEffect2);
    addItem(m_uiBackground2);

    //QFont font ("Times", 12, QFont::Bold);
    QFont font ("Source Sans Pro", 30, QFont::Bold);

    txt_simulation = addText("Simulation");
    txt_simulation->setDefaultTextColor(QColor{"black"});
    txt_simulation->setPos(menu_x - 230, menu_y - 18);
    txt_simulation->setFont(font);
    txt_simulation->setZValue(6);

    txt_formation = addText("Formation");
    txt_formation->setDefaultTextColor(QColor{"black"});
    txt_formation->setPos(menu_x - 230, menu_y + 83);
    txt_formation->setFont(font);
    txt_formation->setZValue(6);

    m_startButton = new QGraphicsFormationButton(Function::START_SIM, ":/images/start_button.svg" , this);
    m_startButton->setPos(menu_x, menu_y);
    addItem(m_startButton);

    m_stopButton = new QGraphicsFormationButton(Function::STOP_SIM, ":/images/stop_button.svg" , this);
    m_stopButton->setPos(menu_x + 40, menu_y);
    addItem(m_stopButton);

    m_formLineButton = new QGraphicsFormationButton(Function::FORM_LINE, ":/images/line_button.svg" , this);
    m_formLineButton->setPos(menu_x, menu_y + 100);
    addItem(m_formLineButton);

    m_formTestudoButton = new QGraphicsFormationButton(Function::FORM_TESTUDO, ":/images/testudo_button.svg" , this);
    m_formTestudoButton->setPos(menu_x + 40, menu_y + 100);
    addItem(m_formTestudoButton);

    m_formSquareButton = new QGraphicsFormationButton(Function::FORM_SQUARE, ":/images/square_button.svg" , this);
    m_formSquareButton->setPos(menu_x + 80, menu_y + 100);
    addItem(m_formSquareButton);



    for (const auto& contubernium : simulation.centuria().contubernia()){

        std::for_each(contubernium.Legionaries().begin(), contubernium.Legionaries().end(), [&](const std::shared_ptr<Legionary> soldier){
            QGraphicsSvgItem *legionaryItem = new QGraphicsSvgItem();
            legionaryItem->setSharedRenderer(legionaryRenderer);
            legionaryItem->setPos(soldier->actualPosition().m_x, soldier->actualPosition().m_y);
            legionaryItem->setTransformOriginPoint(17.3, 17.15);
            Qlegionaries.push_front(legionaryItem);
            addItem(legionaryItem);

//            QLegionary *legitem = new QLegionary(soldier->actualPosition().m_x, soldier->actualPosition().m_y);
//            Qlegionaries2.push_front(legitem);
//            addItem(legitem);
        });
        QGraphicsSvgItem *decanusItem = new QGraphicsSvgItem();
        decanusItem->setSharedRenderer(decanusRenderer);
        decanusItem->setPos(contubernium.decanus()->actualPosition().m_x, contubernium.decanus()->actualPosition().m_y);
        //decanusItem->setTransformOriginPoint(contubernium.decanus()->radius(),contubernium.decanus()->radius());
        decanusItem->setTransformOriginPoint(17.3, 17.15);
        Qlegionaries.push_front(decanusItem);
        addItem(decanusItem);
    }

    addRect(QRect{-125  , -120, 10, 10});
    addRect(QRect{  0   , -120, 10, 10});
    addRect(QRect{ 125  , -120, 10, 10});
    addRect(QRect{-125  , -40 , 10, 10});
    addRect(QRect{ 125  , -40 , 10, 10});
    addRect(QRect{-125  ,  40 , 10, 10});
    addRect(QRect{ 125  ,  40 , 10, 10});
    addRect(QRect{-125  ,  120, 10, 10});
    addRect(QRect{  0   ,  120, 10, 10});
    addRect(QRect{ 125  ,  120, 10, 10});

    //addRect(QRect{-50, -50, 10, 10});
    //addRect(QRect{50, 50, 10, 10});

    //startSimulation(100);
}

///
/// \brief Gives order to the simulation to start.
/// \param interval     time in ms between steps (so-called ticks). It determines the simulation speed.
///
void MainScene::startSimulation(int interval) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainScene::UpdateSimulationData);

    simulation.start(interval);
    timer->start(100);
}

void MainScene::stopSimulation()
{
    simulation.stop();
    timer->stop();
}

void MainScene::changeCenturiaFormation(const Formation &new_formation)
{
    simulation.changeFormation(new_formation);
}

void MainScene::moveCenturia(const Position &requested_position)
{
    simulation.moveCenturia(requested_position);
}

void MainScene::changeCenturiaPosition(QGraphicsSceneMouseEvent *mouseEvent)
{
    QPointF Qpos = ground->mapToScene(mouseEvent->pos());
    Position pos = Position{Qpos.rx(), Qpos.ry()};
    moveCenturia(pos);
}

//void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
//{
//    QGraphicsScene::mousePressEvent(mouseEvent);


//}

///
/// \brief MainScene::~MainScene
///
MainScene::~MainScene()
{
    for (QGraphicsSvgItem * ptr : Qlegionaries){
        delete ptr;
    }
    for (QLegionary * ptr : Qlegionaries2){
        delete ptr;
    }
}


void MainScene::UpdateSimulationData() {

    std::forward_list<QGraphicsSvgItem*>::iterator q_legio_iter = Qlegionaries.begin();
    Position sim_pos;
    double pos_x0;
    double pos_y0;

    for (const auto& contubernium : simulation.centuria().contubernia()){
        sim_pos = contubernium.decanus()->actualPosition();
        pos_x0 = sim_pos.m_x - (*q_legio_iter)->pos().rx();
        pos_y0 = sim_pos.m_y - (*q_legio_iter)->pos().ry();

        if (abs(pos_x0) > 1 || abs(pos_y0) > 1) {
            (*q_legio_iter)->setRotation(std::atan2(pos_y0,pos_x0)*180/M_PI + 90);
        }  else {
            (*q_legio_iter)->setRotation(0);
        }


        (*q_legio_iter)->setPos(contubernium.decanus()->actualPosition().m_x, contubernium.decanus()->actualPosition().m_y);
        //(*q_legio_iter).setr
        q_legio_iter++;


        for (const auto& legionary : contubernium.Legionaries()){
            sim_pos = legionary->actualPosition();
            pos_x0 = sim_pos.m_x - (*q_legio_iter)->pos().rx();
            pos_y0 = sim_pos.m_y - (*q_legio_iter)->pos().ry();


            if (abs(pos_x0) > 1 || abs(pos_y0) > 1) {
                (*q_legio_iter)->setRotation(std::atan2(pos_y0,pos_x0)*180/M_PI + 90);
            }  else {
                (*q_legio_iter)->setRotation(0);
            }

            (*q_legio_iter)->setPos(legionary->actualPosition().m_x, legionary->actualPosition().m_y);
            q_legio_iter++;
        }

    }

}
