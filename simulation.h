#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <memory>

#include "centuria.h"
#include "drillfield.h"
#include "formationenum.h"
#include "timer.h"

class Simulation
{
public:
    Simulation();
    void Start(int interval);
    void ChangeFormation(const enum Formation& new_formation);

private:
    void Step();
    Timer simulation_timer{};
    Centuria centuria{m_inanimate_objects, m_soldiers};
    DrillField drillfield{};

    std::vector<std::shared_ptr<Soldier>> m_soldiers;
    std::vector<std::shared_ptr<PhysicalObject>> m_inanimate_objects;

    std::vector<std::shared_ptr<Soldier>> initializeSoldiersVector();
    std::vector<std::shared_ptr<PhysicalObject> > initializeInanimateObjectsVector();

    const std::vector<std::shared_ptr<Tree>>& m_trees;
    const std::vector<std::shared_ptr<Boulder>>& m_boulders;
    const std::vector<std::shared_ptr<WaterPond>>& m_waterponds;


    // wektor wskaźników na pozycje
    // dictionary numeru w wektorze i wsk na -obiektu



    void makedict();
};

#endif // SIMULATION_H
