#include "Simulation.hpp"


Simulation::Simulation() {}

Simulation::Simulation(int worldWidth, int worldHeight, int tileSize, int nbAnimals, float predatorsPrct)
{
   
    for(int i = 0; i < nbAnimals; i++)
    {
        createEntity(EType::Animal, 24, 42, "Peau de l'ours (avec ours)");   
    }
    
}

Simulation::~Simulation() {}


bool Simulation::createEntity(EType type, int posx, int posy, std::string name)
{
    
    switch (type)
    {
        case EType::Animal :
        {
            Animal *newAnimal = new Animal(posx, posy, name);
            _entities.push_back(std::make_shared<Animal>(*newAnimal));
            break;
        }
        case EType::Entity :
        {
            Entity *newEntity = new Entity(EType::Entity, posx, posy, name);
            _entities.push_back(std::make_shared<Entity>(*newEntity));
            break;
        }
        /*
        case EType::Predator :
            Predator *newPredator = new Predator(MagicThings things);
            _entities.push_back(std::make_shared<Predator>(newPredator));
            break;

        case EType::Prey :
            Predator *newPrey = new Predator(MagicThings things);
            _entities.push_back(std::make_shared<Prey>(newPrey));
            break;

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
        case EType::Predator:
        case EType::Prey:
        case EType::Resource:
        case EType::NeutralAsset:
        case EType::EffectiveAsset:
        {
            std::cerr << "[Simulation] in 'Simulation::createEntity(EType type, int posx, int posy, std::string name)\n\t 'EType type' (" << type << ") : Entity type not implemented.\n";
            break;
        }
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
    SimulationFrame _current(this);
    mtx_accessFrame.unlock();

    std::cout << "[Simulation] Updated " << countEntities( {EType::Animal, EType::Predator, EType::Prey} ) << " entities\n";
    return countEntities( {EType::Animal, EType::Predator, EType::Prey} );
}

//NEVER CALL THIS IN THE SIMULATION THREAD
SimulationFrame Simulation::getCurrentFrame()
{
    mtx_accessFrame.lock();
    SimulationFrame _copy = _current;
    mtx_accessFrame.unlock();

    return _copy;
}

/*********** TO BE MOVED ************/
SimulationFrame::SimulationFrame() {}
SimulationFrame::SimulationFrame(Simulation *s) : _entities(s->getEntities()) {}
SimulationFrame::SimulationFrame(SimulationFrame &s) : _entities(s.getEntities()) {}

std::vector<std::shared_ptr<Entity>> SimulationFrame::getEntities() const
{
    return _entities;
}

SimulationFrame::~SimulationFrame() {}