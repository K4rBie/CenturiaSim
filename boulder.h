#ifndef BOULDER_H
#define BOULDER_H

#include "physicalobject.h"

/**
 * @brief Class providing functions of boulder on the ground.
 */

class Boulder : public PhysicalObject
{
public:
    Boulder(Position t_start_position, double t_radius);
    void step();
};

#endif // BOULDER_H
