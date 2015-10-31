#include <iostream>
#include <string>

std::string mul2(const std::string& number)
{
    int carry = 0;
    std::string result(number.size(), '0');
    auto number_itr = number.rbegin();
    auto result_itr = result.rbegin();
    while (number_itr != number.rend())
    {
        int digit = (*number_itr - '0') * 2;
        *result_itr = (digit % 10 + carry) + '0';
        carry = digit > 9;
        ++number_itr;
        ++result_itr;
    }
    if (carry)
    {
        result.insert(result.begin(), '1');
    }
    return result;
}

int p16()
{
    int power = 1000;
    int sum = 0;
    std::string number("1");
    for (int i = 0; i < power; ++i)
    {
        number = mul2(number);
    }
    for (char c : number)
    {
        sum += c - '0';
    }
    return sum;
}

int main()
{
    std::cout << p16() << std::endl;
}