#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <cmath>

#include "position.h"

class PhysicalObject
{
protected:
    Position m_actual_position = {};
    double m_radius;

public:
    PhysicalObject(Position t_start_position, double t_radius)
        : m_actual_position(t_start_position), m_radius(t_radius){}

    PhysicalObject(double t_x, double t_y, double t_radius)
        : m_actual_position(Position{t_x, t_y}), m_radius(t_radius){}

    PhysicalObject() : m_actual_position(Position{0,0}), m_radius(0){}

    virtual void Step()=0;

    const Position& actualPosition() {return m_actual_position;}

    double radius() {return m_radius;}


};




#endif // PHYSICALOBJECT_H