#include <iostream>
typedef unsigned long long ull;

ull recursive_rabbits(ull n, ull k){
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return ((k * recursive_rabbits(n - 2, k)) + recursive_rabbits(n - 1, k));
    }
}




int main(int argc, char* argv [])
{
    ull n;
    ull k;

    ull numberOfRabbits;

    n = std::strtoull(argv[1], 0, 10);
    k = std::strtoull(argv[2], 0, 10);

    numberOfRabbits = recursive_rabbits(n, k);
    std::printf("%llu", numberOfRabbits);

    return 0;
}