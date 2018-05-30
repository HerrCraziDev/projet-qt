#ifndef PREDATOR
#define PREDATOR

#include <iostream>
#include <vector>
#include <memory>

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
    void attack(Animal& target);    //Attacks a target

    int kills() const;      //Get the number of Preys this Predator have killed
    int killRadius() const; //Get the collision radius used to determine whether or not the Predator should attack
    
    void addKill();         //Add a kill to this Predator
    void killRadius(int radius);    //Set the kill radius

    void update();
    void die();

private:
    int _kills, _killRadius;

};
#endif //PREDATOR