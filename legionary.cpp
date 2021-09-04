#include "legionary.h"

///
/// \brief Legionary::Legionary
/// \param t_start_position        Position on the field legionary is initially placed
/// \param t_nearby_objects        Static objects (list of)
/// \param t_nearby_soldiers       All soldiers really
///
Legionary::Legionary(Position t_start_position, flist_PhysicalObject_ptr_cstref t_nearby_objects, flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
    : Soldier(t_start_position, 10.f, t_nearby_objects, t_nearby_soldiers){}

///
/// \brief Legionary::Legionary
/// \param t_nearby_objects         Static objects (list of)
/// \param t_nearby_soldiers        All soldiers really
///
Legionary::Legionary(flist_PhysicalObject_ptr_cstref t_nearby_objects, flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
    : Soldier(Position{}, 10.f, t_nearby_objects, t_nearby_soldiers){}


///
/// \brief Make a next step of simulation.
///
void Legionary::step()
{
    this->move();
}

Position Legionary::move()
{

    // policz wszystkie siły
    double x_force = 0;
    double y_force = 0;
    double s_force = 0;
    double epsilon = 1;
    double s = 0;
    double bugged = 10000;
    double margin = 23;

    Position distance{};
    for (const auto& soldier : m_nearby_soldiers) {
        distance = soldier->actualPosition() - actualPosition();
        s = distance.length();
//        if (s > epsilon && s < bugged)
//        {
//            s_force = 100/s/s;
//            x_force -= distance.m_x/s * s_force;
//            y_force -= distance.m_y/s * s_force;
//        }
//        if (s > epsilon && s < bugged) {
//            if (s > margin)   s_force = 200/s;
//            else              s_force = 10000/s;

//            x_force -= distance.m_x/s * s_force;
//            y_force -= distance.m_y/s * s_force;
//        }
        if (s > epsilon && s < bugged) {
            if (s > margin)   s_force = 150/s/s; // 5/s;
            else              s_force = std::min(1000/s/s, 50.); // 100/s/s;
            //s_force = 10000/s/s/s/s;
            x_force -= distance.m_x/s * s_force;
            y_force -= distance.m_y/s * s_force;
        }
    }

    distance = targetPosition() - actualPosition();
    s = distance.length();
    if (s > epsilon && s < bugged)
    {
        s_force = 1*s + 20/s;
        x_force += distance.m_x/s * s_force;
        y_force += distance.m_y/s * s_force;
    }

    // wybierz kierunek ruchu
    Position force{x_force, y_force};

    // wykonaj ruch ze stałą prędkością (kiedyś to będzie siła/przyspieszenie
    speedvector = (speedvector + force*0.001)*0.98;

    // wykonaj ruch ze stałą prędkością (kiedyś to będzie siła/przyspieszenie
    //Position new_position = m_actual_position + speedvector;
    m_actual_position = m_actual_position + speedvector;


    return speedvector;

}
