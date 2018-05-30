#include "Simulation.hpp"

Simulation::Simulation() {}

Simulation::Simulation(int worldWidth, int worldHeight, int tileSize, int nbAnimals, float predatorsPrct, uint seed) :
    _width(worldWidth),
    _height(worldHeight),
    _tileSize(tileSize)
{
    //predatorsPrct *= 100;

    utl::rand randX(0, (worldWidth * tileSize) - tileSize);
    utl::rand randY(0, (worldHeight * tileSize) - tileSize);
    utl::rand randType(0, 100);

    randX.seed(seed); randY.seed(seed); randType.seed(seed);

    for(int i = 0; i < nbAnimals; i++)
    {
        //createEntity(EType::Animal, randX(), randY(), "Peau de l'ours (avec ours)");
        std::cout << randType() << "/" << predatorsPrct << "\n";
        if (randType() > predatorsPrct)
        {
            createEntity(EType::Prey, randX(), randY(), "Peau de l'ours (avec ours)");
        } else {
            createEntity(EType::Predator, randX(), randY(), "Camarade Pladimir Pladimirovich Voutine");
        }
    }

    
    for(auto&& entity : _entities)
    {
        std::cout << "Entity " << entity->getName() << " is " << entity->getType() << "\n";
    }
    
    
}

Simulation::~Simulation() {}


bool Simulation::createEntity(EType type, int posx, int posy, std::string name)
{
    
    switch (type)
    {
        //case EType::Predator :
        //case EType::Prey :
        //                std::cerr << "[Simulation] in 'Simulation::createEntity(EType type, int posx, int posy, std::string name)\n\t 'EType type' (" << type << ") : Entity type not implemented. A generic Animal have been created instead.\n";
        case EType::Animal :
        {
            Animal *newAnimal = new Animal(this, posx, posy, name);
            _entities.push_back(std::make_shared<Animal>(*newAnimal));
            break;
        }

        case EType::Resource:
        case EType::NeutralAsset :
        case EType::EffectiveAsset :
            std::cerr << "[Simulation] in 'Simulation::createEntity(EType type, int posx, int posy, std::string name)\n\t 'EType type' (" << type << ") : Entity type not implemented. A generic Entity have been created instead.\n";
        case EType::Entity :
        {
            Entity *newEntity = new Entity(this, EType::Entity, posx, posy, name);
            _entities.push_back(std::make_shared<Entity>(*newEntity));
            break;
        }
        
        case EType::Predator :
        {
            Predator *newPredator = new Predator(this, posx, posy, ST_PREDATORATK, ST_PREDATORDEF, name);
            _entities.push_back(std::make_shared<Predator>(*newPredator));
            break;
        }

        case EType::Prey :
        {
            Prey *newPrey = new Prey(this, posx, posy, ST_PREYDEF, name);
            _entities.push_back(std::make_shared<Prey>(*newPrey));
            break;
        }
        /*
        case EType::Resource :
            Resource *newResource = new Resource(MagicThings things);
            _entities.push_back(std::make_shared<Resource>(newResource));
            break;

        case EType::NeutralAsset :
            NeutralAsset *newNeutralAsset = new NeutralAsset(MagicThings things);
            _entities.push_back(std::make_shared<NeutralAsset>(newNeutralAsset));
            break;
        
        case EType::EffectiveAsset :
            EffectiveAsset *newEffectiveAsset = new EffectiveAsset(MagicThings things);
            _entities.push_back(std::make_shared<EffectiveAsset>(newEffectiveAsset));
            break;
        */

        default:
        {
            std::cerr << "[Simulation] in 'Simulation::createEntity(EType type, int posx, int posy, std::string name)\n\t'EType type' is not a valid EType entity type.\n\tValid types are Entity, Animal, Predator, Prey, Resource, NeutralAsset, EffectiveAsset.\n";
            break;
        }
    }
    return true;
}

std::vector<std::shared_ptr<Entity>> Simulation::getEntities() const
{
    return _entities;
}

std::vector<std::shared_ptr<Entity>> Simulation::getEntitiesByType(EType type) const
{
    std::vector<std::shared_ptr<Entity>> filtered_entities;

    for(auto&& entity : _entities)
    {
        if (entity->getType() == type)
        {
            filtered_entities.push_back(entity);
        }
    }
    
    return filtered_entities;
}

std::vector<std::shared_ptr<Entity>> Simulation::filterEntitiesByType(std::vector<std::shared_ptr<Entity>> entities, std::vector<EType> types)
{
    std::vector<std::shared_ptr<Entity>> filtered_entities;

    for(auto&& entity : entities)
    {
        for(auto&& type : types)
        {
            if (entity->getType() == type)
            {
                filtered_entities.push_back(entity);
            }
        }
    }
    
    return filtered_entities;
}

std::vector<std::shared_ptr<Entity>> Simulation::getEntitiesByPosition(float posx, float posy, int radius) const
{
    std::vector<std::shared_ptr<Entity>> filtered_entities;

    for(auto&& entity : _entities)
    {
        if ( abs(posx - entity->getX()) <= radius && abs(posy - entity->getY()) <= radius )
        {
            filtered_entities.push_back(entity);
        }
    }
    
    return filtered_entities;
}

int Simulation::countEntities(std::vector<EType> types) const
{
    int count = 0;

    for(auto&& type : types)
    {
        count += getEntitiesByType(type).size();
    }

    return count;
}

bool Simulation::processFrame()
{
    
    for(auto&& entity : _entities)
    {
        entity->update();
    }

    //NO MODIFICATIONS UNDER THIS LINE
    mtx_accessFrame.lock();
    _current = SimulationFrame(this);
    mtx_accessFrame.unlock();

    std::cout << "\r[Simulation] Updated " << countEntities( {EType::Animal, EType::Predator, EType::Prey} ) << " entities\r";
    return countEntities( {EType::Animal, EType::Predator, EType::Prey} );
}

//NEVER CALL THIS IN THE SIMULATION THREAD
SimulationFrame& Simulation::getCurrentFrame()
{
    mtx_accessFrame.lock();
    SimulationFrame& _copy(_current);
    mtx_accessFrame.unlock();

    return _copy;
}

int Simulation::width() const
{
    return _width;
}

int Simulation::height() const
{
    return _height;
}

int Simulation::tileSize() const
{
    return _tileSize;
}



/*********** TO BE MOVED ************/
SimulationFrame::SimulationFrame() {}
SimulationFrame::SimulationFrame(Simulation *s) : _entities(s->getEntities()) {}
SimulationFrame::SimulationFrame(SimulationFrame &s) : _entities(s.getEntities()) {}
SimulationFrame::SimulationFrame(SimulationFrame *s) : _entities(s->getEntities()) {}

std::vector<std::shared_ptr<Entity>> SimulationFrame::getEntities() const
{
    return _entities;
}

SimulationFrame::~SimulationFrame() {}