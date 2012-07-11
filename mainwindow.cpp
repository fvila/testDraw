#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "boundingboxgraphicsitem.h"

#include <QLabel>

#include "drawscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionSelect->setChecked(true);

    statusCoords = new QLabel();
    ui->statusBar->addPermanentWidget(statusCoords);

    scene = new DrawScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_activated()
{
    ui->statusBar->showMessage("Open action");
}

void MainWindow::on_actionSave_activated()
{
    ui->statusBar->showMessage("Save action");
}

void MainWindow::on_actionSelect_triggered(bool status)
{
    if (status)
    {
        ui->statusBar->showMessage("Select action activated");
        ui->actionDraw->setChecked(false);
        ui->actionDelete->setChecked(false);

        ui->graphicsView->setMode(DrawView::Select);
    }
    else
    {
        ui->actionSelect->setChecked(true);
    }
}

void MainWindow::on_actionDraw_triggered(bool status)
{
    if (status)
    {
        ui->statusBar->showMessage("Draw action activated");
        ui->actionSelect->setChecked(false);
        ui->actionDelete->setChecked(false);

        ui->graphicsView->setMode(DrawView::Insert);
    }
    else
    {
        ui->actionDraw->setChecked(true);
    }
}

void MainWindow::on_actionDelete_triggered(bool status)
{
    if (status)
    {
        ui->statusBar->showMessage("Delete action activated");
        ui->actionSelect->setChecked(false);
        ui->actionDraw->setChecked(false);
    }
    else
    {
        ui->actionDelete->setChecked(true);
    }
}

void MainWindow::on_graphicsView_scenePositionValueChanged(qreal x, qreal y)
{
    QString msg = QString("X: %1 Y: %2")
            .arg(x).arg(y);

    statusCoords->setText(msg);
}
