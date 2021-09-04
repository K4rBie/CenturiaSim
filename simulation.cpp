#include "simulation.h"
#include "iostream"

///
/// \brief Default ctor. (links objects owned by centuria and drillfield in order to flatten the structure)
///
Simulation::Simulation() :
    m_trees(drillfield.trees()), m_boulders(drillfield.boulders()), m_waterponds(drillfield.waterponds()){

    initializeInanimateObjectsVector();
    initializeSoldiersVector();

}

void Simulation::initializeSoldiersVector() {
    //m_soldiers.reserve(80);

    for (const auto& contubernium : m_centuria.contubernia()){
        for (const auto& legionary : contubernium.Legionaries()){
            auto legio = std::shared_ptr<Legionary>(legionary);
            m_soldiers.push_front(legio);
        }
        m_soldiers.push_front(contubernium.decanus());
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

///
/// \brief Starts simulation
/// \param interval of the simulation (time between ticks)
///
void Simulation::start(int interval)
{
    if (!running) {
        simulation_timer.setInterval([=](){this->step();}, interval);
        running = true;
    }
}

void Simulation::stop()
{
    if (running) {
        simulation_timer.stop();
        running = false;
    }
}

void Simulation::step() {
    m_centuria.step();
//    for (auto& contubernium : m_centuria.contubernia()){
//        for (auto& legionary : contubernium.legionaries){
//            std::cout << legionary.get()->actualPosition().m_x;
//        }
//        m_soldiers.push_front(contubernium.decanus);
//    }
    drillfield.step();
}

///
/// \brief Order the simulated centuria to change Formation
/// \param new formation to be used
///
void Simulation::changeFormation(const enum Formation &new_formation) {
    m_centuria.formation(new_formation);
}

void Simulation::moveCenturia(const Position &requested_position)
{
    m_centuria.center(requested_position);
}

///
/// \brief soldiers getter
/// \return gets all soldiers generated in the centuria
///
const std::forward_list<std::shared_ptr<Soldier> > &Simulation::soldiers()
{
    return m_soldiers;
}

///
/// \brief centuria getter
/// \return gets centuria
///
const Centuria &Simulation::centuria()
{
    return m_centuria;
}


void Simulation::makedict(){
    std::for_each(drillfield.m_boulders.begin(), drillfield.m_boulders.begin(), [](std::shared_ptr<Boulder> b){
        b->actualPosition();
        b->radius();
    });
}
