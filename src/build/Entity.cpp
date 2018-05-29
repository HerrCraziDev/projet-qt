#include "Entity.hpp"

Entity::Entity() : x(0), y(0), visible(true), movable(false), name(""), texturePath("") {}

Entity::Entity(EType t, int posx, int posy, std::string newName) :
    x(posx), 
    y(posy), 
    visible(true), 
    movable(false),
    name(newName), 
    texturePath(""),
    type(t)
{
    std::cout << "[Entity] New Entity created : " << name << "\n";
}

Entity::Entity(Entity &source) :
     x(source.getX()),
     y(source.getY()), 
     visible(source.isVisible()), 
     movable(source.isMovable()),
     name(source.getName()), 
     texturePath(source.getTexturePath()),
     type(source.getType())
{
    std::cout << "[Entity] Entity copied\n";
}

Entity::~Entity()
{
    std::cout << "[Entity] Entity deleted\n";
}

void Entity::update()
{
    //something
}



std::ostream& operator<< (std::ostream &ostr, EType type)
{
    
    switch (type)
    {
        case EType::Entity:
            ostr << "EType::Entity";
            break;
        case EType::Animal:
            ostr << "EType::Animal";
            break;
        case EType::Predator:
            ostr << "EType::Predator";
            break;
        case EType::Prey:
            ostr << "EType::Prey";
            break;
        case EType::NeutralAsset:
            ostr << "EType::NeutralAsset";
            break;
        case EType::EffectiveAsset:
            ostr << "EType::EffectiveAsset";
            break;
        case EType::Resource:
            ostr << "EType::Resource";
            break;
        default:
            break;
    }
    return ostr;
}
