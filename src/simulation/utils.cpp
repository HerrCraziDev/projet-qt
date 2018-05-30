#include "utils.hpp"

utl::rand::rand() : _min(0), _max(RAND_MAX), _seed(std::time(nullptr))
{
    seed(_seed);
}

utl::rand::rand(int min, int max) : _min(min), _max(max), _seed(std::time(nullptr))
{
    seed(_seed);
}

utl::rand::~rand() {}

void utl::rand::seed(uint seed)
{
    std::srand(seed);
    _seed = seed;
}

int utl::rand::get()
{
    return ( std::rand() % (_max - _min) ) + _min;
}

int utl::rand::get(int min, int max)
{
    return ( std::rand() % (max - min) ) + min;
}

void utl::rand::init()
{
    std::srand(std::time(nullptr));
}

void utl::rand::seed(uint seed)
{
    std::srand(seed);
}


utl::unique_rand::unique_rand() : rand(), _calls(0) {}

utl::unique_rand::unique_rand(int min, int max) : rand(min, max), _calls(0) {}

utl::unique_rand::~unique_rand() {}

int utl::unique_rand::get()
{
    if (_calls >= (_max - _min)) { reset(); }

    utl::rand rval(_min, _max);
    int urval;

    do
    {
        urval = rval();
    } while (utl::findInVect(urval, _prev) != -1);

    _calls++;
    _prev.push_back(urval);
    return urval; 
}

void utl::unique_rand::reset()
{
    _calls = 0;
    _prev.clear();
}



template <typename T>
int utl::findInVect(T value, std::vector<T> vect)
{
    for (uint i ; i < vect.size() ; ++i)
    {
        if (value == vect[i]) return i;
    }

    return -1;
}