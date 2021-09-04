#include "qgraphicsformationbutton.h"

QGraphicsFormationButton::QGraphicsFormationButton(Function function, std::string t_icon_path, QObject *parent)
    : QGraphicsSvgItem(this), m_function(function)
{
    m_parent = (MainScene*)parent;
    iconRenderer = new QSvgRenderer(QLatin1String(t_icon_path.c_str()));

    this->setSharedRenderer(iconRenderer);
    this->setPos(0, 0);
    //QGraphicsRectItem{0  , 0, 10, 10},
    //this->setRect(0  , 0, 10, 10);
    //this->setBrush(QBrush{Qt::SolidPattern});

//    switch (m_function) {
//        case(START_SIM): connect(this, mouseReleaseEvent(), ((MainScene*)parent), ((MainScene*)parent)->startSimulation(200)); break;
//        case(STOP_SIM): ((MainScene*)parent)->startSimulation(200); break;
//        case(FORM_SQUARE): ((MainScene*)parent())->changeCenturiaFormation(Formation::SQUARE); break;
//        case(FORM_LINE): ((MainScene*)parent())->changeCenturiaFormation(Formation::LINE); break;
//        case(FORM_TESTUDO): ((MainScene*)parent())->changeCenturiaFormation(Formation::TESTUDO); break;
//    }
}

void QGraphicsFormationButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_function) {
        case(START_SIM): m_parent->startSimulation(100); break;
        case(STOP_SIM): m_parent->stopSimulation(); break;
        case(FORM_SQUARE): m_parent->changeCenturiaFormation(Formation::SQUARE); break;
        case(FORM_LINE): m_parent->changeCenturiaFormation(Formation::LINE); break;
        case(FORM_TESTUDO): m_parent->changeCenturiaFormation(Formation::TESTUDO); break;
    }
}

void QGraphicsFormationButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    switch (m_function) {
//        case(START_SIM): ((MainScene*)parent())->startSimulation(200); break;
//        case(STOP_SIM): ((MainScene*)parent())->startSimulation(200); break;
//        //case(FORM_SQUARE): ((MainScene*)parent())->changeCenturiaFormation(Formation::SQUARE); break;
//        case(FORM_LINE): ((MainScene*)parent())->changeCenturiaFormation(Formation::LINE); break;
//        case(FORM_TESTUDO): ((MainScene*)parent())->changeCenturiaFormation(Formation::TESTUDO); break;
//    }
}

//void QGraphicsFormationButton::mouseReleaseEvent()
//{
//}
