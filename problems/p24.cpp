#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono>
#include <vector>

using ints = std::vector<long long>;
using namespace std::chrono;

void permutate(const ints& set, ints instance, ints& permutations)
{
    if (set.size() == 1)
    {
        instance.emplace_back(set.front());
        long long sum = 0;
        for (auto item : instance)
        {
            sum = (sum * 10) + item;
        }
        permutations.emplace_back(sum);
        return;
    }
    for (auto item : set)
    {
        ints nset;
        ints perm = instance;
        perm.emplace_back(item);
        std::copy_if(set.begin(), set.end(), std::back_inserter(nset), [item] (const auto& value) { return item != value; });
        permutate(nset, perm, permutations);
    }
}

long long p24()
{
    ints set = {0,1,2,3,4,5,6,7,8,9};
    ints result;
    permutate(set, {}, result);
    return result[1000000 - 1];
}

int main()
{
    auto start = system_clock::now();
    auto p = p24();
    auto elapsed = duration_cast<nanoseconds>(system_clock::now() - start).count() / 1E9;
    std::cout << "Answer: " << p << "\nElapsed: " << elapsed << "s" << std::endl;
}