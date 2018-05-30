#include "SimulationScene.hpp"

SimulationScene::SimulationScene(SimulationController &cntr, QObject *parent) : QGraphicsScene(parent), controller(cntr)
{    
    //Some fancy logo to dispay here
    bk_placeholder = new QGraphicsPixmapItem(QPixmap("../../res/textures/bearhunterrussia_logo.png"));
    this->addItem(bk_placeholder);
    
    //Loading the textures resources
    textures[EType::Entity] = QPixmap();
    textures[EType::Animal] = QPixmap("../../res/textures/objects/bear.png");
    textures[EType::Prey] = QPixmap("../../res/textures/objects/bear.png");
    textures[EType::Predator] = QPixmap("../../res/textures/objects/hunter.png");
    textures[EType::Resource] = QPixmap();
    textures[EType::NeutralAsset] = QPixmap("../../res/textures/objects/bear_dead.png");
    textures[EType::EffectiveAsset] = QPixmap();
    textures[EType::DeadPredator] = QPixmap("../../res/textures/objects/hunter_dead.png");
    textures[EType::DeadPrey] = QPixmap("../../res/textures/objects/bear_dead.png");

    grass = QPixmap("../../res/textures/ground/grass.png");

}

SimulationScene::~SimulationScene()
{
    controller.stop();
}

void SimulationScene::launch(int ww, int wh, int tickLength, int nbAnimals, float predPrct, uint seed)
{
    std::cout << "[Scene] Launching simulation";
    
    sim = new Simulation(ww, wh, ST_TILESIZE, nbAnimals, predPrct, seed);

    /* Creating ground tiles */

    for (int i = 0; i < ww; i++)
    {
        for (int j = 0; j < wh; j++)
        {
            QGraphicsPixmapItem *tile = new QGraphicsPixmapItem(grass);
            tile->setPos(i * ST_TILESIZE, j * ST_TILESIZE);
            this->addItem(tile);

            mapTiles.push_back(tile);
        }
    }

    /* Creating sprites */
    //worldBackground->setRect(0, 0, ww * ST_TILESIZE, wh * ST_TILESIZE);  worldBackground->setBrush(Qt::green);
    //this->addItem(worldBackground);

    std::vector<std::shared_ptr<Entity>> entities = sim->getEntities();
    
    for(auto&& entity : entities)
    {
        QGraphicsPixmapItem *sprite = new QGraphicsPixmapItem( textures[entity->getType()] );
        entitySprites.push_back(sprite);
        this->addItem(sprite);
    }
    

    controller.attach(sim);
    controller.setTickLength(tickLength);
    controller.launch();
}

void SimulationScene::update()
{
    //Getting the entities from the simulation
    auto entities = controller.getSimulationFrame().getEntities();

    //std::cout << "\r[Scene] Updating " << entities.size() << " entity sprites";

    //Update entity positions and textures
    for(int i = 0 ; i < (int)entities.size() ; ++i)
    {
        entitySprites[i]->setPos( entities[i]->getX(), entities[i]->getY() );

        if (entities[i]->getType() == EType::Predator || entities[i]->getType() == EType::Prey || entities[i]->getType() == EType::Animal)
        {
            entitySprites[i]->setZValue(9999);
        }
        entitySprites[i]->setPixmap( textures[ entities[i]->getType() ] );
    }
}

void SimulationScene::resume()
{

}

void SimulationScene::pause()
{

}

void SimulationScene::stop()
{
    controller.stop();
    this->removeItem(worldBackground);

    //Delete the sprites...
    for(QGraphicsPixmapItem* sprite : entitySprites)
    {
        this->removeItem(sprite);
    }
    entitySprites.clear();

    //...and the ground tiles as well
    for (QGraphicsPixmapItem *tile : mapTiles)
    {
        this->removeItem(tile);
    }
    mapTiles.clear();
}

QGraphicsPixmapItem *SimulationScene::getPlaceholder()
{
    return bk_placeholder;
}