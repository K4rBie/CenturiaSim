#include "simulation.h"

Simulation::Simulation() :
    m_trees(drillfield.trees()), m_boulders(drillfield.boulders()), m_waterponds(drillfield.waterponds()){

    initializeInanimateObjectsVector();
    initializeSoldiersVector();

}

void Simulation::initializeSoldiersVector() {
    //m_soldiers.reserve(80);

    for (auto& contubernium : centuria.m_contubernia){
        for (auto& legionary : contubernium.legionaries){
            m_soldiers.push_front(legionary);
        }
        m_soldiers.push_front(contubernium.decanus);
    }
}

void Simulation::initializeInanimateObjectsVector()
{
    //auto objects = std::vector<std::shared_ptr<PhysicalObject>>{};
    //m_inanimate_objects.reserve(20);

    //auto boulders = drillfield.boulders();
    auto trees = drillfield.trees();
    auto waterponds = drillfield.waterponds();

    for (auto& obj : drillfield.boulders()){
        m_inanimate_objects.push_front(obj);
    }

    //m_inanimate_objects.insert(m_inanimate_objects.end(), boulders.begin(), boulders.end());
    //m_inanimate_objects.insert(m_inanimate_objects.end(), trees.begin(), trees.end());
    //m_inanimate_objects.insert(m_inanimate_objects.end(), waterponds.begin(), waterponds.end());

}

void Simulation::start(int interval)
{
    simulation_timer.setInterval([=](){this->Step();}, interval);
}

void Simulation::Step() {
    centuria.step();
    drillfield.step();
}

void Simulation::ChangeFormation(const enum Formation &new_formation) {
    centuria.formation(new_formation);
}

const std::forward_list<std::shared_ptr<Soldier> > &Simulation::soldiers()
{
    return m_soldiers;
}


void Simulation::makedict(){
    std::for_each(drillfield.m_boulders.begin(), drillfield.m_boulders.begin(), [](std::shared_ptr<Boulder> b){
        b->actualPosition();
        b->radius();
    });
}
