// Shortest Knight Path
// https://www.codewars.com/kata/549ee8b47111a81214000941
#include <queue>
#include <map>
#include <vector>
#include <utility>
#include <fmt/ranges.h>
#include <array>
#include <algorithm>
using namespace std;
using namespace fmt;

std::pair<int, int> alg2cor(std::string alg)
{
    auto x = alg[0] - 'a';
    auto y = alg[1] - '1';
    return {x, y};
}

std::string cor2alg(const std::pair<int, int> &cor)
{
    std::string result;
    result.push_back('a' + cor.first);
    result.push_back('1' + cor.second);
    return result;
}

std::pair<int, int> canMove(std::pair<int, int> pos, std::pair<int, int> move)
{
    const int x = pos.first + move.first;
    const int y = pos.second + move.second;
    if (x > 7 || x < 0 || y > 7 || y < 0)
    {
        return {-1, -1};
    }
    else
    {
        return {x, y};
    }
}

int main()
{
    constexpr array<pair<int, int>, 8> moves =
        {{{1, 2},
          {2, 1},
          {2, -1},
          {1, -2},
          {-1, -2},
          {-2, -1},
          {-2, 1},
          {-1, 2}}};
    constexpr int SIZE = 7;

    queue<pair<int, int>> que;
    vector<pair<int, int>> visited;
    map<pair<int, int>, pair<int, int>> solution;

    auto start = alg2cor("a1");
    auto finish = alg2cor("f8");
    que.push(start);
    visited.push_back(start);
    std::pair<int, int> nextCell = {-1, -1};
    while (!que.empty())
    {
        auto &current = que.front();
        for (auto &move : moves)
        {
            nextCell = canMove(current, move);
            auto isVisited = std::find(visited.begin(), visited.end(), nextCell) != visited.end();
            if (nextCell.first >= 0 && nextCell.second >= 0 && !isVisited)
            {
                que.push(nextCell);
                visited.push_back(nextCell);
                solution[nextCell] = current;
            }
            if (nextCell == finish)
                break;
        }
        if (nextCell == finish)
            break;
        que.pop();
    }

    auto steps = 0;
    auto current = finish;
    print("{}\n", cor2alg(current));
    while (current != start)
    {
        steps++;
        current = solution[current];
        print("{}\n", cor2alg(current));
    }
    print("from {} to {} is {} steps\n", cor2alg(start), cor2alg(finish), steps);
    return EXIT_SUCCESS;
}
