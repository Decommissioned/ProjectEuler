#include <cstdio>

int main()
{
    int sum = 0;
    for (int i = 3; i < 1000; ++i)
    {
        sum += !(i % 3 && i % 5) * i;
    }
    std::printf("%d\n", sum);
}