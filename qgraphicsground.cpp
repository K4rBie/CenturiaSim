#include "qgraphicsground.h"

QGraphicsGround::QGraphicsGround() : QGraphicsPixmapItem(QPixmap(":/images/ground.png"))
{

}

const Position &QGraphicsGround::mousePosition()
{
    return m_mousePosition;
}
