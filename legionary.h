#ifndef LEGIONARY_H
#define LEGIONARY_H

#include "soldier.h"
#include "formationenum.h"


class Legionary : public Soldier
{
public:
    Legionary(Position t_start_position,
              flist_PhysicalObject_ptr_cstref t_nearby_objects,
              flist_PhysicalObject_ptr_cstref t_nearby_soldiers);


    Legionary(flist_PhysicalObject_ptr_cstref t_nearby_objects,
              flist_PhysicalObject_ptr_cstref t_nearby_soldiers);

    void step();

private:
    Position move();

};

#endif // LEGIONARY_H
