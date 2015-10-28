#include <cstdio>

int main()
{
    const int N = 100;
    long long sq_of_sum = 0;
    long long sum_of_sq = 0;
    for (int i = 0; i < N; i++)
    {
        sq_of_sum += i + 1;
        sum_of_sq += (i + 1) * (i + 1);
    }
    sq_of_sum *= sq_of_sum;
    std::printf("%lld\n", sq_of_sum - sum_of_sq);
}