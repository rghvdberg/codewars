// Two Sum
// https://www.codewars.com/kata/52c31f8e6605bcc646000082

/*
 Assert::That(two_sum({1, 2, 3}, 4), Fulfills(EqualsUnordered{0, 2}));
 Assert::That(two_sum({1234, 5678, 9012}, 14690), Fulfills(EqualsUnordered{1, 2}));
 Assert::That(two_sum({2, 2, 3}, 4), Fulfills(EqualsUnordered{0, 1}));
*/

#include <utility>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int> &numbers, int target)
{
    // can't think of a clever (dynamic) way
    // so let's brute force
    int len = numbers.size();
    for (int i = 0; i <= len; i++)
    {
        for (int j = i + 1; j <= len; j++)
        {
            fmt::print("index {} and {}\t {} + {} = {} \n", i, j, numbers[i], numbers[j], numbers[i] + numbers[j]);
            if (numbers[i] + numbers[j] == target)
                return {i, j};
        }
    }

    return {0, 0};
}

int main()
{
    auto result = two_sum({1, 2, 3}, 4);
    fmt::print("{},{}\n", result.first, result.second);
    result = two_sum({1234, 5678, 9012}, 14690);
    fmt::print("{},{}\n", result.first, result.second);
    result = two_sum({2, 2, 3}, 4);
    fmt::print("{},{}\n", result.first, result.second);
}

/*
 Assert::That(two_sum({1, 2, 3}, 4), Fulfills(EqualsUnordered{0, 2}));
 Assert::That(two_sum({1234, 5678, 9012}, 14690), Fulfills(EqualsUnordered{1, 2}));
 Assert::That(two_sum({2, 2, 3}, 4), Fulfills(EqualsUnordered{0, 1}));
*/