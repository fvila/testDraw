#include "drawview.h"
#include "boundingboxgraphicsitem.h"

#include <QMouseEvent>

DrawView::DrawView(QWidget *parent) :
    QGraphicsView(parent)
{
    m = Select;
    bbox = 0;

    id = 0;
}

void DrawView::mousePressEvent(QMouseEvent *event)
{
    if (!(event->button() == Qt::LeftButton))
        return;

    QPointF realPos = mapToScene(event->pos());

    switch (m)
    {
    case Select:
        break;
    case Insert:
        bbox = new BoundingBoxGraphicsItem(realPos.x(), realPos.y());
        scene()->addItem(bbox);

        break;
    default:
        break;
    }

    QGraphicsView::mousePressEvent(event);
}

void DrawView::mouseMoveEvent(QMouseEvent *event)
{
    QPointF point = QGraphicsView::mapToScene(event->pos());
    emit scenePositionValueChanged(point.x(), point.y());

    QPointF realPos = mapToScene(event->pos());

    if (event->buttons() & Qt::LeftButton)
    {
        switch (m)
        {
        case Select:
            break;
        case Insert:
            bbox->setSize(realPos.x(), realPos.y());
            scene()->invalidate();
            break;
        default:
            break;
        }
    }

    QGraphicsView::mouseMoveEvent(event);
}

void DrawView::mouseReleaseEvent(QMouseEvent *event)
{
    switch (m)
    {
    case Select:
        break;
    case Insert:
        bbox->setId(QString("%1").arg(id));
        ++id;
        scene()->invalidate();
        break;
    default:
        break;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void DrawView::setMode(Mode m)
{
    this->m = m;
}
