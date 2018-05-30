#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

#include <iostream>

#include "SimulationScene.hpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    SimulationController &getController();

public slots:
    void onSetPredatorPercentage(int prct);
    void onSetPreyPercentage(int prct);
    void onNonImplemented();
    void onToggleFullscreen(int state);
    void onLaunchSimulation();
    void onTogglePause(bool toggle);
    void onStopSimulation();

    void update();


private:
    void toggleLaunchButton();

    Ui::MainWindow *ui;
    SimulationScene *scene;
    QTimer *gphUpdater;

    SimulationController controller;

    bool btnLaunch_state = true;
};

#endif // MAINWINDOW_HPP
