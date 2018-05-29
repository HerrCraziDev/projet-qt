#ifndef SIMULATION_SCENE
#define SIMULATION_SCENE

#include <iostream>
#include <vector>
#include <map>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtGui/QPixmap>

#include "../simulation/SimulationController.hpp"



class SimulationScene : public QGraphicsScene
{
    Q_OBJECT

public:
  SimulationScene(QObject *parent);
  ~SimulationScene();

  QGraphicsPixmapItem *getPlaceholder();
  
  void launch(int ww, int wh, int tickLength, int nbAnimals, float preyPrct);

public slots:
    void pause();
    void resume();
    void update();
    void stop();

private:
    std::vector<QGraphicsPixmapItem> entitySprites;
    std::map<EType, QPixmap> textures;

    QGraphicsPixmapItem *bk_placeholder;
};

#endif // SIMULATION_SCENE
