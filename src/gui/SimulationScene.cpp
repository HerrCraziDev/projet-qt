#include "SimulationScene.hpp"

SimulationScene::SimulationScene(QObject *parent) : QGraphicsScene(parent)
{
    bk_placeholder = new QGraphicsPixmapItem(QPixmap("../../res/textures/bearhunterrussia_logo.png"));

    this->addItem(bk_placeholder);
}

SimulationScene::~SimulationScene() {}

void SimulationScene::update()
{
    std::cout << "[Scene] Update\n";
}

QGraphicsPixmapItem *SimulationScene::getPlaceholder()
{
    return bk_placeholder;
}