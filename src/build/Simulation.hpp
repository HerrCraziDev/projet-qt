/* TODO:
implémenter World dans Simulation avec un foncteur pour le processing d'une SimulationFrame
*/

#ifndef SIMULATION
#define SIMULATION

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>

#include "Animal.hpp"

class Simulation;

class SimulationFrame
{
public: 
    SimulationFrame();
    SimulationFrame(Simulation *s);
    SimulationFrame(SimulationFrame &s);
    ~SimulationFrame();

    std::vector<std::shared_ptr<Entity>> getEntities() const;

private:
    std::vector<std::shared_ptr<Entity>> _entities;
};


class Simulation
{
public:
    Simulation();
    Simulation(int worldWidth, int worldHeight, int tileSize, int nbAnimals, float predatorsPrct);
    ~Simulation();

    bool createEntity(EType type, int posx, int posy, std::string name);  //Create a new entity of the given type at (posx, posy)
    bool addEntity(EType type, Entity *e);              //Add an already created entity on the map

    //bool createTile(TMaterial material, int tilex, int tiley);
    //bool addTile(TMaterial material, Tile *t);

    std::vector<std::shared_ptr<Entity>> getEntities() const;
    std::vector<std::shared_ptr<Entity>> getEntitiesByPosition(int tilex, int tiley) const;
    std::vector<std::shared_ptr<Entity>> getEntitiesByType(EType type) const;
    int countEntities(std::vector<EType> types = EntityTypes) const;
    //std::vector<std::vector<std::shared_ptr<Tile>>> getWorld() const;

    bool processFrame();
    SimulationFrame getCurrentFrame();
    
    bool operator() ()
    {
        return processFrame();
    }

private:
    std::vector<std::shared_ptr<Entity>> _entities;
    std::mutex mtx_accessFrame;
    //std::vector<std::vector<std::shared_ptr<Tile>>> _world;

    SimulationFrame _current;
};


#endif //SIMULATION