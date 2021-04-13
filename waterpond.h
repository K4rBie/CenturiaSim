#ifndef WATERPOND_H
#define WATERPOND_H

#include "physicalobject.h"

class WaterPond : public PhysicalObject
{
public:
    WaterPond(Position t_start_position, double t_radius)
        : PhysicalObject(t_start_position, t_radius){};
    void Step(){};
};

#endif // WATERPOND_H