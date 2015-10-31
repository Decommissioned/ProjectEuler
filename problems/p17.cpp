#include <iostream>
#include <string>

std::string say(int number)
{
    static const std::string units[] = {" ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    static const std::string decades[] = {" ", " ", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};    
    static const std::string exceptions[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    static const std::string hundred = "hundred ";

    if (number == 0)
    {
        return "zero";
    }
    if (number == 1000)
    {
        return "one thousand";
    }

    std::string str;
    bool centuries = number % 1000 > 99;

    if (centuries)
    {
        str += units [(number % 1000) / 100] + hundred;
    }

    if (number % 100 >= 20)
    {
        if (centuries)
        {
            str += "and ";
            centuries = false;
        }
        str += decades [(number % 100) / 10];
    }
    else if (number % 100 >= 10)
    {
        if (centuries)
        {
            str += "and ";
            centuries = false;
        }
        str += exceptions [(number % 100) - 10];
        goto done;
    }

    if (centuries && number % 10)
    {
        str += "and ";
        centuries = false;
    }
    str += units [number % 10];
    done: return str;
}

int p17()
{
    int count = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        for (char ch : say(i))
        {
            count += ch >= 'a' && ch <= 'z';
        }
    }
    return count;
}

int main()
{
    std::cout << p17() << std::endl;
}