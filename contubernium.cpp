#include "contubernium.h"

///
/// \brief Contubernium::Contubernium
/// \param t_inanimate_objects all static objects of the simulation.
/// \param t_soldiers all moving objects, only Legionaries and Decani at this point.
///
Contubernium::Contubernium(flist_PhysicalObject_ptr_cstref t_inanimate_objects, flist_Soldier_ptr_cstref t_soldiers)
                          : m_inanimate_objects (t_inanimate_objects), m_soldiers (t_soldiers)
{
    legionaries = { 7, std::shared_ptr<Legionary> {
            new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))}
    };

    decanus = std::shared_ptr<Decanus> {
            new Decanus(legionaries, m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))
    };
}

///
/// \brief Make a next step of simulation.
///
void Contubernium::step()
{
    decanus->step();
    std::for_each(legionaries.begin(), legionaries.end(), [](std::shared_ptr<Legionary> legionary) {
        legionary->step();
    });
}

void Contubernium::sendOrdersDown(const enum Formation &new_formation)
{
    decanus->formation(new_formation);
}
