#include "Simulation.hpp"


Simulation::Simulation() {}

Simulation::Simulation(int worldWidth, int worldHeight, int tileSize, int nbAnimals, float predatorsPrct)
{
    float preysPrct = 100 - predatorsPrct;

    
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
            Predator *newResource = new Predator(MagicThings things);
            _entities.push_back(std::make_shared<Resource>(newResource));
            break;

        case EType::NeutralAsset :
            Predator *newNeutralAsset = new Predator(MagicThings things);
            _entities.push_back(std::make_shared<NeutralAsset>(newNeutralAsset));
            break;
        
        case EType::EffectiveAsset :
            Predator *newEffectiveAsset = new Predator(MagicThings things);
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



/*********** TO BE MOVED ************/
SimulationFrame::SimulationFrame() {}
SimulationFrame::SimulationFrame(Simulation *s) {}
SimulationFrame::~SimulationFrame() {}