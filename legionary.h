#ifndef LEGIONARY_H
#define LEGIONARY_H

#include "soldier.h"
#include "formationenum.h"

class Legionary : public Soldier
{
public:
    Legionary(Position t_start_position,
              flist_PhysicalObject_ptr_cstref t_nearby_objects,
              flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
              : Soldier(t_start_position, 10.f, t_nearby_objects, t_nearby_soldiers){};

    Legionary(flist_PhysicalObject_ptr_cstref t_nearby_objects,
              flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
              : Soldier(Position{}, 10.f, t_nearby_objects, t_nearby_soldiers){};


    void step();
};

#endif // LEGIONARY_H
