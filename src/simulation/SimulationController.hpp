#ifndef SIMCTRL
#define SIMCTRL

#include <iostream>
#include <thread>

#include "Simulation.hpp"

/*
A side note about Simulations : 
The simulation is processed step-by-step into simulation frames. A simulation frame represents a fixed state of
the simulation at a give time. The time step between two frames can be modified and determines how fast the
simulation runs.
The physical simulation runs separately from the graphical rendering (or terminal rendering if used).
This means that sometimes one graphical frame rendering can take more time than a physical simulation frame
processing. Then multiple simulation frames would be processed during one single graphical frame. 
The inverse situation is also possible, multiple graphical frames could be rendered while only one simulation
frame have been processed.
*/

/* Possible states of the simulation */
enum class SimulationState
{
    Paused,     //The simulation is paused
    Stopped,    //The simulation have been stopped
    Running,    //The simulation is running but on idle state (ie. not processing) (This state is safe for threads)
    Processing, //The simulation is processing a step. This state is NOT thread-safe
    Initialized //The simulation have been initialized but haven't been launched yet
};

class SimulationController
{
public:
    SimulationController();
    ~SimulationController();

    void launch();  //Launch the simulation
    void pause();   //Pause the simulation
    void resume();  //Resume the simulation if paused
    void stop();    //Stop the simulation. No further frame will be processed

    void setTickLength(int ticklength); //Set the physical simulation tick length (ie. the time between two simulation frames)
    int getTickLength() const;          //Get the physical simulation tick length

    void exec(int frames=1);    //Process the given number of frames

    Simulation* getSimulation() const;  //Return the current simulation frame

    SimulationState getState() const;

private:
    double processedFrames;
    int tickLength;
    SimulationState state;
    Simulation *sim;

};
#endif //SIMCTRL