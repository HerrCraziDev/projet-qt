#include "Entity.hpp"

int main(int argc, char *argv[])
{
    Entity panzer(10,10,"Panzer");

    Entity panzer2(panzer);

    return 0;
}