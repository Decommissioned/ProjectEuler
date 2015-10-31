#include <iostream>
#include <vector>

unsigned long long p12()
{
    std::vector<int> primes = {2, 3};
    auto divisors = [&primes](int number) -> int
    {
        int count = 1;
        int power = 0;
        int index = 0;
        int rem = number;
        while (rem != 1)
        {
            if (index >= primes.size())
            {
                for (int patient = primes.back() + 2;; patient += 2)
                {
                    bool isprime = true;
                    for (int prime : primes)
                    {
                        isprime &= patient % prime != 0;
                    }
                    if (isprime)
                    {
                        primes.push_back(patient);
                        break;
                    }
                }
            }
            if (rem % primes [index] == 0)
            {
                rem /= primes [index];
                power++;
            }
            else
            {
                index++;
                count *= power + 1;
                power = 0;
            }
        }
        return count * (power + 1);
    };
    int tn = 1;
    for (int n = 1; divisors(tn) <= 500; ++n, tn = (n * n + n) / 2);
    return tn;
}

int main()
{
    std::cout << p12() << std::endl;
}