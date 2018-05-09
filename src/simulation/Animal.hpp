#ifndef ANIMAL
#define ANIMAL

class Animal : public Entity
{
public:
    Animal();
    Animal(int posx, int posy, std::string animalName);
    Animal(Animal &a);
    ~Animal();

    

private:
    int hp, atk, def;
    int speed, heading;

};
#endif //ANIMAL