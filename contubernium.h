#ifndef CONTUBERNIUM_H
#define CONTUBERNIUM_H

#include "decanus.h"
#include "legionary.h"
#include "formationenum.h"
#include <vector>
#include <deque>
#include <memory>
#include <algorithm>


class Contubernium
{
public:
    Contubernium(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
                 flist_Soldier_ptr_cstref t_soldiers);

    void step();
    void sendOrdersDown(const Formation &new_formation);

    std::forward_list<std::shared_ptr<Legionary>> legionaries;
    std::shared_ptr<Decanus> decanus;

private:
    flist_PhysicalObject_ptr_cstref m_inanimate_objects;
    flist_Soldier_ptr_cstref m_soldiers;
};

#endif // CONTUBERNIUM_H
