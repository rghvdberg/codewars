#include <iostream>
#include <map>
#include <string>

int solution(std::string roman)
{
    std::map<char, int> numerals;

    numerals['I'] = 1;
    numerals['V'] = 5;
    numerals['X'] = 10;
    numerals['L'] = 50;
    numerals['C'] = 100;
    numerals['D'] = 500;
    numerals['M'] = 1000;

    int last_value = 0;
    int sum = 0;
    int length = roman.length();
    for (int i = 0; i < length; i++)
    {
        char n = roman[i];
        int value = numerals[n];
        if (value > last_value)
        {
            sum = sum - 2 * last_value + value;
        }
        else
        {
            sum += value;
        }
        last_value = value;
    }
    return sum;
}

int main()
{
    std::cout << solution("XXI") << "\n";     // Equals(21));
    std::cout << solution("I") << "\n";       // Equals(1));
    std::cout << solution("IV") << "\n";      // Equals(4));
    std::cout << solution("MMVIII") << "\n";  // Equals(2008));
    std::cout << solution("MDCLXVI") << "\n"; // Equals(1666));
};
