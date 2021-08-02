// Product of consecutive Fib numbers
// https://www.codewars.com/kata/5541f58a944b85ce6d00006a

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>

typedef unsigned long long ull;
class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod)
    {
        ull i{0};
        ull x{0};
        ull y{0};
        ull test{0};
        while (prod > test)
        {
            x = getFib(i);
            y = getFib(i + 1);
            test = x * y;
            if (test == prod)
            {
                return {x, y, 1};
            }
            i++;
        }
        return {x, y, 0};
    }

    static ull getFib(ull n)
    {
        if (n < 2)
            return n;
        ull f0 = 0;
        ull f2 = 0;
        ull f1 = 1;
        for (ull i = 2; i <= n; i++)
        {
            f0 = f2 + f1;
            f2 = f1;
            f1 = f0;
        }
        return f0;
    }
};

int main(int argc, char const *argv[])
{

    //dotest(4895, {55, 89, true});
    fmt::print("{}\n", ProdFib::productFib(4895));
    fmt::print("{}\n", ProdFib::productFib(5895));
    fmt::print("{}\n", ProdFib::productFib(74049690));
    fmt::print("{}\n", ProdFib::productFib(84049690));

    return 0;
}
