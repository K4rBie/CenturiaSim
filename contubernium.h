#ifndef CONTUBERNIUM_H
#define CONTUBERNIUM_H

#include <vector>
#include <deque>
#include <memory>
#include <algorithm>

#include "decanus.h"
#include "legionary.h"
#include "formationenum.h"


class Contubernium
{
public:
    Contubernium(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
                 flist_Soldier_ptr_cstref t_soldiers);

    void step();
    void sendOrdersDown(const Formation &new_formation);

    const std::forward_list<std::shared_ptr<Legionary> > &Legionaries() const;
    const std::shared_ptr<Decanus> &decanus() const;

private:
    std::forward_list<std::shared_ptr<Legionary>> m_legionaries;
    std::shared_ptr<Decanus> m_decanus;

    flist_PhysicalObject_ptr_cstref m_inanimate_objects;
    flist_Soldier_ptr_cstref m_soldiers;
};

#endif // CONTUBERNIUM_H
