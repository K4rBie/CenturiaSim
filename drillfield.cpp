#include "drillfield.h"
#include <iostream>


DrillField::DrillField()
{

}

const std::vector<std::shared_ptr<Tree> > &DrillField::trees() const
{
    return m_trees;
}

const std::vector<std::shared_ptr<Boulder> > &DrillField::boulders() const
{
    return m_boulders;
}

const std::vector<std::shared_ptr<WaterPond> > &DrillField::waterponds() const
{
    return m_waterponds;
}

const std::vector<std::shared_ptr<PhysicalObject> > &DrillField::inanimateObjects() const
{

}

void DrillField::Step()
{
    for (auto tree : m_trees) {
        tree->Step();
    }

    for (auto boulder : m_boulders) {
         boulder->Step();
    }

    for (auto waterpond : m_waterponds) {
         waterpond->Step();
    }
}
