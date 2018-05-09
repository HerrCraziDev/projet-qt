#include "Entity.hpp"

Entity::Entity() : x(0), y(0), visible(true), movable(false), name(""), texturePath("") {}

Entity::Entity(int posx, int posy, std::string newName) : 
    x(posx), 
    y(posy), 
    visible(true), 
    movable(false),
    name(newName), 
    texturePath("")
{
    std::cout << "[Entity] New Entity created\n";
}

Entity::Entity(Entity &source) : 
     x(source.getX()),
     y(source.getY()), 
     visible(source.isVisible()), 
     movable(source.isMovable()),
     name(source.getName()), 
     texturePath(source.getTexturePath())
{
    std::cout << "[Entity] Entity copied\n";
}

Entity::~Entity()
{
    std::cout << "[Entity] Entity deleted\n";
}