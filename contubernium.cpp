#include "contubernium.h"

Contubernium::Contubernium(vec_PhysicalObject_shptr_cstref t_inanimate_objects, vec_Soldier_shptr_cstref t_soldiers) :
    m_inanimate_objects(t_inanimate_objects), m_soldiers(t_soldiers)
{

}

void Contubernium::Step()
{
    decanus->Step();
    std::for_each(legionaries.begin(), legionaries.end(), [](std::shared_ptr<Legionary> legionary) {
        legionary->Step();
    });
}

void Contubernium::SendOrdersDown(const enum Formation &new_formation)
{
    decanus->formation(new_formation);
}
