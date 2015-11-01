#include <iostream>
#include <chrono>

using namespace std::chrono;

int sumdivisors(int number)
{
    int sum = 1;
    for (int i = 2; i < number; sum += i * (number % i == 0), ++i);
    return sum;
}

int p23()
{
    const int n = 20161 + 1;
    bool abundant [n];
    bool check [n] = {false}; 
    int sum = 0;
    for (int i = 1; i < n; abundant [i] = sumdivisors(i) > i, ++i);
    for (int i = 1; i < n; ++i)
    {
        for (int k = i; k < n - i; check [i + k] |= abundant [i] && abundant [k], ++k);
    }
    for (int i = 1; i < n; sum += i * !check [i], ++i);
    return sum;
}

int main()
{
    auto start = system_clock::now();
    auto p = p23();
    auto elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << p << "\nElapsed: " << elapsed << "s" << std::endl;
}