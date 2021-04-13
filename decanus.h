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
    Decanus(std::vector<std::shared_ptr<Legionary>> t_subordinates,
            Position t_start_position,
            double t_radius,
            vec_PhysicalObject_shptr_cstref t_nearby_objects,
            vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
        : Soldier(t_start_position, t_radius, t_nearby_objects, t_nearby_soldiers),
          m_subordinates(t_subordinates){};

    Decanus(std::vector<std::shared_ptr<Legionary>> t_subordinates,
            vec_PhysicalObject_shptr_cstref t_nearby_objects,
            vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
        : Soldier(Position{}, 2.f, t_nearby_objects, t_nearby_soldiers),
          m_subordinates(t_subordinates){};

    void Step();

    void formation(const Formation &newFormation);
    const Formation& formation() const;

    void giveOrders();
    void sendLineFormationOrders();
    void sendTestudoFormationOrders();
    void sendSquareFormationOrders();
private:
    Decanus(); //should stay without definition

    std::vector<std::shared_ptr<Legionary>> m_subordinates;
    Formation m_formation {Formation(Square)};
};

#endif // DECANUS_H
