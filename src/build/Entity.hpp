#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <string>
#include <vector>


/* Available types of Entities */

enum class EType
{
    Entity,     //Generic entity (a more precise type should be used instead of this)
    Animal,     //Generic animal
    Predator,   //A special type of Animal that have an aggressive behavior an eats Preys
    Prey,       //A special type of Animal which can be eated by a Predator and eats Resources
    Resource,      //A resource (special type of EffectiveAsset that gives health and disappears once eated)
    NeutralAsset,   //A neutral asset on the map that does not affect in any way nearby entities, like a log, dead leaves, ect
    EffectiveAsset, //An asset that affects the nearby entities in some way (dealing damages, slowing movement)
};

/* Sugar everywhere ! We loove sugar !*/
static const std::vector<EType> EntityTypes = {   EType::Entity, 
                                                    EType::Animal, 
                                                    EType::Predator, 
                                                    EType::Prey, 
                                                    EType::Resource, 
                                                    EType::NeutralAsset, 
                                                    EType::EffectiveAsset };

std::ostream& operator<< (std::ostream &ostr, EType type);


/* The basic representation of an Entity */

class Entity
{
public:
    Entity();
    Entity(Entity &source);
    
    Entity(EType type, int posx, int posy, std::string newName);
    ~Entity();

    void lock()
    {
        movable = false;
    }

    void unlock()
    {
        movable = true;
    }

    void show()
    {
        visible = true;
    }

    void hide() 
    {
        visible = false;
    }

    void rename(std::string newName)
    {
        name = newName;
    }

    std::string getName() const
    {
        return name;
    }

    bool isMovable() const
    {
        return movable;
    }

    bool isVisible() const
    {
        return visible;
    }


    //getPos();
    //setPos(Point npos);
    float getX() const
    {
        return x;
    }

    float getY() const
    {
        return y;
    }

    void setX(float nx)
    {
        x = nx;
    }

    void setY(float ny)
    {
        y = ny;
    }

    std::string getTexturePath() const
    {
        return texturePath;
    }

    void setTexturePath(std::string newTexturePath)
    {
        texturePath = newTexturePath;
    }

    EType getType() const
    {
        return type;
    }

    virtual void update();
    
protected:
    float x, y;
    bool visible, movable;

    std::string name;
    std::string texturePath;
    EType type;
};
#endif //ENTITY