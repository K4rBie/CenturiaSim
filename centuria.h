#ifndef CENTURIA_H
#define CENTURIA_H

#include <vector>
#include <memory>
#include <algorithm>
#include "contubernium.h"
#include "formationenum.h"


class Centuria
{
public:
    Centuria(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
             flist_Soldier_ptr_cstref t_soldiers);

    void step();
    const Formation& formation() const;
    void formation(const Formation& new_formation);
    const std::vector<Contubernium>& contubernia() const;

private:
    void sendOrdersDown();
    enum Formation m_formation;
    flist_Soldier_ptr_cstref m_soldiers;
    flist_PhysicalObject_ptr_cstref m_inanimate_objects;
    std::vector<Contubernium> m_contubernia{ 10 , Contubernium{m_inanimate_objects, m_soldiers}};

};

#endif // CENTURIA_H
