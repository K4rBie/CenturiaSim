#include "mainscene.h"
#include "iostream"

///
/// \brief Creates a graphical representation (based on QGraphicsScene) of the simulated environment.
/// \param parent   A pointer to a parent object (standard Qt stuff)
///
MainScene::MainScene(QObject *parent) {
    QGraphicsScene(this);
    setSceneRect(-400, -300, 800, 600);

    QGraphicsPixmapItem* ground = new QGraphicsPixmapItem(QPixmap(":/images/ground.png"));
    ground->setPos(-800, -600);
    addItem(ground);

    m_startButton = new QGraphicsFormationButton(Function::START_SIM, ":/images/start_button.svg" , this);
    m_startButton->setPos(-300,0);
    addItem(m_startButton);

    m_stopButton = new QGraphicsFormationButton(Function::STOP_SIM, ":/images/stop_button.svg" , this);
    m_stopButton->setPos(-280,0);
    addItem(m_stopButton);

    m_formLineButton = new QGraphicsFormationButton(Function::FORM_LINE, ":/images/line_button.svg" , this);
    m_formLineButton->setPos(-260,0);
    addItem(m_formLineButton);

    m_formTestudoButton = new QGraphicsFormationButton(Function::FORM_TESTUDO, ":/images/testudo_button.svg" , this);
    m_formTestudoButton->setPos(-240,0);
    addItem(m_formTestudoButton);

    m_formSquareButton = new QGraphicsFormationButton(Function::FORM_SQUARE, ":/images/square_button.svg" , this);
    m_formSquareButton->setPos(-220,0);
    addItem(m_formSquareButton);



    for (const auto& contubernium : simulation.centuria().contubernia()){

        std::for_each(contubernium.Legionaries().begin(), contubernium.Legionaries().end(), [&](const std::shared_ptr<Legionary> soldier){
            QGraphicsSvgItem *legionaryItem = new QGraphicsSvgItem();
            legionaryItem->setSharedRenderer(legionaryRenderer);
            legionaryItem->setPos(soldier->actualPosition().m_x, soldier->actualPosition().m_y);
            Qlegionaries.push_front(legionaryItem);
            addItem(legionaryItem);

//            QLegionary *legitem = new QLegionary(soldier->actualPosition().m_x, soldier->actualPosition().m_y);
//            Qlegionaries2.push_front(legitem);
//            addItem(legitem);
        });
        QGraphicsSvgItem *decanusItem = new QGraphicsSvgItem();
        decanusItem->setSharedRenderer(decanusRenderer);
        decanusItem->setPos(contubernium.decanus()->actualPosition().m_x, contubernium.decanus()->actualPosition().m_y);
        Qlegionaries.push_front(decanusItem);
        addItem(decanusItem);
    }

    addRect(QRect{-100  , -125, 10, 10});
    addRect(QRect{  0   , -125, 10, 10});
    addRect(QRect{ 100  , -125, 10, 10});
    addRect(QRect{-125 , -50  , 10, 10});
    addRect(QRect{ 125 , -50  , 10, 10});
    addRect(QRect{-125 ,  50  , 10, 10});
    addRect(QRect{ 125 ,  50  , 10, 10});
    addRect(QRect{-100  ,  125, 10, 10});
    addRect(QRect{  0   ,  125, 10, 10});
    addRect(QRect{ 100  ,  125, 10, 10});

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
    //std::cout <<simulation.soldiers().front().get()->actualPosition().m_x << "\n";
    //std::cout <<simulation.centuria().contubernia().front().decanus->actualPosition().m_x << "\n";
    //std::cout <<simulation.centuria().contubernia().front().legionaries.front()->actualPosition().m_x << "\n";
    //std::forward_list<std::shared_ptr<Soldier>>::const_iterator legio_iter = simulation.soldiers().begin();
    //auto legio_iter_end = simulation.soldiers().end();

    std::forward_list<QGraphicsSvgItem*>::iterator q_legio_iter = Qlegionaries.begin();
    //auto q_legio_iter_end = Qlegionaries.end();

    for (const auto& contubernium : simulation.centuria().contubernia()){

        (*q_legio_iter)->setPos(contubernium.decanus()->actualPosition().m_x, contubernium.decanus()->actualPosition().m_y);
        q_legio_iter++;
        for (const auto& legionary : contubernium.Legionaries()){
            (*q_legio_iter)->setPos(legionary->actualPosition().m_x, legionary->actualPosition().m_y);
            q_legio_iter++;
        }

    }

//    while (legio_iter != legio_iter_end && q_legio_iter != q_legio_iter_end) {
//        Position sim_pos = legio_iter->get()->actualPosition();
//        std::cout << sim_pos.m_x;
//        (*q_legio_iter)->setPos(sim_pos.m_x, sim_pos.m_y);

//        legio_iter._M_next();
//        q_legio_iter++;
//    }
}
