#include "drillfield.h"
#include <iostream>

///
/// \brief DrillField::trees
/// \return list of trees in the field.
///
const std::forward_list<std::shared_ptr<Tree> > &DrillField::trees() const
{
    return m_trees;
}

///
/// \brief DrillField::boulders
/// \return List of boulders in the field.
///
const std::forward_list<std::shared_ptr<Boulder> > &DrillField::boulders() const
{
    return m_boulders;
}


///
/// \brief DrillField::waterponds
/// \return List of waterponds in the field.
///
const std::forward_list<std::shared_ptr<WaterPond> > &DrillField::waterponds() const
{
    return m_waterponds;
}

///
/// \brief DrillField::step In case any of the static objects somehow interacts with others.
///
void DrillField::step()
{
    for (auto tree : m_trees) {
        tree->step();
    }

    for (auto boulder : m_boulders) {
         boulder->step();
    }

    for (auto waterpond : m_waterponds) {
         waterpond->step();
    }
}
