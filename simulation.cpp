#include "simulation.h"

Simulation::Simulation() :
    m_trees(drillfield.trees()), m_boulders(drillfield.boulders()), m_waterponds(drillfield.waterponds()),
    m_soldiers(initializeSoldiersVector()),
    m_inanimate_objects(initializeInanimateObjectsVector()){}

std::vector<std::shared_ptr<Soldier>> Simulation::initializeSoldiersVector() {
    auto soldiers = std::vector<std::shared_ptr<Soldier>>{};
    soldiers.reserve(80);

    for (auto& contubernium : centuria.contubernia){
        soldiers.insert(soldiers.end(), contubernium.legionaries.begin(), contubernium.legionaries.end());
        soldiers.push_back(contubernium.decanus);
    }

    return soldiers;
}

std::vector<std::shared_ptr<PhysicalObject>> Simulation::initializeInanimateObjectsVector()
{
    auto objects = std::vector<std::shared_ptr<PhysicalObject>>{};
    objects.reserve(20);

    auto boulders = drillfield.boulders();
    auto trees = drillfield.trees();
    auto waterponds = drillfield.waterponds();

    objects.insert(objects.end(), boulders.begin(), boulders.end());
    objects.insert(objects.end(), trees.begin(), trees.end());
    objects.insert(objects.end(), waterponds.begin(), waterponds.end());

    return objects;
}

void Simulation::Start(int interval)
{
    simulation_timer.setInterval([=](){this->Step();}, interval);
}

void Simulation::Step() {
    centuria.Step();
    drillfield.Step();
}

void Simulation::ChangeFormation(const enum Formation &new_formation) {
    centuria.formation(new_formation);
}


void Simulation::makedict(){
    std::for_each(drillfield.m_boulders.begin(), drillfield.m_boulders.begin(), [](std::shared_ptr<Boulder> b){
        b->actualPosition();
        b->radius();
    });
}
