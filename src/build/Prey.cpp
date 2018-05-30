#include "Prey.hpp"

Prey::Prey() : Animal() {}

Prey::Prey(Simulation *wptr, int posx, int posy, float def, std::string name) : Animal(wptr, posx, posy, name)
{
    type = EType::Prey;
    std::cout << "[Predator] New predator created : " << name << "\n";
}

Prey::Prey(Prey &p) : Animal(p)
{
    type = EType::Prey;
}

Prey::~Prey() {}


void Prey::update()
{

}

void Prey::die()
{
    type = EType::DeadPrey;
}