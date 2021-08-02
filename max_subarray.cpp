// Maximum subarray sum
// https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <algorithm>
#include <vector>
using namespace std;
using namespace fmt;

int maxSequence(const std::vector<int> &arr)
{
    // check for all negative elements
    const auto max = std::max_element(arr.begin(), arr.end());
    if (*max < 0)
        return 0;

    int result = 0;
    const auto len = arr.size();

    for (int h = 0; h < len; h++)
    {
        for (int i = h; i < len; i++)
        {
            int sum = 0;
            for (int j = h; j < i + 1; j++)
            {
                sum += arr[j];
                print("{}, ", arr[j]);
            }
            print("\tsum = {}\n", sum);
            if (sum > result)
                result = sum;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    print("{}\n", maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}));
    return 0;
}
