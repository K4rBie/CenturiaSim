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
    const std::vector<std::shared_ptr<Tree>>& trees() const;
    const std::vector<std::shared_ptr<Boulder>>& boulders() const;
    const std::vector<std::shared_ptr<WaterPond>>& waterponds() const;
    const std::vector<std::shared_ptr<PhysicalObject>>& inanimateObjects() const;
    void Step();

private:
    double length = 600;
    double width = 800;

    std::vector<std::shared_ptr<Tree>> m_trees {};
    std::vector<std::shared_ptr<Boulder>> m_boulders {};
    std::vector<std::shared_ptr<WaterPond>> m_waterponds {};

    friend class Simulation;

};




#endif // DRILLFIELD_H
