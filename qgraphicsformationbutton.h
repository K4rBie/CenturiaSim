#ifndef QGRAPHICSFORMATIONBUTTON_H
#define QGRAPHICSFORMATIONBUTTON_H

#include <QObject>
#include <qgraphicsitem.h>

#include "simulation.h"
#include "mainscene.h"
#include "functionenum.h"

class MainScene;

///
/// \brief Buttons for scene ui
///
class QGraphicsFormationButton : public QGraphicsSvgItem
{
    Q_OBJECT
public:
    explicit QGraphicsFormationButton(Function function, std::string t_icon_path, QObject *parent = nullptr);



private:
    Function m_function;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent();
    QSvgRenderer* iconRenderer;
    MainScene* m_parent;
    QGraphicsView* m_viewport;
    QLatin1String m_icon_path{};


};

#endif // QGRAPHICSFORMATIONBUTTON_H
