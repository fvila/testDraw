#ifndef BOUNDINGBOXGRAPHICSITEM_H
#define BOUNDINGBOXGRAPHICSITEM_H

#include <QGraphicsItem>

class BoundingBoxGraphicsItem : public QGraphicsItem
{
public:
    BoundingBoxGraphicsItem(qreal posx = 0, qreal posy = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setSize(qreal x, qreal y);

    void setId (QString);

//    void setSelected(bool);
//    bool selected();

private:
    QRectF bbox;
    QPointF origin, size;

    QString id;

 //   bool sel;
};

#endif // BOUNDINGBOXGRAPHICSITEM_H
