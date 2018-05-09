#include "SimulationController.hpp"

SimulationController::SimulationController() :
    processedFrames(0),
    tickLength(10),
    state(SimulationState::Initialized)
{
    std::cout << "[SimulationController] Simulation initialized\n";
}

