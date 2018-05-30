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
#include "Predator.hpp"
#include "Prey.hpp"

class Simulation;

/* A side note about SimulationFrames :
A SimulationFrame represents the state of the whole simulation at a given time. 
Copying SimulationFrames is a safe way to deal with threads concurrent access problems. The
thread continues working on the main class while data-based operations can be safely performed
on a SimulationFrame.
*/
class SimulationFrame
{
public:
    SimulationFrame();
    SimulationFrame(Simulation *s);
    SimulationFrame(SimulationFrame &s);
    SimulationFrame(SimulationFrame *s);
    ~SimulationFrame();

    std::vector<std::shared_ptr<Entity>> getEntities() const;

private:
    std::vector<std::shared_ptr<Entity>> _entities;
};


class Simulation
{
public:
    /* Constructors / Destructors */
    Simulation();
    Simulation(int worldWidth, int worldHeight, int tileSize, int nbAnimals, float predatorsPrct, uint seed);
    ~Simulation();


    /* Public methods */

    bool createEntity(EType type, int posx, int posy, std::string name);    //Create a new entity of the given type at (posx, posy)
    bool addEntity(EType type, Entity *e);                                  //Add an already created entity on the map

    //bool createTile(TMaterial material, int tilex, int tiley);
    //bool addTile(TMaterial material, Tile *t);

    static std::vector<std::shared_ptr<Entity>> filterEntitiesByType(std::vector<std::shared_ptr<Entity>> entities, std::vector<EType> types);

    std::vector<std::shared_ptr<Entity>> getEntities() const;
    std::vector<std::shared_ptr<Entity>> getEntitiesByPosition(float posx, float posy, int radius) const;
    std::vector<std::shared_ptr<Entity>> getEntitiesByType(EType type) const;
    int countEntities(std::vector<EType> types = EntityTypes) const;
    //std::vector<std::vector<std::shared_ptr<Tile>>> getWorld() const;

    bool processFrame();                //Process the next SimulationFrame
    SimulationFrame& getCurrentFrame(); //Return the current SimulationFrame (copied)

    //Getters for world size informations
    int width() const;
    int height() const;
    int tileSize() const;
    
    bool operator() ()
    {
        return processFrame();
    }

private:
    int _width, _height, _tileSize;
    std::vector<std::shared_ptr<Entity>> _entities;
    std::mutex mtx_accessFrame;                     //Mutex locking access to _current
    //std::vector<std::vector<std::shared_ptr<Tile>>> _world;

    SimulationFrame _current;   //The current SimulationFrame (state of the whole simulation at this time)
};


#endif //SIMULATION