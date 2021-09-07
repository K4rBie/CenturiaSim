#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <deque>
#include <memory>

#include "centuria.h"
#include "drillfield.h"
#include "formationenum.h"
#include "timer.h"

///
/// \brief Main object containing all simulated objects and coordinating them.
///
class Simulation
{
public:
    Simulation();
    void start(int interval);
    void stop();
    void changeFormation(const enum Formation& new_formation);
    void moveCenturia(const Position& requested_position);

    const std::forward_list<std::shared_ptr<Soldier>>& soldiers();
    const Centuria& centuria();

private:
    void step();
    Timer simulation_timer{};

    std::forward_list<std::shared_ptr<Soldier>> m_soldiers{};
    std::forward_list<std::shared_ptr<PhysicalObject>> m_inanimate_objects{};

    DrillField drillfield{};
    Centuria m_centuria{m_inanimate_objects, m_soldiers};

    void initializeSoldiersVector();
    void initializeInanimateObjectsVector();

    const std::forward_list<std::shared_ptr<Tree>>& m_trees;
    const std::forward_list<std::shared_ptr<Boulder>>& m_boulders;
    const std::forward_list<std::shared_ptr<WaterPond>>& m_waterponds;

    bool running{};


    // wektor wskaźników na pozycje
    // dictionary numeru w wektorze i wsk na -obiektu



    void makedict(); //unused?

};

#endif // SIMULATION_H
