#include "boulder.h"


///
/// \brief Boulder constructor
/// \param t_start_position     Position of the boulder. Boulder cannot be moved
/// \param t_radius             Radius (so size) of created boulder
///
Boulder::Boulder(Position t_start_position, double t_radius) : PhysicalObject(t_start_position, t_radius){}

///
/// \brief Simulation step. Does nothing. Typical boulder
///
void Boulder::step(){}
