#include "soldier.h"

Position Soldier::targetPosition()
{

}

void Soldier::targetPosition(const Position &new_target)
{
    // widzę to tak:
    // legionista sam sobie nie wybiera docelowej pozycji, robi to za niego dowódca.
    // legionista tylko czyta tę pozycję i się nią "inspiruje" tzn w funkcji move – może powinienem
    // nazwać ją movement_action? – dzieje się wiele rzeczy, które zakłócają ten cel
    // na razie nie będę bawił się w żadne path findingi. Robią linię prostą, a jak nie to się zatrzymują.

    // dodam tylko że jednak warto od razu zmieniać ten target position w osiągalny.
    // obiekty statyczne się nie ruszają, więc można je przeanalizować tylko raz, czyli tutaj.
    // jeśli target position nachodzi na obiekt, to przesuń target position na granicę obiektu.

    if (new_target == m_target_position)
    m_target_position = isValidPosition(new_target, m_nearby_objects) ? new_target : m_target_position;
    // kiedyśtam dodam tutaj większą logikę przesuwania targetu aż coś znajdzie dla siebie
}

void Soldier::Step()
{
    move();
}

Position Soldier::move()
{
    // nie rusza dalej, gdy znajdzie się za blisko jakiegoś obiektu. Powinien to samo robić dla żołnierzy,
    // a nawet najlepiej, jakby to była jedna wspólny wektor
    Position direction = m_target_position - m_actual_position;
    Position next_step = Position::getUnitVector(direction) * speed;
    Position new_position = m_actual_position + next_step;

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
    for(auto& obj_ptr : m_nearby_objects){
        // spr czy wchodzi na inny obiekt, jak nie, to wszystko spoko i przepuszczaj
        Position difference = obj_ptr->actualPosition() - position;
        double distance = difference.length();

        double minimal_distance = obj_ptr->radius() + this->radius();

        // zatrzymaj się i czekaj
        if (distance < minimal_distance) {
            return false;
        }
    }

    for(auto& obj_ptr : m_nearby_soldiers){
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

bool Soldier::isValidPosition(const Position& position, vec_PhysicalObject_shptr_cstref objects) {
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

