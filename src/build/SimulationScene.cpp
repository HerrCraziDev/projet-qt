#include "SimulationScene.hpp"

SimulationScene::SimulationScene(SimulationController &cntr, QObject *parent) : QGraphicsScene(parent), controller(cntr)
{    
    bk_placeholder = new QGraphicsPixmapItem(QPixmap("../../res/textures/bearhunterrussia_logo.png"));
    worldBackground = new QGraphicsRectItem(0,0,ST_TILESIZE, ST_TILESIZE);

    this->addItem(bk_placeholder);
    
    // sim->getCurrentFrame();
    textures[EType::Entity] = QPixmap();
    textures[EType::Animal] = QPixmap("../../res/textures/objects/bear.png");
    textures[EType::Prey] = QPixmap("../../res/textures/objects/bear.png");
    textures[EType::Predator] = QPixmap("../../res/textures/objects/hunter.png");
    textures[EType::Resource] = QPixmap();
    textures[EType::NeutralAsset] = QPixmap("../../res/textures/objects/bear_dead.png");
    textures[EType::EffectiveAsset] = QPixmap();
    textures[EType::DeadPredator] = QPixmap("../../res/textures/objects/hunter_dead.png");
    textures[EType::DeadPrey] = QPixmap("../../res/textures/objects/bear_dead.png");

    /*QGraphicsPixmapItem *pladimir = new QGraphicsPixmapItem(QPixmap("../../res/textures/objects/bear.png"));
    this->addItem(pladimir);
    pladimir->setPos(42,42);*/
}

SimulationScene::~SimulationScene()
{
    controller.stop();
}

void SimulationScene::launch(int ww, int wh, int tickLength, int nbAnimals, float predPrct, uint seed)
{
    std::cout << "[Scene] Launching simulation";
    
    sim = new Simulation(ww, wh, ST_TILESIZE, nbAnimals, predPrct, seed);

    worldBackground->setRect(0, 0, ww * ST_TILESIZE, wh * ST_TILESIZE);
    worldBackground->setBrush(Qt::green);
    this->addItem(worldBackground);

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
    //SimulationFrame frame = controller.getSimulationFrame();
    auto entities = controller.getSimulationFrame().getEntities();

    std::cout << "\r[Scene] Updating " << entities.size() << " entity sprites";

    for(int i = 0 ; i < (int)entities.size() ; ++i)
    {
        entitySprites[i]->setPos( entities[i]->getX(), entities[i]->getY() );
        //entitySprites[i]->setPos(0,0);
        entitySprites[i]->setPixmap( textures[ entities[i]->getType() ] );
        std::cout << "Entity " << i << " : (" << entities[i]->getX() << "," << entities[i]->getY() << "), type : " << entities[i]->getType() << "\n";
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

    for(auto&& sprite : entitySprites)
    {
        this->removeItem(sprite);
    }
}

QGraphicsPixmapItem *SimulationScene::getPlaceholder()
{
    return bk_placeholder;
}