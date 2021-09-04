#ifndef POSITION_H
#define POSITION_H

#include <cmath>


class Position
{
public:
    Position() : m_x(0), m_y(0){};
    Position(double t_x, double t_y): m_x(t_x), m_y(t_y){};
    Position operator-(const Position& b) const;
    Position operator+(const Position& b) const;
    Position operator/(int b) const;
    Position operator*(const Position& b) const;
    bool operator==(const Position& b) const;

    template<typename T>
    Position operator*(const T& type_value)
    {
        Position c;

        c.m_x = this->m_x * type_value;
        c.m_y = this->m_y * type_value;

        return c;
    }

    static Position normalize(Position& vector);

    double length();

    double m_x;
    double m_y;

private:
    double epsilon {0.001};
};

#endif // POSITION_H
