#include <iostream>

using u64 = unsigned long long;

u64 ncr(u64 n, u64 r)
{
    if (r == 0)
    {
        return 1;
    }
    return n * ncr(n - 1, r - 1) / r;
}

int main()
{
    int n = 20;
    std::cout << ncr(2 * n, n) << std::endl;
}