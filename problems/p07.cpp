#include <cstdio>

int main()
{
    const int limit = 10001;
    long long primes [limit] = {2};
    long long current = 3;
    for (int index = 1; index < limit; current += 2)
    {
        long long half_current = (current + 1) / 2;
        for (int prime_index = 0; prime_index < index; ++prime_index)
        {
            if (primes [prime_index] > half_current)
            {
                break;
            }
            if (current % primes [prime_index] == 0)
            {
                goto not_prime;
            }
        }
        primes [index++] = current;
        not_prime:;
    }
    std::printf("%lld\n", primes [limit - 1]);
}