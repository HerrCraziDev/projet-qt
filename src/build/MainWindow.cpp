#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("BEAR HUNTER RUSSIA XTREME");
    ui->pbar_predators->setValue(0);
    ui->pbar_preys->setValue(0);

    scene = new SimulationScene(controller, this);
    ui->g_map->setScene(scene);
    ui->g_map->centerOn(scene->getPlaceholder());
    
    connect(ui->slider_predprct, SIGNAL(valueChanged(int)), this, SLOT(onSetPredatorPercentage(int)));
    connect(ui->slider_preysprct, SIGNAL(valueChanged(int)), this, SLOT(onSetPreyPercentage(int)));
    connect(ui->btn_advancedopt, SIGNAL(clicked(bool)), this, SLOT(onNonImplemented()));
    connect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onLaunchSimulation()));
    connect(ui->toggle_fs, SIGNAL(stateChanged(int)), this, SLOT(onToggleFullscreen(int)));

    gphUpdater = new QTimer(this);
    connect(gphUpdater, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* Slots */

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
    QMessageBox::critical(this, "Error", "This functionnality haven't been implemented yet.", QMessageBox::Ok);
}

void MainWindow::onToggleFullscreen(int state)
{
    if (state == Qt::Checked) this->showFullScreen();
    else this->showNormal();
}

void MainWindow::onLaunchSimulation()
{
    int popnumber = ui->input_popnumber->value();
    int worldWidth = ui->input_wsize_width->value();
    int worldHeight = ui->input_wsize_height->value();
    int predPrct = ui->slider_predprct->value();
    int tickLength = ui->slider_simspeed->value();
    uint seed = ui->input_seed->value();

    ui->pbar_predators->setMaximum(popnumber);

    scene->launch(worldWidth, worldHeight, tickLength, popnumber, predPrct, seed);
    ui->g_map->centerOn(worldWidth*ST_TILESIZE/2, worldHeight*ST_TILESIZE/2);

    gphUpdater->start(1000/ST_FPS);

    toggleLaunchButton();
}

void MainWindow::onTogglePause(bool state)
{
    if (state) controller.pause();
    else controller.resume();
}

void MainWindow::onStopSimulation()
{
    ui->btn_launch->setText("Stopping...");

    gphUpdater->stop();
    scene->stop();

    toggleLaunchButton();
}

void MainWindow::update()
{
    scene->update();
    controller.setTickLength( ui->slider_simspeed->value() );

    ui->pbar_predators->setValue( controller.getSimulation()->countEntities( {EType::Animal} ) );

    if (controller.state() == SimulationState::Stopping)
    {
        onStopSimulation();
    }
}


/* Private Methods */

void MainWindow::toggleLaunchButton()
{
    if (btnLaunch_state)
    {
        ui->btn_launch->setText("Stop Simulation");
        disconnect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onLaunchSimulation()));
        connect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onStopSimulation()));
    } else {
        ui->btn_launch->setText("Launch Simulation");
        disconnect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onStopSimulation()));
        connect(ui->btn_launch, SIGNAL(clicked(bool)), this, SLOT(onLaunchSimulation()));
    }

    btnLaunch_state = !btnLaunch_state;
}
