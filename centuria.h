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
    Centuria(vec_PhysicalObject_shptr_cstref t_inanimate_objects,
             vec_Soldier_shptr_cstref t_soldiers);

    void Step();

    const Formation& formation() const;
    void formation(const Formation& new_formation);

    std::vector<Contubernium> contubernia{ 10 , Contubernium{m_inanimate_objects, m_soldiers}};

private:
    // to świetna okazja żeby zastosować templatki bo masz kilka typów, które robią to samo, przesyłają polecenie niżej
    void SendOrdersDown(std::vector<Contubernium> &units);
    void SendOrdersDown();
    enum Formation m_formation;
    vec_Soldier_shptr_cstref m_soldiers;
    vec_PhysicalObject_shptr_cstref m_inanimate_objects;
};

#endif // CENTURIA_H
