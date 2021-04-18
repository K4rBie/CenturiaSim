#include "position.h"

Position Position::operator-(const Position &b) const
{
    Position c;

    c.m_x = this->m_x - b.m_x;
    c.m_y = this->m_y - b.m_y;

    return c;
}

Position Position::operator+(const Position &b) const
{
    Position c;

    c.m_x = this->m_x + b.m_x;
    c.m_y = this->m_y + b.m_y;

    return c;
}

bool Position::operator==(const Position &b) const
{
    return (std::abs(m_x - b.m_x) < epsilon && std::abs(m_y - b.m_y) < epsilon) ? true : false;
}

Position Position::getUnitVector(Position &vector)
{
    Position unit {0,0};
    double length = vector.length();

    if (length == 0) return unit; // tymczasowo bo dizelenie przez zero, potem jeszcze ruch będzie w złym kierunku

    unit.m_x = vector.m_x / length;
    unit.m_y = vector.m_y / length;

    return unit;
}

double Position::length()
{
    return sqrt(this->m_x*this->m_x + this->m_y*this->m_y);
}
