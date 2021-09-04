#include "position.h"

///
/// \brief substract positions
/// \param b to be substracted
/// \return
///
Position Position::operator-(const Position &b) const
{
    Position c;

    c.m_x = this->m_x - b.m_x;
    c.m_y = this->m_y - b.m_y;

    return c;
}

///
/// \brief Add positions
/// \param b to be added
/// \return
///
Position Position::operator+(const Position &b) const
{
    Position c;

    c.m_x = this->m_x + b.m_x;
    c.m_y = this->m_y + b.m_y;

    return c;
}

///
/// \brief Check if equal
/// \param b is it equal?
/// \return
///
bool Position::operator==(const Position &b) const
{
    return (std::abs(m_x - b.m_x) < epsilon && std::abs(m_y - b.m_y) < epsilon) ? true : false;
}

///
/// \brief Normalize position
/// \param vector
/// \return
///
Position Position::normalize(Position &vector)
{
    Position unit {0,0};
    double length = vector.length();

    if (length == 0) return unit; // tymczasowo bo dizelenie przez zero, potem jeszcze ruch będzie w złym kierunku

    unit.m_x = vector.m_x / length;
    unit.m_y = vector.m_y / length;

    return unit;
}

///
/// \brief Compute length or distance from zero point.
/// \return length
///
double Position::length()
{
    return sqrt(this->m_x*this->m_x + this->m_y*this->m_y);
}
