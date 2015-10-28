#include <cstdio>

int main()
{
    for (int number = 999 * 999; number > 0; number--)
    {
        bool palindrome = true;
        int digits [6] = {0};
        int index = 0;
        for (int copy = number; copy > 0; copy /= 10)
        {
            digits [index++] = copy % 10;
        }
        for (int h = 0, t = index - 1; h < t; ++h, --t)
        {
            palindrome &= digits [h] == digits [t];
        }
        if (palindrome)
        {
            for (int divisor = 999; divisor > 99; divisor--)
            {
                if (number % divisor == 0 && number / divisor < 1000)
                {
                    std::printf("%d\n", number);
                    return 0;
                }
            }
        }
    }
} 