// Sort the odd
// https://www.codewars.com/kata/578aa45ee9fd15ff4600090d

#include <vector>
#include <algorithm>
#include <iostream>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::vector<int> temp = array;
        std::sort(temp.begin(), temp.end());

        for (int i = 0, j = 0; i < array.size(); i++)
        {
            if (array[i] % 2) // odd number, replace with sorted tmp
            {
                while (temp[j] % 2 == 0) // if temp[j] is an even number, try the next j
                    j++;
                array[i] = temp[j];
                j++;
            }
            std::cout << array[i] << "\n";
        }
        return array;
    }
};

int main()
{
    Kata myKata;
    myKata.sortArray({5, 8, 6, 3, 4});
}