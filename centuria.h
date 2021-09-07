#ifndef CENTURIA_H
#define CENTURIA_H

#include <vector>
#include <memory>
#include <algorithm>

#include "contubernium.h"
#include "formationenum.h"

/**
 * @brief Part of simulation dealing with commanding and simulation troops.
 */

class Centuria
{
public:
    Centuria(flist_PhysicalObject_ptr_cstref t_inanimate_objects,
             flist_Soldier_ptr_cstref t_soldiers);

    void step();

    const Formation& formation() const;
    void formation(const Formation& new_formation);

    const std::vector<Contubernium>& contubernia() const;

    const Position& center();
    void center(const Position& requested_center);

private:
    void sendOrdersDown();
    enum Formation m_formation;
    Position m_center{};

    flist_Soldier_ptr_cstref m_soldiers;
    flist_PhysicalObject_ptr_cstref m_inanimate_objects;
    std::vector<Contubernium> m_contubernia{};

};

#endif // CENTURIA_H
