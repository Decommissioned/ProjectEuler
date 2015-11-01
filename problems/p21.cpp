#include <iostream>
#include <vector>
#include <chrono>

using ints = std::vector<int>;
using namespace std::chrono;

ints sieve(int limit)
{
    limit += 1;
    ints primes = {2};
    bool* check = new bool [limit];
    std::memset(check, 0x01, limit);
    for (int k = 3; k < limit; k += 2)
    {
        for (int n = k << 1; n < limit; check [n] = 0x00, n += k);
    }
    for (int n = 3; n < limit; n += 2)
    {
        if (check [n])
        {
            primes.emplace_back(n);
        }
    }
    delete[] check;
    return primes;
}

int sumdivisors(ints factor) // overly complicated, but at least it seems to run fast
{
    int sum = 1;
    ints combo;
    ints values;
    ints set;
    for (int i = 1; i < factor.size(); ++i)
    {
        combo.push_back(0);
        for (int k = 0; k < combo.size(); combo [k] = k, ++k);
        repeat:
        for (; combo.back() < factor.size(); ++combo.back())
        {
            int product = 1;
            for (int v : combo)
            {
                product *= factor [v];
            }
            values.emplace_back(product);
        }
        --combo.back();
        for (int k = 0; k < combo.size() - 1; ++k)
        {
            int distance = combo [k + 1] - combo [k];
            if (distance > 2)
            {
                ++combo [k];
                combo [k + 1] = combo [k] + 1;
                goto repeat;
            }
            else if (distance == 2)
            {
                ++combo [k];
                goto repeat;
            }
        }
    }
    for (auto value : values)
    {
        bool contains = false;
        for (auto item : set)
        {
            contains |= value == item;
        }
        if (!contains)
        {
            set.emplace_back(value);
            sum += value;
        }
    }
    return sum;
}

int p21()
{
    const int n = 10000;
    ints primes = sieve(n);
    int numbers [n] = {1};
    int sum = 0;
    for (int i = 2; i < n; ++i)
    {
        ints factors;
        for (int k = i, pi = 0; k > 1; ++pi)
        {
            while (k % primes [pi] == 0)
            {
                k /= primes [pi];
                factors.emplace_back(primes [pi]);
            }
        }
        numbers [i] = sumdivisors(factors);
    }
    for (int i = 2; i < n; ++i)
    {
        int j = numbers [i];
        if (i != j && j < n)
        {
            if (i == numbers [j] && j == numbers [i])
            {
                sum += i;
            }
        }
    }
    return sum;
}

int main()
{
    auto start = system_clock::now();
    auto p = p21();
    auto elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << p << "\nElapsed: " << elapsed << "s" << std::endl;
}