#include "SimulationScene.hpp"

SimulationScene::SimulationScene(QObject *parent) : QGraphicsScene(parent)
{    
    bk_placeholder = new QGraphicsPixmapItem(QPixmap("../../res/textures/bearhunterrussia_logo.png"));

    this->addItem(bk_placeholder);
}

SimulationScene::~SimulationScene() {}

void SimulationScene::launch(int ww, int wh, int tickLength, int nbAnimals, float preyPrct)
{
    std::cout << "[Scene] Launching simulation";
}

void SimulationScene::update()
{
    std::cout << "[Scene] Update\n";
}

void SimulationScene::resume()
{

}

void SimulationScene::pause()
{

}

void SimulationScene::stop()
{
    
}

QGraphicsPixmapItem *SimulationScene::getPlaceholder()
{
    return bk_placeholder;
}