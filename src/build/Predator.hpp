#ifndef PREDATOR
#define PREDATOR

#include <iostream>

#include "Animal.hpp"
#include "settings.hpp"


class Predator : public Animal
{
public:
    /* Constructors / Destructors */
    Predator();
    Predator(Simulation *wptr, int posx, int posy, float atk, float def, std::string name);
    Predator(Predator &p);

    ~Predator();


    /* Public methods */
    void attack(Animal target);

    int kills() const;
    int killRadius() const;
    
    void addKill();
    void killRadius(int radius);

    void update();
    void die();

private:
    int _kills, _killRadius;

};
#endif //PREDATOR