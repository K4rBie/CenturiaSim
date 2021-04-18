#ifndef DRILLFIELD_H
#define DRILLFIELD_H
#include <vector>

#include "centuria.h"
#include "tree.h"
#include "boulder.h"
#include "waterpond.h"

class DrillField
{
public:
    DrillField();
    const std::forward_list<std::shared_ptr<Tree>>& trees() const;
    const std::forward_list<std::shared_ptr<Boulder>>& boulders() const;
    const std::forward_list<std::shared_ptr<WaterPond>>& waterponds() const;
    void step();

private:
    double length = 600;
    double width = 800;

    std::forward_list<std::shared_ptr<Tree>> m_trees {};
    std::forward_list<std::shared_ptr<Boulder>> m_boulders {};
    std::forward_list<std::shared_ptr<WaterPond>> m_waterponds {};

    friend class Simulation; // potrzebne?

};




#endif // DRILLFIELD_H
