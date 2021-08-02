// Perimeter of squares in a rectangle
// https://www.codewars.com/kata/559a28007caad2ac4e000083
#include <iostream>

typedef unsigned long long ull;
class SumFct
{
public:
    static ull perimeter(int n)
    {
        ull sum{0};
        for (int i = 1; i < n + 2; i++)
        {
            sum += getFib(i);
        }

        return sum * 4;
    }

    static ull getFib(int n)
    {
        if (n < 2)
            return n;
        ull f0 = 0;
        ull f2 = 0;
        ull f1 = 1;
        for (int i = 2; i <= n; i++)
        {
            f0 = f2 + f1;
            f2 = f1;
            f1 = f0;
        }
        return f0;
    }
};

int main()
{
    std::cout << SumFct::perimeter(7) << "\n";
    return 0;
}