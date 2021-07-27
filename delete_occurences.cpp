// Delete occurrences of an element if it occurs more than n times
// https://www.codewars.com/kata/554ca54ffa7d91b236000023

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <map>
#include <vector>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::map<int, int> count;
    std::vector<int> result;
    for (auto &i : arr)
    {
        count[i]++;
        if (count[i] <= n)
            result.push_back(i);
    }

    fmt::print("input {}\n", arr);
    fmt::print("count {}\n", count);
    fmt::print("result 
    {}\n", result);
    return {result};
}

int main(int argc, char const *argv[])
{
    deleteNth({1, 1, 1, 1}, 2); // # return [1,1]

    deleteNth({20, 37, 20, 21}, 1); // # return [20,37,21]

    return 0;
}
