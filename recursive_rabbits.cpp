#include <iostream>

unsigned long long recursive_rabbits(unsigned long long n, unsigned long long k){
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
    unsigned long long n;
    unsigned long long k;

    unsigned long long numberOfRabbits;

    n = std::strtoull(argv[1], 0, 10);
    k = std::strtoull(argv[2], 0, 10);

    numberOfRabbits = recursive_rabbits(n, k);
    std::printf("%llu", numberOfRabbits);

    return 0;
}