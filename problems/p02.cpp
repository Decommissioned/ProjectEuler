#include <cstdio>

int main()
{
    int sum = 0;
    int previous_term = 1;
    int current_term = 1;
    while (current_term < 4000000)
    {
        sum += current_term * !(current_term % 2);
        int aux = previous_term;
        previous_term = current_term;
        current_term += aux;
    }
    std::printf("%d\n", sum);
}