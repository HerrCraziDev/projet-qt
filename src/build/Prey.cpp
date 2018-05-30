#include "Prey.hpp"

Prey::Prey() : Animal() {}

Prey::Prey(Simulation *wptr, int posx, int posy, float def, std::string name) : Animal(wptr, posx, posy, name)
{
    type = EType::Prey;
    setDef(def);
    setHp(getHp() + utl::rand::get(-30, 30));
    
    std::cout << "[Predator] New predator created : " << name << "\n";
}

Prey::Prey(Prey &p) : Animal(p)
{
    type = EType::Prey;
}

Prey::~Prey() {}


void Prey::update()
{
    if ( isAlive() ) 
    {
        move( (float)utl::rand::get(0, speed())/10, heading() + utl::rand::get(-10, 10) );

        if ( !isAlive() ) //He died :(
        {
            die();
        }
    }
}

void Prey::die()
{
    type = EType::DeadPrey;
}