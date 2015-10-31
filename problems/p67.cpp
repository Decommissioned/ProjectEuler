#include <iostream>
#include <fstream>
#include <streambuf>

int tn(int n)
{
    return (n * n + n) / 2;
}

int p18()
{
    std::ifstream t("p067_triangle.txt");
    std::string triangle((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    int count = triangle.length() / 3;
    int* numbers = new int[count];
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
    int result = numbers [0];
    delete[] numbers;
    return result;
}

int main()
{
    std::cout << p18() << std::endl;
}