// RGB To Hex Conversion
// https://www.codewars.com/kata/513e08acc600c94f01000001
#include <iomanip>
#include <algorithm>
#include <iostream>

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        std::stringstream result;
        result << std::hex << std::setfill('0') << std::uppercase;
        result << std::setw(2) << std::clamp(r, 0, 255)
               << std::setw(2) << std::clamp(g, 0, 255)
               << std::setw(2) << std::clamp(b, 0, 255);
        return result.str();
    }
};

int main(int argc, char const *argv[])
{
    std::cout << RGBToHex::rgb(255, 255, 255) << "\n";
    return 0;
}
