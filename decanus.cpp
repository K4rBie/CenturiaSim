#include "decanus.h"
#include "iostream"

///
/// \brief Decanus::Decanus
/// \param t_subordinates       Legionaries he commands
/// \param t_start_position     Position on the field he is initially placed
/// \param t_nearby_objects     Static objects (list of)
/// \param t_nearby_soldiers    All soldiers really
///
Decanus::Decanus(std::forward_list<std::shared_ptr<Legionary> > t_subordinates,
                 Position t_start_position,
                 flist_PhysicalObject_ptr_cstref t_nearby_objects,
                 flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
                 : Soldier(t_start_position, 10.f, t_nearby_objects, t_nearby_soldiers),
                 m_subordinates(t_subordinates)
{

}

///
/// \brief Decanus::Decanus
/// \param t_subordinates       Legionaries he commands
/// \param t_nearby_objects     Static objects (list of)
/// \param t_nearby_soldiers    All soldiers really
///
Decanus::Decanus(std::forward_list<std::shared_ptr<Legionary> > t_subordinates,
                 flist_PhysicalObject_ptr_cstref t_nearby_objects,
                 flist_PhysicalObject_ptr_cstref t_nearby_soldiers)
                 : Soldier(Position{}, 10.f, t_nearby_objects, t_nearby_soldiers),
                 m_subordinates(t_subordinates)
{

}

///
/// \brief Make a simulation step: give orders and move to the next position.
///
void Decanus::step()
{
    giveOrders();
    move();
}

///
/// \brief Legionary::move
/// \return a new position for decanus
///
Position Decanus::move()
{
    // policz wszystkie siły
    double x_force = 0;
    double y_force = 0;

    double s = 0;
    double s_force = 0;
    double margin = 25;
    double epsilon = 0.1;
    double bugged = 10000;

    Position distance{};

    for (const auto& soldier : m_nearby_soldiers) {
        bool isOwn = false;
        for (const auto& sub : m_subordinates) {
            if (sub == soldier) {
                isOwn = true;
                break;
            }
        }
        //if (isOwn) continue;


        distance = soldier->actualPosition() - actualPosition();
        s = distance.length();
        if (s > epsilon && s < bugged) {
            if (s > margin)   s_force = 4/s; // 5/s;
            else              s_force = std::min(800/s/s, 60.); // 100/s/s;
            //s_force = 10000/s/s/s/s;

            if (isOwn && s > margin) {
                x_force += distance.m_x/s * s_force;
                y_force += distance.m_y/s * s_force;
            }
            else {
                x_force -= distance.m_x/s * s_force;
                y_force -= distance.m_y/s * s_force;
            }

        }
    }
    // wnioski
    // siła jaką decanus z ekipą generuje będąc w środku pola musi być większa od siły, którą to pole przyciąga innego decanusa
    // punkty równowagi musza być ustawione teak, że rogue decanus gdzieś w środku wypchnie mimo to innego decanusa do innego punktu


    for (int i = 0; i < 10; ++i) {

        distance = m_available_positions[i].offset + formationCenter - actualPosition();
        s = distance.length();

        if (s > epsilon && s < bugged){
            if (s > 6){
                s_force = std::min(0.0004*s + 9000/s/s, 25.);
            } else {
                s_force = 5*s;
            }

            x_force += distance.m_x/s * s_force;
            y_force += distance.m_y/s * s_force;
        }
    }

    // wybierz kierunek ruchu
    Position force{x_force, y_force};

    // wykonaj ruch ze stałą prędkością (kiedyś to będzie siła/przyspieszenie
    speedvector = (speedvector + force*0.1)*0.98;

    // wykonaj ruch ze stałą prędkością (kiedyś to będzie siła/przyspieszenie
    //Position new_position = m_actual_position + speedvector;
    m_actual_position = m_actual_position + speedvector;


    return speedvector;
}

///rect
/// \brief Set new formation for Decanus.
/// \param new_formation New formation.
///
void Decanus::formation(const enum Formation& new_formation)
{
    m_formation = new_formation;
}

///
/// \brief Get actual formation that Decanus tries to achieve.
/// \return Formation
///
const Formation &Decanus::formation() const
{
    return m_formation;
}

void Decanus::giveOrders(){

    switch (m_formation) {
        case LINE:
            m_available_positions = line_formation_positions;
            sendLineFormationOrders();
        break;
        case SQUARE:
            m_available_positions = square_formation_positions;
            sendSquareFormationOrders();
        break;
        case TESTUDO:
            m_available_positions = testudo_formation_positions;
            sendTestudoFormationOrders();
        break;
    }
}

void Decanus::sendLineFormationOrders(){
    Position base = m_actual_position;
    double x_offset = 40;
    //double y_offset = 30;

    Position new_target_position{};
    unsigned long n = 0;

    for (const auto& subordinate : m_subordinates) {
        n++;
        new_target_position = base + Position{n * x_offset, 0};
        subordinate->targetPosition(new_target_position);
    }
}

void Decanus::sendTestudoFormationOrders(){
    double x_offset = 50;
    double y_offset = 50;

    Position base_offset = Position(x_offset, y_offset);
    Position base = m_actual_position - base_offset;

    //Position new_target_position;
    Position offset{};
    long n = -1;

    for (const auto& subordinate : m_subordinates) {
        n++;

        if (n < 4) {
            offset = Position{n * x_offset, 0};
        }
        else {
            if (n == 5) {
                n++;
            }
            offset = Position{(n - 4) * x_offset, y_offset};
        }


        subordinate->targetPosition(base + offset);
    }
}

void Decanus::sendSquareFormationOrders(){
    double x_offset = 40;
    double y_offset = 40;

    Position base_offset = Position(x_offset, y_offset);
    Position base = m_actual_position - base_offset;

    //Position new_target_position;
    Position offset{};
    long n = -1;

    for (const auto& subordinate : m_subordinates) {
        n++;

        if (n < 4) {
            offset = Position{n * x_offset, 0};
        }
        else {
            if (n == 5) {
                n++;
            }
            offset = Position{(n - 4) * x_offset, y_offset};
        }


        subordinate->targetPosition(base + offset);
    }
}

//const FormationPosition Decanus::square_formation_positions[10] = {
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180},
//    FormationPosition{Position  {50   , 50}, 180}
//};

const FormationPosition Decanus::square_formation_positions[10] = {
    FormationPosition{Position  {-160  , -120}, 180},
    FormationPosition{Position  {  0   , -120}, 180},
    FormationPosition{Position  { 160  , -120}, 180},
    FormationPosition{Position  {-160 , -40  },  90},
    FormationPosition{Position  { 160 , -40  }, 270},
    FormationPosition{Position  {-160 ,  40  },  90},
    FormationPosition{Position  { 160 ,  40  }, 270},
    FormationPosition{Position  {-160   ,  120},   0},
    FormationPosition{Position  {  0   ,  120},   0},
    FormationPosition{Position  { 160   ,  120},   0}
};

//const FormationPosition Decanus::line_formation_positions[10] = {
//    FormationPosition{Position  { 25, -200}, 180},
//    FormationPosition{Position  { 25, -100}, 180},
//    FormationPosition{Position  { 25,    0}, 180},
//    FormationPosition{Position  { 25,  100}, 180},
//    FormationPosition{Position  { 25,  200}, 180},
//    FormationPosition{Position  {-25, -200}, 180},
//    FormationPosition{Position  {-25, -100}, 180},
//    FormationPosition{Position  {-25,    0}, 180},
//    FormationPosition{Position  {-25,  100}, 180},
//    FormationPosition{Position  {-25,  200}, 180}
//};

const FormationPosition Decanus::line_formation_positions[10] = {
    FormationPosition{Position  { 0, -200}, 180},
    FormationPosition{Position  { 0, -100}, 180},
    FormationPosition{Position  { 0,    0}, 180},
    FormationPosition{Position  { 0,  100}, 180},
    FormationPosition{Position  { 0,  200}, 180},
    FormationPosition{Position  { 0, -250}, 180},
    FormationPosition{Position  { 0, -150}, 180},
    FormationPosition{Position  { 0,  -50}, 180},
    FormationPosition{Position  { 0,   50}, 180},
    FormationPosition{Position  { 0,  150}, 180}
};

const FormationPosition Decanus::testudo_formation_positions[10] = {
    FormationPosition{Position{-200, -150}, 180},
    FormationPosition{Position{ 0 , -150}, 180},
    FormationPosition{Position{ 200, -150}, 180},
    FormationPosition{Position{-200, -50},  90},
    FormationPosition{Position{ 200, -50}, 270},
    FormationPosition{Position{-200,  50},  90},
    FormationPosition{Position{ 200,  50}, 270},
    FormationPosition{Position{-200,  150},   0},
    FormationPosition{Position{ 0 ,  150},   0},
    FormationPosition{Position{ 200,  150},   0}
};
