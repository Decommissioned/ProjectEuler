#include <iostream>
#include <string>

int p18()
{
    long long max_i = 1;
    int max_c = 0;
    for (int i = 1; i < 1000000; ++i)
    {
        int c = 0;
        for (long long n = i; n != 1; n = n & 1 ? 3 * n + 1 : n / 2, ++c);
        max_c = max_c > c ? max_c : c;
        max_i = max_c > c ? max_i : i;
    }
    return max_i;
}

int main()
{
    std::cout << p18() << std::endl;
}