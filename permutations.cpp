// Permutations
// https://www.codewars.com/kata/5254ca2719453dcc0b00027d

#include <string>
#include <vector>
#include <algorithm>
#include <fmt/ranges.h>

std::vector<std::string> permutations(std::string s)
{
    std::vector<std::string> result;
    std::sort(s.begin(), s.end());
    do
    {
        result.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return result;
}

int main(int argc, char const *argv[])
{
    fmt::print("{}\n", permutations("abcde"));
    return 0;
}
