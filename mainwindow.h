#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class QLabel;
class DrawScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void on_actionOpen_activated();
    void on_actionSave_activated();

    void on_actionSelect_triggered(bool);
    void on_actionDraw_triggered(bool);
    void on_actionDelete_triggered(bool);

    void on_graphicsView_scenePositionValueChanged(qreal, qreal);

private:
    QLabel *statusCoords;

    DrawScene *scene;
};

#endif // MAINWINDOW_H
