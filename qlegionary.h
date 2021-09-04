#ifndef QLEGIONARY_H
#define QLEGIONARY_H

#include <QObject>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>


class QLegionary : public QGraphicsSvgItem
{
    Q_OBJECT
public:
    explicit QLegionary(double init_x, double init_y);

private:
    static QSvgRenderer* legionaryRenderer;

signals:

};

#endif // QLEGIONARY_H
