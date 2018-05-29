#include "SimulationController.hpp"

SimulationController::SimulationController() : 
    _processedFrames(0),
    _tickLength(10),
    _state(SimulationState::Empty)
{

}

SimulationController::SimulationController(Simulation *s) :
    _processedFrames(0),
    _tickLength(10),
    _state(SimulationState::Initialized)
{
    _sim = s;

    
    std::cout << "[SimulationController] Simulation initialized\n";

}

SimulationController::~SimulationController()
{
    std::cout << "[SimulationController] Thread state : " << state() << "\n";
    if (state() != SimulationState::Stopped) 
    {
        stop();
    }
}


void SimulationController::launch()
{
    th_sim = std::thread(worker, this);

    std::cout << "[SimulationController] Simulation launched\n";
    //th_sim.join();
}

void SimulationController::pause()
{
    if (state() != SimulationState::Paused)
    {
        mtx_pause.lock();
        state(SimulationState::Paused);
    }

}

void SimulationController::resume()
{
    if (state() == SimulationState::Paused) mtx_pause.unlock();
}

void SimulationController::stop()
{
    if (state() != SimulationState::Stopped && state() != SimulationState::Empty)
    {
        resume();
        state(SimulationState::Stopping);
        th_sim.join();
        state(SimulationState::Stopped);
    }
}

void SimulationController::attach(Simulation *s)
{
    stop();
    _sim = s;
    state(SimulationState::Initialized);
}

void SimulationController::worker(SimulationController *that)
{
    Simulation *_sim = that->getSimulation();
    bool simAlive = true;

    std::cout << "un peu de café\n";

    while ( that->state() != SimulationState::Stopping && simAlive )
    {
        that->mtx_pause.lock();
        that->mtx_pause.unlock();

        that->state(SimulationState::Running);
        simAlive = (*_sim)();

        std::this_thread::sleep_for(std::chrono::milliseconds(that->getTickLength()));
    }

    that->state(SimulationState::Stopping);
}

void SimulationController::setTickLength(int tickLength)
{
    _tickLength = tickLength;
}

int SimulationController::getTickLength() const
{
    return _tickLength;
}

Simulation* SimulationController::getSimulation() const
{
    return _sim;
}

SimulationFrame SimulationController::getSimulationFrame() const
{
    //SimulationFrame& s = _sim->getCurrentFrame();
}

SimulationState SimulationController::state()
{
    mtx_state.lock();
    SimulationState tmp = _state;
    mtx_state.unlock();

    return tmp;
}

void SimulationController::state(SimulationState state)
{
    mtx_state.lock();
    //We must prevent the Stopping state from being overwritten by anything else than Stopped
    if (_state != SimulationState::Stopping || state == SimulationState::Stopped) _state = state;
    mtx_state.unlock();
}

std::ostream& operator<< (std::ostream &out, SimulationState state)
{
    switch (state)
    {
        case SimulationState::Initialized:
            out << "SimulationState::Initialized";
            break;
        case SimulationState::Running:
            out << "SimulationState::Running";
            break;
        case SimulationState::Processing:
            out << "SimulationState::Processing";
            break;
        case SimulationState::Paused:
            out << "SimulationState::Paused";
            break;
        case SimulationState::Stopped:
            out << "SimulationState::Stopped";
            break;
        case SimulationState::Stopping:
            out << "SimulationState::Stopping";
            break;

        default:
            out << "[unknown state]";
    }

    return out;
}