#include "qlegionary.h"


QSvgRenderer* QLegionary::legionaryRenderer {new QSvgRenderer(QLatin1String(":/images/legionary.svg"))};

///
/// \brief QLegionary constructor
///
QLegionary::QLegionary(double init_x, double init_y) : QGraphicsSvgItem() //this?
{

    this->setSharedRenderer(legionaryRenderer);
    this->setPos(init_x, init_y);
}
