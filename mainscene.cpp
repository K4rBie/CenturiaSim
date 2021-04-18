#include "mainscene.h"

MainScene::MainScene() {
    setSceneRect(-400, -300, 800, 600);

    QGraphicsPixmapItem* ground = new QGraphicsPixmapItem(QPixmap(":/images/ground.png"));
    ground->setPos(-800, -600);
    addItem(ground);

    std::for_each(simulation.soldiers().begin(), simulation.soldiers().end(), [&](const std::shared_ptr<Soldier> soldier) {
        QGraphicsSvgItem *legionaryItem = new QGraphicsSvgItem();
        legionaryItem->setSharedRenderer(legionaryRenderer);
        legionaryItem->setPos(soldier->actualPosition().m_x, soldier->actualPosition().m_y);
//        legionaryItem->setZValue(1);
//        std::cout << position.x() << ", " << position.y() << "\n";
//        std::cout << soldier->actualPosition().m_x << ", " << soldier->actualPosition().m_x << "\n";
        Qlegionaries.push_back(legionaryItem);
        addItem(legionaryItem);
    });
}

void MainScene::startSimulation(int interval) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainScene::UpdateSimulationData);

    simulation.start(interval);
    timer->start(1000);


}

void MainScene::UpdateSimulationData() {
    std::forward_list<std::shared_ptr<Soldier>>::const_iterator legio_iter = simulation.soldiers().begin();
    auto legio_iter_end = simulation.soldiers().end();

    std::vector<QGraphicsSvgItem*>::iterator q_legio_iter = Qlegionaries.begin();
    auto q_legio_iter_end = Qlegionaries.end();

    while (legio_iter != legio_iter_end && q_legio_iter != q_legio_iter_end) {
        q_legio_iter
        //legio_iter->get()->actualPosition().m_x;
        legio_iter._M_next();
    }
}
