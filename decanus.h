#ifndef DECANUS_H
#define DECANUS_H

#include <vector>
#include <memory>

#include "soldier.h"
#include "legionary.h"
#include "formationenum.h"

struct FormationPosition;

///
/// \brief A commander of contubernium.
///
class Decanus : public Soldier
{
public:
    // nearby_soldiers robi za innych decanusów
    // nearby objects to będzie cała lista wszystkiego w co ma nie walnąć.
    Decanus(std::forward_list<std::shared_ptr<Legionary>> t_subordinates,
            Position t_start_position,
            flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers);
    Decanus(std::forward_list<std::shared_ptr<Legionary>> t_subordinates,
            flist_PhysicalObject_ptr_cstref t_nearby_objects,
            flist_PhysicalObject_ptr_cstref t_nearby_soldiers);

    void formation(const Formation &new_formation);
    const Formation& formation() const;

    void step();


private:
    void giveOrders();
    void sendLineFormationOrders();
    void sendTestudoFormationOrders();
    void sendSquareFormationOrders();
    Decanus(); //should stay without definition
    Position move();
    const FormationPosition* m_available_positions;
    const static FormationPosition square_formation_positions[10];
    const static FormationPosition line_formation_positions[10];
    const static FormationPosition testudo_formation_positions[10];

    std::forward_list<std::shared_ptr<Legionary>> m_subordinates;
    Formation m_formation {Formation(SQUARE)};
};

struct FormationPosition {
    Position offset;
    double rotation;
};

#endif // DECANUS_H
