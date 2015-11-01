#include <iostream>
#include <string>
#include <chrono>

using string = std::string;
using namespace std::chrono;

string add(const string& a, const string& b)
{
    string result;
    uint32_t cy = 0;
    int as = a.size();
    int bs = b.size();
    int rs = (as > bs ? as : bs);
    result.reserve(rs + 1);
    for (int i = 1; i <= rs; ++i)
    {
        int ai = as - i >= 0 ? a [as - i] - '0' : 0;
        int bi = bs - i >= 0 ? b [bs - i] - '0' : 0;
        int digit = ai + bi + (cy % 10);
        result.insert(0, 1, digit % 10 + '0');
        cy = (cy / 10) + (digit / 10);
    }
    if (cy)
    {
        result.insert(0, 1, cy + '0');
    }
    return result;
}

int p20()
{
    int n = 100;
    int sum = 0;
    string result = std::to_string(n);
    for (int i = n - 1; i > 0; --i)
    {
        string acc = result;
        for (int k = 1; k < i; acc = add(acc, result), ++k);
        result = acc;
    }
    for (char ch : result)
    {
        sum += ch - '0';
    }
    return sum;
}

int main()
{
    auto start = system_clock::now();
    auto result = p20();
    double elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << result << "\nElapsed: " << elapsed << "s" << std::endl;
}