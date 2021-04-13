#include "decanus.h"

void Decanus::Step()
{
    giveOrders();
    move();
}

void Decanus::formation(const enum Formation& newFormation)
{
    m_formation = newFormation;
}

const Formation &Decanus::formation() const
{
    return m_formation;
}

void Decanus::giveOrders(){

    switch (m_formation) {
        case Line:
            sendLineFormationOrders();
        break;
        case Square:
            sendSquareFormationOrders();
        break;
        case Testudo:
            sendTestudoFormationOrders();
        break;
    }
}

void Decanus::sendLineFormationOrders(){
    Position base = m_actual_position;
    double x_offset = 40;
    //double y_offset = 30;

    Position new_target_position;
    unsigned long n;

    for (unsigned long i = 0; i < m_subordinates.size(); i++) {
        n = i + 1;
        new_target_position = base + Position{n * x_offset, 0};
        m_subordinates.at(i)->targetPosition(new_target_position);
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

    for (unsigned long i = 0; i < m_subordinates.size(); i++) {
        n++;

        if (i < 3) {
            offset = Position{n * x_offset, 0};
        } else {
            if (n == 5) {
                n++;
            }
            offset = Position{(n - 4) * x_offset, y_offset};
        }


        m_subordinates.at(i)->targetPosition(base + offset);
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

    for (unsigned long i = 0; i < m_subordinates.size(); i++) {
        n++;

        if (i < 3) {
            offset = Position{n * x_offset, 0};
        } else {
            if (n == 5) {
                n++;
            }
            offset = Position{(n - 4) * x_offset, y_offset};
        }


        m_subordinates.at(i)->targetPosition(base + offset);
    }
}
