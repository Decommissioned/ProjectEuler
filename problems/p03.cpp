#include <cstdio>

void next_prime(long long& number)
{
    next:
    number += 2;
    for (long long i = 3; i < (number / 2); i += 2)
    {
        if (number % i == 0)
        {
            goto next;
        }
    }
}

int main()
{
    long long number = 600851475143;
    long long factor = 3;
    while (number != 1)
    {
        if (number % factor)
        {
            next_prime(factor);
        }
        else
        {
            number /= factor;
        }
    }
    std::printf("%lld\n", factor);
}