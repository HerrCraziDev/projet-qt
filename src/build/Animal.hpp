#ifndef ANIMAL
#define ANIMAL

#include <iostream>
#include <cmath>
#include "Entity.hpp"
#include "utils.hpp"



class Animal : public Entity
{
public:
    Animal();
    Animal(std::string animalName);
    Animal(int posx, int posy, std::string animalName);
    Animal(Animal &a);
    ~Animal();

    /* Accessors for computed properties */
    float hp() const;
    int atk() const;
    int def() const;
    float speed() const;
    int heading() const;

    /* Getters */
    float getHp() const;
    int getAtk() const;
    int getDef() const;
    float getSpeed() const;
    int getHeading() const;

    /* Setters */
    void setHp(float value);
    void setAtk(int value);
    void setDef(int value);
    void setSpeed(float value);
    void setHeading(int value);

    /* Getters / setters for property modifiers */
    float hpModifier() const;
    float atkModifier() const;
    float defModifier() const;
    float speedModifier() const;

    void hpModifier(float value);
    void atkModifier(float value);
    void speedModifier(float value);
    void defModifier(float value);

    bool isAlive() const;

    virtual bool move(float dx, float dy);
    virtual bool move(float dl, int angle);
    virtual void update();

private:
    float _hp;
    int _atk, _def;
    float _speed;
    int _heading;

    float _hpModifier = 1, _atkModifier = 1, _defModifier = 1, _speedModifier = 1;
};
#endif //ANIMAL