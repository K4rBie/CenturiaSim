#include "decanus.h"

///
/// \brief Make a next step of simulation.
///
void Decanus::step()
{
    giveOrders();
    move();
}

///
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
            sendLineFormationOrders();
        break;
        case SQUARE:
            sendSquareFormationOrders();
        break;
        case TESTUDO:
            sendTestudoFormationOrders();
        break;
    }
}

void Decanus::sendLineFormationOrders(){
    Position base = m_actual_position;
    double x_offset = 40;
    //double y_offset = 30;

    Position new_target_position;
    unsigned long n = 0;

    for (const auto& subordinate : m_subordinates) {
        n++;
        new_target_position = base + Position{n * x_offset, 0};
        subordinate->targetPosition(new_target_position);
    }
}

void Decanus::sendTestudoFormationOrders(){
    double x_offset = 30;
    double y_offset = 30;

    Position base_offset = Position(-x_offset, -y_offset);
    Position base = m_actual_position - base_offset;

    //Position new_target_position;
    Position offset;
    unsigned long n = -1;


    for (const auto& subordinate : m_subordinates) {
        n++;

        if (n < 3) {
            offset = Position{n * x_offset, 0};
        } else {
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

    Position base_offset = Position(-x_offset, -y_offset);
    Position base = m_actual_position - base_offset;

    //Position new_target_position;
    Position offset;
    unsigned long n = -1;

    for (const auto& subordinate : m_subordinates) {
        n++;

        if (n < 3) {
            offset = Position{n * x_offset, 0};
        } else {
            if (n == 5) {
                n++;
            }
            offset = Position{(n - 4) * x_offset, y_offset};
        }


        subordinate->targetPosition(base + offset);
    }
}
