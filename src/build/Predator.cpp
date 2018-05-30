#include "Predator.hpp"
#include "Simulation.hpp"

Predator::Predator() : Animal(), _kills(0), _killRadius(ST_TILESIZE/2) {}

Predator::Predator(Simulation *wptr, int posx, int posy, float atk, float def, std::string name) : Animal(wptr, posx, posy, name)
{
    type = EType::Predator;
    setAtk(atk);
    setDef(def);

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


void Predator::attack(Animal& target)
{
    std::cout << "[Predator] Predator " << getName() << " attacks " << target.getName() << " !\n";

    if ( atk() > target.def() )
    {
        target.setHp(target.getHp() - (atk() - target.getDef()));
        setHp(getHp() + atk() - target.getDef());
        addKill();
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
        //Execute moves
        move( (float)utl::rand::get(0, speed())/10, heading() + utl::rand::get(-10, 10) );

        //Get the neighboring Preys that can be attacked
        std::vector<std::shared_ptr<Entity>> neighbors = Simulation::filterEntitiesByType(world->getEntitiesByPosition(getX(), getY(), 16), {EType::Animal, EType::Prey} );
        //If there is Preys to attack in range, attack the first Prey found
        if ( neighbors.size() )
        {
            std::shared_ptr<Prey> target = std::dynamic_pointer_cast<Prey>(neighbors[0]);
            if ( target )
            {
                attack(*target);
            }
        }

        if ( !isAlive() ) die();
    }
}

void Predator::die()
{
    type = EType::DeadPredator;
}