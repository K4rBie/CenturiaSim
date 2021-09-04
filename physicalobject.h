#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <cmath>

#include "position.h"


class PhysicalObject
{
public:
    ///
    /// \brief PhysicalObject constructor
    /// \param t_start_position Initial position of the object
    /// \param t_radius         Radius of the object
    ///
    PhysicalObject(Position t_start_position, double t_radius)
        : m_actual_position(t_start_position), m_radius(t_radius) {}

    ///
    /// \brief PhysicalObject constructor.
    /// \param t_x          Initial x position of the object
    /// \param t_y          Initial y position of the object
    /// \param t_radius     Radius of the object
    ///
    PhysicalObject(double t_x, double t_y, double t_radius)
        : m_actual_position(Position{t_x, t_y}), m_radius(t_radius) {}

    ///
    /// \brief PhysicalObject constructor with default initial position and radius (only zeroes).
    ///
    PhysicalObject() : m_actual_position(Position{0.f,0.f}), m_radius(0) {}

    ///
    /// \brief virtual step as any object could do something meaningful.
    ///
    virtual void step()=0;

    ///
    /// \brief actual Position getter
    /// \return gets actual position
    ///
    const Position& actualPosition() const {return m_actual_position;}

    ///
    /// \brief radius getter
    /// \return gets radius
    ///
    double radius() {return m_radius;}

protected:
    Position m_actual_position {};
    double m_radius;

};


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif // PHYSICALOBJECT_H
