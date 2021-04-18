#ifndef SOLDIER_H
#define SOLDIER_H

#include <vector>
#include <deque>
#include <memory>
#include <forward_list>
#include <algorithm>

#include "physicalobject.h"

using flist_PhysicalObject_ptr_cstref =
      const std::forward_list<std::shared_ptr<PhysicalObject>>&;

class Soldier : public PhysicalObject
{
public:
    Soldier(Position t_start_position, double t_radius,
            flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
            : PhysicalObject(t_start_position, t_radius),
            m_nearby_objects(t_nearby_objects),
            m_nearby_soldiers(t_nearby_soldiers){};

    Soldier(flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
            : PhysicalObject(Position{}, 10.f),
            m_nearby_objects(t_nearby_objects),
            m_nearby_soldiers(t_nearby_soldiers){}; // no ogólnie spoko, ale może lepiej na to nie pozwalać?

    virtual const Position& targetPosition();
    virtual void targetPosition(const Position& new_target);
    virtual void step();

protected:
    virtual Position move();
    bool isValidPosition(const Position &position);
    bool isValidPosition(const Position &position, flist_PhysicalObject_ptr_cstref objects);

    flist_PhysicalObject_ptr_cstref m_nearby_objects;
    flist_PhysicalObject_ptr_cstref m_nearby_soldiers;

    Position m_target_position {};
    double speed {1};

private:

};

using flist_Soldier_ptr_cstref =
      std::forward_list<std::shared_ptr<Soldier>>&;


#endif // SOLDIER_H
