#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <string>

enum class EType
{
    Object,     //Generic object
    GroundTile, //Generic ground tile
    Animal,     //Generic animal

    Plant,      //A plant
    Water,      //A piece of water
    NeutralAsset,   //A neutral asset on the map that does not affect in any way nearby entities, like a log, dead leaves, ect
    EffectiveAsset, //An asset that affects the entities above it in some way (dealing damages, slowing movement)
};

class Entity
{
public:
    Entity();
    Entity(Entity &source);
    Entity(int posx, int posy, std::string newName);
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

private:
    float x, y;
    bool visible, movable;

    std::string name;
    std::string texturePath;
};
#endif //ENTITY