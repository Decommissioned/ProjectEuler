#include <iostream>

int tn(int n)
{
    return (n * n + n) / 2;
}

int p18()
{
    const char triangle[] = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
    const int count = sizeof(triangle) / 3;
    int numbers [count];
    int height = 0;
    for (int i = 0; i < count; ++i)
    {
        numbers [i] = 10 * (triangle [3 * i] - '0') + (triangle [3 * i + 1] - '0');
        height += i > tn(height);
    }
    for (int n = height - 1; n > 0; --n)
    {
        int end = tn(n) - 1;
        int start = end - n + 1;
        for (int current = end; current >= start; --current)
        {
            int left = numbers [current + n];
            int right = numbers [current + n + 1];
            numbers [current] += left > right ? left : right;
        }
    }
    return numbers[0];
}

int main()
{
    std::cout << p18() << std::endl;
}