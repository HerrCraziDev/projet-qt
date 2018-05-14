#include "SimulationController.hpp"

SimulationController::SimulationController(Simulation *s) :
    processedFrames(0),
    tickLength(10),
    state(SimulationState::Initialized)
{
    sim = s;
    
    std::cout << "[SimulationController] Simulation initialized\n";

}

