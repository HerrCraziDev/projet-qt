#ifndef PREY
#define PREY

#include <iostream>

#include "Animal.hpp"


class Prey : public Animal
{
public:
    /* Constructors / Destructors */
    Prey();
    Prey(Simulation *wptr, int posx, int posy, float def, std::string name);
    Prey(Prey &p);

    ~Prey();


    /* Public methods */

    //void eat(Resource res);

    void update();
    void die();

private:
    int _eatRadius;

};
#endif //PREY