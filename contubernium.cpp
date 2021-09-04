#include "contubernium.h"
#include "iostream"

///
/// \brief Contubernium::Contubernium
/// \param t_inanimate_objects      All static objects of the simulation
/// \param t_soldiers               All moving objects, only Legionaries and Decani at this point
///
Contubernium::Contubernium(flist_PhysicalObject_ptr_cstref t_inanimate_objects, flist_Soldier_ptr_cstref t_soldiers)
                          : m_inanimate_objects (t_inanimate_objects), m_soldiers (t_soldiers)
{
    m_legionaries = {
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))),
        std::shared_ptr<Legionary> (
        new Legionary(m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers)))
    };

    m_decanus = std::shared_ptr<Decanus> {
            new Decanus(m_legionaries, m_inanimate_objects, flist_PhysicalObject_ptr_cstref(m_soldiers))
    };
}

///
/// \brief Make a next step of simulation.
///
void Contubernium::step()
{
    m_decanus->step();
    std::for_each(m_legionaries.begin(), m_legionaries.end(), [](std::shared_ptr<Legionary> legionary) {
        legionary->step();
        //std::cout << legionary.get()->actualPosition().m_x;
    });
}

///
/// \brief Send orders to decanus and down to its legionaries.
/// \param new_formation    new formation to form lel.
///
void Contubernium::sendOrdersDown(const enum Formation &new_formation)
{
    m_decanus->formation(new_formation);
}

///
/// \brief Decanus getter.
/// \return decanus
///
const std::shared_ptr<Decanus> &Contubernium::decanus() const
{
    return m_decanus;
}

///
/// \brief Legionaries getter.
/// \return List of legionaries in contubernium.
///
const std::forward_list<std::shared_ptr<Legionary> > &Contubernium::Legionaries() const
{
    return m_legionaries;
}
