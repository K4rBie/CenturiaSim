#ifndef TREE_H
#define TREE_H

#include "physicalobject.h"

class Tree : public PhysicalObject
{
public:
    Tree(Position t_start_position, double t_radius)
        : PhysicalObject(t_start_position, t_radius){};
    Tree();
    void step(){};
};

#endif // TREE_H
