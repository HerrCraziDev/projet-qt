#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("BEAR HUNTER RUSSIA XTREME");


    scene = new SimulationScene();
    ui->g_map->setScene(scene);
    ui->g_map->centerOn(scene->getPlaceholder());
    
    connect(ui->slider_predprct, SIGNAL(valueChanged(int)), this, SLOT(onSetPredatorPercentage(int)));
    connect(ui->slider_preysprct, SIGNAL(valueChanged(int)), this, SLOT(onSetPreyPercentage(int)));
    connect(ui->btn_advancedopt, SIGNAL(clicked(bool)), this, SLOT(onNonImplemented()));
    connect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onNonImplemented()));
    connect(ui->toggle_fs, SIGNAL(stateChanged(int)), this, SLOT(onToggleFullscreen(int)));
}

void MainWindow::onSetPredatorPercentage(int prct)
{
    ui->slider_preysprct->setValue(100 - prct);
}

void MainWindow::onSetPreyPercentage(int prct)
{
    ui->slider_predprct->setValue(100 - prct);
}

void MainWindow::onNonImplemented()
{
    QMessageBox::critical(this, "Error", "The functionnality 'Launch Simulation' havn't been implemented yet.", QMessageBox::Ok);
}

void MainWindow::onToggleFullscreen(int state)
{
    if (state == Qt::Checked) this->showFullScreen();
    else this->showNormal();
}

MainWindow::~MainWindow()
{
    delete ui;
}
