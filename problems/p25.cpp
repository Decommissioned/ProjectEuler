#include <iostream>
#include <chrono>

using namespace std::chrono;

const int N = 1000;
uint8_t temp [N];
uint8_t previous [N] = {0};
uint8_t current [N] = {1};

int p25()
{
    int index;
    int carry = 0;
    for (index = 0; current [N - 1] == 0; ++index)
    {
        std::memcpy(temp, current, N);
        for (int k = 0; k < N; ++k)
        {
            int digit = previous [k] + current [k] + carry;
            current [k] = digit % 10;
            carry = carry / 10 + digit / 10;
        }
        std::memcpy(previous, temp, N);
    }
    return index + 1;
}

int main()
{
    auto start = system_clock::now();
    auto p = p25();
    auto elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << p << "\nElapsed: " << elapsed << "s" << std::endl;
}