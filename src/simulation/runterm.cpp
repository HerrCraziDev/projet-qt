#include "Animal.hpp"
#include "Simulation.hpp"

int main(int argc, char *argv[])
{
    
    Animal superpanzer("SUPERPANZER");
    Animal ours(8,5,"Peau de l'ours (avec ours)");

    std::cout << superpanzer.getName() << " a " << superpanzer.atk() << " points d'attaque\n";

    Simulation world(42,42,16,2,50);
    world.createEntity(EType::NeutralAsset, 4,4,"Caillou en pierre de roche");

    return 0;
}