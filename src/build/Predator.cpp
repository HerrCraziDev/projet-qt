#include "Predator.hpp"

Predator::Predator() : Animal(), _kills(0), _killRadius(ST_TILESIZE/2) {}

Predator::Predator(Simulation *wptr, int posx, int posy, float atk, float def, std::string name) : Animal(wptr, posx, posy, name)
{
    type = EType::Predator;
    std::cout << "[Predator] New predator created : " << name << "\n";
}

Predator::Predator(Predator &p) : Animal(p), _kills(p.kills()), _killRadius(p.killRadius()) 
{
    type = EType::Predator;
    std::cout << "[Predator] Predator copied\n";
}

Predator::~Predator() {}



int Predator::kills() const
{
    return _kills;
}

int Predator::killRadius() const
{
    return _killRadius;
}

void Predator::addKill()
{
    _kills++;
}

void Predator::killRadius(int radius)
{
    _killRadius = abs(radius);
}


void Predator::attack(Animal target)
{
    if ( atk() > target.def() )
    {
        target.setHp(target.getHp() - (atk() - target.getDef()));
        setHp(getHp() + atk() - target.getDef());
    } else {
        setHp(getHp() - target.getDef());
    }

    if ( !target.isAlive() ) target.die();
    if ( !isAlive() ) die();
}

void Predator::update()
{
    if ( isAlive() ) 
    {
        move( (float)utl::rand::get(0, speed())/10, heading() + utl::rand::get(-10, 10) );

        if ( !isAlive() ) die();
    }
}

void Predator::die()
{
    type = EType::DeadPredator;
}