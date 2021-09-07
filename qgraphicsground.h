#ifndef QGRAPHICSGROUND_H
#define QGRAPHICSGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "position.h"

class QGraphicsGround : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QGraphicsGround();
    const Position& mousePosition();

private:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Position m_mousePosition{};

signals:
    void mousePressSignal();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QGRAPHICSGROUND_H
