//  Mexican Wave
// https://www.codewars.com/kata/58f5c63f1e26ecda7e000029
#include <vector>
#include <fmt/ranges.h>
#include <string>
#include <cctype>

std::vector<std::string> wave(std::string y)
{
    std::vector<std::string> result;
    const int str_length = y.size();

    for (int pos = 0; pos < str_length; pos++)
    {
        std::string tmp = y;
        if (tmp[pos] != ' ')
        {
            tmp[pos] = std::toupper(tmp[pos]);
            result.push_back(tmp);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    fmt::print("{}\n", wave("hello world"));
    return 0;
}
