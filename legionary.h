#ifndef LEGIONARY_H
#define LEGIONARY_H

#include "soldier.h"
#include "formationenum.h"

class Legionary : public Soldier
{
public:
    Legionary(Position t_start_position,
              double t_radius,
              vec_PhysicalObject_shptr_cstref t_nearby_objects,
              vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
              : Soldier(t_start_position, t_radius, t_nearby_objects, t_nearby_soldiers){};
    Legionary(vec_PhysicalObject_shptr_cstref t_nearby_objects,
              vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
              : Soldier(Position{}, 2.f, t_nearby_objects, t_nearby_soldiers){};


    void Step();
    Position TargetPosition();
};

#endif // LEGIONARY_H
