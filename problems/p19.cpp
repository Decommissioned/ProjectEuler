#include <iostream>

int p19()
{
    enum { SUN, MON, TUE, WED, THU, FRI, SAT };
    enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = (MON + 365) % 7;
    int count = 0;
    for (int year = 1901; year <= 2000; ++year)
    {
        for (int month = JAN; month <= DEC; ++month)
        {
            count += day == SUN;
            day = (day + months [month] + (month == FEB && year % 4 == 0)) % 7;
        }
    }
    return count;
}

int main()
{
    std::cout << p19() << std::endl;
}