#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
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
    
    //SimulationController &getController();

public slots:
    void onSetPredatorPercentage(int prct);
    void onSetPreyPercentage(int prct);
    void onNonImplemented();
    void onToggleFullscreen(int state);
    void onLaunchSimulation();
    void onTogglePause(bool toggle);
    void onStopSimulation();



private:
    Ui::MainWindow *ui;
    SimulationScene *scene;

    SimulationController controller;
};

#endif // MAINWINDOW_HPP
