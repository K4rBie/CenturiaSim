#ifndef BOULDER_H
#define BOULDER_H

#include "physicalobject.h"

class Boulder : public PhysicalObject
{
public:
    Boulder(Position t_start_position, double t_radius)
        : PhysicalObject(t_start_position, t_radius){};
    void Step(){};
};

#endif // BOULDER_H
