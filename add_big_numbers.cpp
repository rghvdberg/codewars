// Adding Big Numbers 
// https://www.codewars.com/kata/525f4206b73515bffb000b21

#include <string>
#include <fmt/core.h>
using namespace std;
using namespace fmt;
int main()
{
    string a = "0";
    string b = "0";
    auto a_len = a.size();
    auto b_len = b.size();
    // make both strings the same length
    // fill up with zero;
    if (a_len > b_len)
    {
        const auto add_zeros = a_len - b_len;
        const auto zeroString = string(add_zeros, '0');
        b = zeroString + b;
    }
    else if (a_len < b_len)
    {
        const auto add_zeros = b_len - a_len;
        const auto zeroString = string(add_zeros, '0');
        a = zeroString + a;
    }

    print("{}\t{}\n", a, b);
    string result = "";

    auto sum = 0;
    auto carry = 0;
    auto digit_a = 0;
    auto digit_b = 0;

    auto len = a.size() - 1;

    for (int i = len; i >= 0; i--)
    {
        digit_a = a[i] - '0';
        digit_b = b[i] - '0';
        sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result = to_string(sum - carry * 10) + result;
        print("{}\n", result);
    }
    if (carry)
        result = to_string(carry) + result;
    print("{}\n", result);

    return 0;
}
