#include "soldier.h"

///
/// \brief Number of Soldier objects created.
///
int Soldier::count = 0;
Position Soldier::formationCenter{0,0};

///
/// \brief Soldier::Soldier
/// \param t_start_position            Position on the field legionary is initially placed
/// \param t_radius                    Sheer size of that chungus
/// \param t_nearby_objects            Static objects (list of)
/// \param t_nearby_soldiers           All soldiers really
///
Soldier::Soldier(Position t_start_position, double t_radius, flist_PhysicalObject_ptr_cstref t_nearby_objects, flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
                : PhysicalObject(t_start_position, t_radius),
                m_nearby_objects(t_nearby_objects),
                m_nearby_soldiers(t_nearby_soldiers)
{
    double x_pos = (count % 10)*m_radius*4;
    double y_pos = std::ceil(count/10)*m_radius*4;
    m_actual_position = Position{x_pos, y_pos};
    count++;
}


///
/// \brief Soldier::Soldier
/// \param t_nearby_objects         Static objects (list of)
/// \param t_nearby_soldiers        All soldiers really
///
Soldier::Soldier(flist_PhysicalObject_ptr_cstref t_nearby_objects, flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
    : PhysicalObject(Position{}, 10.f),
    m_nearby_objects(t_nearby_objects),
    m_nearby_soldiers(t_nearby_soldiers)
{
    count++;
    double x_pos = (count % 10)*m_radius*2;
    double y_pos = std::ceil(count/10)*m_radius*2;
    m_actual_position = Position{x_pos, y_pos};

};


///
/// \brief target Position getter
/// \return gets target Position
///
const Position &Soldier::targetPosition()
{
    return m_target_position;
}

///
/// \brief Target Position setter.
/// \param new_target                 new target Position
///
void Soldier::targetPosition(const Position &new_target)
{
    // widzę to tak:
    // legionista sam sobie nie wybiera docelowej pozycji, robi to za niego dowódca.
    // legionista tylko czyta tę pozycję i się nią "inspiruje" tzn w funkcji move – może powinienem
    // nazwać ją movement_action? – dzieje się wiele rzeczy, które zakłócają ten cel

    m_target_position = new_target;
    // kiedyśtam dodam tutaj większą logikę przesuwania targetu aż coś znajdzie dla siebie
}

///
/// \brief Soldier simulation step.
///
void Soldier::step()
{
    move();
}

Position Soldier::move()
{
    // nie rusza dalej, gdy znajdzie się za blisko jakiegoś obiektu. Powinien to samo robić dla żołnierzy,
    // a nawet najlepiej, jakby to była jedna wspólny wektor
    Position direction = m_target_position - m_actual_position;

    Position new_position;

    if (direction.length() <= speed) {
        new_position = m_actual_position + direction;
    } else {
        Position next_step = Position::normalize(direction) * speed;
        new_position = m_actual_position + next_step;
    }



//    if (isValidPosition(new_position))
//    {
//        return new_position;
//    }
//    else
//    {
//        return m_actual_position;
//    }

    return isValidPosition(new_position) ? new_position : m_actual_position;

}

bool Soldier::isValidPosition(const Position& position) {
    for(const auto& obj_ptr : m_nearby_objects){
        // spr czy wchodzi na inny obiekt, jak nie, to wszystko spoko i przepuszczaj
        Position difference = obj_ptr->actualPosition() - position;
        double distance = difference.length();

        double minimal_distance = obj_ptr->radius() + this->radius();

        // zatrzymaj się i czekaj
        if (distance < minimal_distance) {
            return false;
        }
    }

//    for(auto& obj_ptr : m_nearby_soldiers){
//        // spr czy wchodzi na inny obiekt, jak nie, to wszystko spoko i przepuszczaj
//        Position difference = obj_ptr->actualPosition() - position;
//        double distance = difference.length();

//        double minimal_distance = obj_ptr->radius() + this->radius();

//        // zatrzymaj się i czekaj
//        if (distance < minimal_distance) {
//            return false;
//        }
//    }

    return true;
}

bool Soldier::isValidPosition(const Position& position, flist_PhysicalObject_ptr_cstref objects) {
    for(auto& obj_ptr : objects){
        // spr czy wchodzi na inny obiekt, jak nie, to wszystko spoko i przepuszczaj
        Position difference = obj_ptr->actualPosition() - position;
        double distance = difference.length();

        double minimal_distance = obj_ptr->radius() + this->radius();

        // zatrzymaj się i czekaj
        if (distance < minimal_distance) {
            return false;
        }
    }

    return true;
}

Position Soldier::hateOthers(const Soldier &soldier, double hateFromDistance, double hateUpClose)
{
    Position distance = soldier.actualPosition() - actualPosition();
    double s = distance.length();
//    if (s > epsilon && s < bugged) {
//        if (s > margin)   s_force = 1000/s;
//        else              s_force = 50000/s;

//        x_force -= distance.m_x/s * s_force;
//        y_force -= distance.m_y/s * s_force;
//    }
}

