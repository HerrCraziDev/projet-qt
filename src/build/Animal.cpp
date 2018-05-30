#include "Animal.hpp"
#include "Simulation.hpp"

Animal::Animal() : Entity()
{
    std::cout << "[Animal] Warning ! The default empty constructor for Animal was used. This will create an empty Animal.\n";
}

Animal::Animal(Simulation *wptr, std::string animalName) : Entity(wptr, EType::Animal, 0, 0, animalName), _hp(100), _atk(10), _def(10), _speed(10), _heading(utl::rand::get(0,360))
{
    std::cout << "[Animal] New Animal created (constr: 'Animal::Animal(std::string animalName)')\n";
}

Animal::Animal(Simulation *wptr, int posx, int posy, std::string animalName) : Entity(wptr, EType::Animal, posx, posy, animalName), _hp(100), _atk(10), _def(10), _speed(10), _heading(utl::rand::get(0,360))
{
    std::cout << "[Animal] New Animal created (constr: 'Animal::Animal(int posx, int posy, std::string animalName)')\n";
}

Animal::Animal(Animal &a) : Entity(a), _hp(a.getHp()), _atk(a.getAtk()), _def(a.getDef()), _speed(a.getSpeed()), _heading(a.getHeading())
{
    std::cout << "[Animal] Animal copied.\n";
}

Animal::~Animal()
{
    std::cout << "[Animal] Animal scrhffblrfized\n";
}



/* Computed accessors */
float Animal::hp() const
{
    return _hp * 1;
}

int Animal::atk() const
{
    return _atk * 1;
}

int Animal::def() const
{
    return _def * 1;
}

float Animal::speed() const
{
    return _speed * 1;
}

int Animal::heading() const
{
    return _heading * 1;
}


/* Getters */
float Animal::getHp() const
{
    return _hp;
}

int Animal::getAtk() const
{
    return _atk;
}

int Animal::getDef() const
{
    return _def;
}

float Animal::getSpeed() const
{
    return _speed;
}

int Animal::getHeading() const
{
    return _heading;
}

/* Setters */
void Animal::setHp(float value)
{
    _hp = value;
}

void Animal::setAtk(int value)
{
    _atk = value;
}

void Animal::setDef(int value)
{
    _def = value;
}

void Animal::setSpeed(float value)
{
    _speed = value;
}

void Animal::setHeading(int value)
{
    _heading = value % 360;
}


float Animal::hpModifier() const
{
    return _hpModifier;
}

float Animal::atkModifier() const
{
    return _atkModifier;
}

float Animal::defModifier() const
{
    return _defModifier;
}

float Animal::speedModifier() const
{
    return _speedModifier;
}


void Animal::hpModifier(float value)
{
    _hpModifier = value;
}

void Animal::atkModifier(float value)
{
    _atkModifier = value;
}

void Animal::defModifier(float value)
{
    _defModifier = value;
}

void Animal::speedModifier(float value)
{
    _speedModifier = value;
}

bool Animal::isAlive() const
{
    return (_hp > 0);
}

bool Animal::move(float dx, float dy)
{
    setX(getX() + dx);
    setY(getY() + dy);
    setHp( getHp() - sqrt(dx*dx + dy*dy)/10 );
    return true;
}

bool Animal::move(float dl, int angle)
{
    float radAngle = angle * (M_PI / 180);
    float futureX = getX() + dl*cos(radAngle);
    float futureY = getY() + dl*sin(radAngle);
    
    if ( futureX < 0 || futureX + ST_TILESIZE > world->width()*world->tileSize() )
    {
        _heading = - _heading + 180;
    } 
    else if ( futureY < 0 || futureY + ST_TILESIZE > world->height()*world->tileSize() )
    {
        _heading = - _heading;
    }


    setX(futureX);
    setY(futureY);
    setHp( getHp() - dl/5 );

    return true;
}

void Animal::update()
{
    if ( isAlive() ) 
    {
        move( (float)utl::rand::get(0, speed())/10, _heading + utl::rand::get(-10, 10) );

        if ( !isAlive() ) //He died :(
        {
            die();
        }
    }
}

void Animal::die()
{
    type = EType::NeutralAsset;
}