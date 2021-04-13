#include "centuria.h"

Centuria::Centuria(vec_PhysicalObject_shptr_cstref t_inanimate_objects,
                   vec_Soldier_shptr_cstref t_soldiers)
                : m_soldiers(t_soldiers),
                m_inanimate_objects(t_inanimate_objects)
{
    formation(Square);
}

void Centuria::Step()
{
    std::for_each(contubernia.begin(), contubernia.end(), [&](Contubernium& contubernium) {
        contubernium.Step();
    });
}

const Formation &Centuria::formation() const
{
    return m_formation;
}

void Centuria::formation(const enum Formation &new_formation)
{
    m_formation = new_formation;
    SendOrdersDown();
}

void Centuria::SendOrdersDown() {
    std::for_each(contubernia.begin(), contubernia.end(), [&](Contubernium& u) {
        u.SendOrdersDown(formation());
    });
}
