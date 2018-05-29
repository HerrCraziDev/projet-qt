#include "Animal.hpp"
#include "SimulationController.hpp"
//#include "utils.hpp"
#include <iostream>


int main(int argc, char *argv[])
{
    /*utl::rand::init();

    Simulation world(1000,1000,8,10,0.5);

    while ( world() );*/

    Simulation world(1000,1000,8,10,0.5);

    SimulationController simulator(&world);

    simulator.setTickLength(100);
    simulator.launch();
    
    while (simulator.state() != SimulationState::Stopping)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        //world.getCurrentFrame();
        //std::cout << "Entities : " << world.countEntities() << "\n";
    }
    std::cout << "Thread should've ended\n";
    
    simulator.stop();

    Simulation newworld(420, 420, 8, 2, 0.5);

    simulator.attach(&newworld);
    simulator.launch();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    simulator.stop();
    //simulator.stop();

    return 0;
}