#ifndef UTILS
#define UTILS

#include <vector>
#include <cstdlib>
#include <ctime>

/* Ca fait le gaz et le sucre, mais pas le café*/

namespace utl
{
    class rand
    {
    public:
        rand();
        rand(int min, int max);
        ~rand();

        virtual int get();
        void seed(uint seed);

        int operator()()
        {
            return get();
        }

        static void init();
        static int get(int min, int max);

    protected:
        int _min, _max;
        uint _seed;
    };

    class unique_rand : public rand
    {
    public:
        unique_rand();
        unique_rand(int min, int max);
        ~unique_rand();

        int get();
        void reset();

    private:
        int _calls;
        std::vector<int> _prev;
    };

    template <typename T>
    int findInVect(T value, std::vector<T> vect);
}
#endif //UTILS