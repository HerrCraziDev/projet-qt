#ifndef SIMULATION_SCENE
#define SIMULATION_SCENE

#include <iostream>
#include <vector>
#include <map>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QtGui/QPixmap>
#include <QWidget>

#include "../simulation/SimulationController.hpp"


class SimulationScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SimulationScene(QObject *parent = 0);
    ~SimulationScene();

    QGraphicsPixmapItem *getPlaceholder();

public slots:
    void update();

private:
    std::vector<QGraphicsPixmapItem> entitySprites;
    std::map<EType, QPixmap> textures;

    QGraphicsPixmapItem *bk_placeholder;

};

#endif // SIMULATION_SCENE
