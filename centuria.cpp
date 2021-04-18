#include "centuria.h"

///
/// \brief Centuria::Centuria
/// \param t_inanimate_objects all static objects of the simulation.
/// \param t_soldiers all moving objects, only Legionaries and Decani at this point.
///
Centuria::Centuria(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
                   flist_Soldier_ptr_cstref t_soldiers)
                : m_soldiers(t_soldiers),
                m_inanimate_objects(t_inanimate_objects)
{
    formation(SQUARE);
}

///
/// \brief Make a next step of simulation.
///
void Centuria::step()
{
    std::for_each(m_contubernia.begin(), m_contubernia.end(), [&](Contubernium& contubernium) {
        contubernium.step();
    });
}

///
/// \brief Get actual formation set in Centuria.
/// \return Formation
///
const Formation &Centuria::formation() const
{
    return m_formation;
}

///
/// \brief Set new formation for Centuria.
/// \param new_formation New formation.
///
void Centuria::formation(const enum Formation &new_formation)
{
    m_formation = new_formation;
    sendOrdersDown();
}

///
/// \brief Centuria::contubernia
/// \return Vector of all contubernia the centuria consists of.
///
const std::vector<Contubernium> &Centuria::contubernia() const
{
    return m_contubernia;
}


void Centuria::sendOrdersDown() {
    std::for_each(m_contubernia.begin(), m_contubernia.end(), [&](Contubernium& u) {
        u.sendOrdersDown(formation());
    });
}
