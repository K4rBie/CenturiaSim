#include "centuria.h"

///
/// \brief Constructor.
/// \param t_inanimate_objects  All static objects of the simulation
/// \param t_soldiers           All moving objects, only Legionaries and Decani at this point
///
Centuria::Centuria(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
                   flist_Soldier_ptr_cstref t_soldiers)
                   : m_soldiers(t_soldiers),
                   m_inanimate_objects(t_inanimate_objects)
{
    formation(SQUARE);
    //{ 10 , Contubernium{m_inanimate_objects, m_soldiers}}; jakoś nie działa tak jak sobie to wyobrażałem

    for (int i = 0; i<10  ; i++ ) {
        m_contubernia.push_back(Contubernium{m_inanimate_objects, m_soldiers});
    }
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
/// \brief Gets actual formation set in Centuria.
/// \return Formation   Formation enum
///
const Formation &Centuria::formation() const
{
    return m_formation;
}

///
/// \brief Sets new formation for Centuria.
/// \param new_formation    New formation
///
void Centuria::formation(const enum Formation &new_formation)
{
    m_formation = new_formation;
    sendOrdersDown();
}

///
/// \brief Contubernia getter.
/// \return Vector of all contubernia the centuria consists of.
///
const std::vector<Contubernium> &Centuria::contubernia() const
{
    return m_contubernia;
}

///
/// \brief Center of contubernia getter.
/// \return Requested center point of centuria
///
const Position &Centuria::center()
{
    return m_center;
}

///
/// \brief Center of contubernia setter.
///
void Centuria::center(const Position &requested_center)
{
    m_center = requested_center;
}

///
/// \brief Sends orders put most likely by user down to contubernia and to decani.
///
void Centuria::sendOrdersDown() {
    std::for_each(m_contubernia.begin(), m_contubernia.end(), [&](Contubernium& u) {
        u.sendOrdersDown(formation());
    });
}
