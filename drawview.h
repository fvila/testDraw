#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QGraphicsView>

class QMouseEvent;
class BoundingBoxGraphicsItem;

class DrawView : public QGraphicsView
{
    Q_OBJECT

public:
    enum Mode { Insert, Select};

    explicit DrawView(QWidget *parent = 0);

signals:
    void scenePositionValueChanged(qreal x, qreal y);

public slots:

    void setMode(Mode m);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Mode m;

    BoundingBoxGraphicsItem *bbox;

    unsigned int id;
};

#endif // DRAWVIEW_H
