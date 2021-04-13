#ifndef CONTUBERNIUM_H
#define CONTUBERNIUM_H

#include "decanus.h"
#include "legionary.h"
#include "formationenum.h"
#include <vector>
#include <memory>
#include <algorithm>


class Contubernium
{
public:
    Contubernium(vec_PhysicalObject_shptr_cstref t_inanimate_objects,
                 vec_Soldier_shptr_cstref t_soldiers);
    void Step();
    void SendOrdersDown(const Formation &new_formation);

    std::vector<std::shared_ptr<Legionary>> legionaries{
        7,
        std::shared_ptr<Legionary>{new Legionary(m_inanimate_objects, vec_PhysicalObject_shptr_cstref(m_soldiers))}
    };

    std::shared_ptr<Decanus> decanus { new Decanus(legionaries, m_inanimate_objects, vec_PhysicalObject_shptr_cstref(m_soldiers))};

private:
    vec_PhysicalObject_shptr_cstref m_inanimate_objects;
    vec_Soldier_shptr_cstref m_soldiers;
};

#endif // CONTUBERNIUM_H
