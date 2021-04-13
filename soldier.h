#ifndef SOLDIER_H
#define SOLDIER_H

#include <vector>
#include <memory>
#include <algorithm>

#include "physicalobject.h"

using vec_PhysicalObject_shptr_cstref =
      const std::vector<std::shared_ptr<PhysicalObject>>&;

class Soldier : public PhysicalObject
{
public:
    Soldier(Position t_start_position, double t_radius,
            vec_PhysicalObject_shptr_cstref t_nearby_objects,
            vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
        : PhysicalObject(t_start_position, t_radius),
          m_nearby_objects(t_nearby_objects),
          m_nearby_soldiers(t_nearby_soldiers){};

    Soldier(vec_PhysicalObject_shptr_cstref t_nearby_objects,
            vec_PhysicalObject_shptr_cstref t_nearby_soldiers)
        : PhysicalObject(Position{}, 1),
          m_nearby_objects(t_nearby_objects),
          m_nearby_soldiers(t_nearby_soldiers){}; // no ogólnie spoko, ale może lepiej na to nie pozwalać?

    virtual Position targetPosition();
    virtual void targetPosition(const Position& new_target);

    virtual void Step();

protected:
    virtual Position move();
    bool isValidPosition(const Position &position);
    bool isValidPosition(const Position &position, vec_PhysicalObject_shptr_cstref objects);

    vec_PhysicalObject_shptr_cstref m_nearby_objects;
    vec_PhysicalObject_shptr_cstref m_nearby_soldiers;

    Position m_target_position {};
    double speed {1};

private:

};

using vec_Soldier_shptr_cstref =
      std::vector<std::shared_ptr<Soldier>>&;


#endif // SOLDIER_H
