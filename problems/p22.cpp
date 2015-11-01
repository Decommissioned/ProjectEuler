#include <algorithm>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>
#include <chrono>

using string = std::string;
using strings = std::vector<std::string>;
using namespace std::chrono;

long long p22()
{
    std::ifstream file("p022_names.txt");
    string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    strings names;
    bool start = true;
    long long sum = 0;
    for (size_t i = 0, si; i < content.size(); ++i)
    {
        char ch = content [i];
        if (ch == '\"')
        {
            if (start)
            {
                si = i + 1;
            }
            else
            {
                names.emplace_back(std::move(content.substr(si, i - si)));
            }
            start = !start;
        }
    }
    std::sort(names.begin(), names.end());    
    for (int i = 0; i < names.size(); ++i)
    {
        int acc = names[i].size();
        for (char ch : names [i])
        {
            acc += ch - 'A';
        }
        sum += (i + 1) * acc;
    }
    return sum;
}

int main()
{
    auto start = system_clock::now();
    auto p = p22();
    auto elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << p << "\nElapsed: " << elapsed << "s" << std::endl;
}