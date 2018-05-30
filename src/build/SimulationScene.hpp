#ifndef SIMULATION_SCENE
#define SIMULATION_SCENE

#include <iostream>
#include <vector>
#include <map>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtGui/QPixmap>

#include "SimulationController.hpp"
#include "settings.hpp"



class SimulationScene : public QGraphicsScene
{
    Q_OBJECT

public:
  SimulationScene(SimulationController &cntr, QObject *parent = nullptr);
  ~SimulationScene();

  QGraphicsPixmapItem *getPlaceholder();
  
  void launch(int ww, int wh, int tickLength, int nbAnimals, float predPrct, uint seed=42);

public slots:
    void pause();
    void resume();
    void update();
    void stop();

private:
    std::vector<QGraphicsPixmapItem*> entitySprites;
    std::map<EType, QPixmap> textures;

    QGraphicsPixmapItem *bk_placeholder;
    QGraphicsRectItem *worldBackground;

    SimulationController &controller;
    Simulation *sim;
};

#endif // SIMULATION_SCENE
