// Sum of Intervals
// https://www.codewars.com/khttps://www.codewars.com/kata/52b7ed099cdc285c300001cdata/52b7ed099cdc285c300001cd

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <set>
using namespace std;
using namespace fmt;

int sum_intervals(std::vector<std::pair<int, int>> iv)
{
  bool did_a_merge = false;
  std::sort(iv.begin(), iv.end());
  auto last = std::unique(iv.begin(), iv.end());
  iv.erase(last, iv.end());
  print("sorted \n {}\n", iv);
  std::vector<std::pair<int, int>> result;
  std::pair<int, int> tmp;
  int len = iv.size();

  for (auto i = iv.begin(); i != iv.end(); ++i)
  {
  restart:
    for (auto j = i + 1; j != iv.end(); j++)
    {

      print("compare , {}{}\n", *i, *j);
      if ((i->second > j->first))
      {
        print("{} and {} overlap\n", *i, *j);
        const int frst = i->first;
        const int scnd = i->second > j->second
                             ? i->second
                             : j->second;
        tmp = {frst, scnd};
        print("merged : {}\n", tmp);
        *i = tmp;
        iv.erase(j);
        goto restart;
      }
    }
  }

  auto sum = 0;
  for (auto i : iv)
    sum += i.second - i.first;
  return sum;
}

int main()
{
  std::vector<std::pair<int, int>> test = {
      {194, 296},
      {-377, -198},
      {151, 293},
      {285, 287},
      {-181, -173},
      {212, 213},
      {-66, 390},
  };
  // std::vector<std::pair<int, int>> test = {
  //     {-5, 0},
  //     {3, 5},
  //     {-2, 1},
  // };

  print("{}\n", sum_intervals(test));
  return 0;
}
