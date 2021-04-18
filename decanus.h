#ifndef DECANUS_H
#define DECANUS_H

#include <vector>
#include <memory>

#include "soldier.h"
#include "legionary.h"
#include "formationenum.h"


class Decanus : public Soldier
{
public:
    Decanus(std::forward_list<std::shared_ptr<Legionary>> t_subordinates,
            Position t_start_position,
            flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
            : Soldier(t_start_position, 10.f, t_nearby_objects, t_nearby_soldiers),
            m_subordinates(t_subordinates){};

    Decanus(std::forward_list<std::shared_ptr<Legionary>> t_subordinates,
            flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
            : Soldier(Position{}, 10.f, t_nearby_objects, t_nearby_soldiers),
            m_subordinates(t_subordinates){};

    void step();

    void formation(const Formation &new_formation);
    const Formation& formation() const;

    void giveOrders();
    void sendLineFormationOrders();
    void sendTestudoFormationOrders();
    void sendSquareFormationOrders();
private:
    Decanus(); //should stay without definition

    std::forward_list<std::shared_ptr<Legionary>> m_subordinates;
    Formation m_formation {Formation(SQUARE)};
};

#endif // DECANUS_H
