#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <deque>
#include <memory>

#include "centuria.h"
#include "drillfield.h"
#include "formationenum.h"
#include "timer.h"

class Simulation
{
public:
    Simulation();
    void start(int interval);
    void ChangeFormation(const enum Formation& new_formation);

    const std::forward_list<std::shared_ptr<Soldier>>& soldiers();

private:
    void Step();
    Timer simulation_timer{};

    std::forward_list<std::shared_ptr<Soldier>> m_soldiers{};
    std::forward_list<std::shared_ptr<PhysicalObject>> m_inanimate_objects{};

    Centuria centuria{m_inanimate_objects, m_soldiers};
    DrillField drillfield{};

    //std::vector<std::shared_ptr<Soldier>> initializeSoldiersVector();
    void initializeInanimateObjectsVector();

    const std::forward_list<std::shared_ptr<Tree>>& m_trees;
    const std::forward_list<std::shared_ptr<Boulder>>& m_boulders;
    const std::forward_list<std::shared_ptr<WaterPond>>& m_waterponds;


    // wektor wskaźników na pozycje
    // dictionary numeru w wektorze i wsk na -obiektu



    void makedict();
    void initializeSoldiersVector();
};

#endif // SIMULATION_H
