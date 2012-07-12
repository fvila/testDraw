#include "boundingboxgraphicsitem.h"

#include <QPainter>
#include <QColor>

BoundingBoxGraphicsItem::BoundingBoxGraphicsItem(qreal posx, qreal posy)
{
    bbox.setCoords(0, 0, 0, 0);
    origin.setX(posx);
    origin.setY(posy);
    size.setX(posx);
    size.setY(posy);

    id = "";

//    sel = false;
    QGraphicsItem::setFlags(QGraphicsItem::ItemIsSelectable |
                            QGraphicsItem::ItemIsMovable |
                            QGraphicsItem::ItemIsFocusable);
}

QRectF BoundingBoxGraphicsItem::boundingRect() const
{
    return bbox;
}

void BoundingBoxGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen;
//    if (sel)
//        pen.setColor(QColor("red"));
//    else
        pen.setColor(QColor("black"));

    pen.setWidth(2);

    painter->setPen(pen);


    painter->drawRect(QRectF(origin, size));
    bbox.setCoords(origin.x(), origin.y(), size.x(), size.y());

    if (id != "")
    {
        painter->drawText(bbox.center(), id);
    }
}

void BoundingBoxGraphicsItem::setSize(qreal x, qreal y)
{
    size.setX(x);
    size.setY(y);
}

void BoundingBoxGraphicsItem::setId(QString id)
{
    this->id = id;
}

//bool BoundingBoxGraphicsItem::selected()
//{
//    return sel;
//}

//void BoundingBoxGraphicsItem::setSelected(bool state)
//{
//    sel = state;
//}
