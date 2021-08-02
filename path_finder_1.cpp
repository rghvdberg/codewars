#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <fmt/ranges.h>

using namespace std;
using namespace fmt;

void makeMaze(const string &maze, std::map<std::pair<int, int>, char> &mazeMap)
{
    int x = 0, y = 0;
    for (auto &c : maze)
    {
        if (c == '\n')
        {
            x = 0;
            y++;
        }
        else
        {
            mazeMap[std::pair<int, int>(x, y)] = c;
            x++;
        }
    }
}

std::pair<int, int> getMazeSize(const std::map<std::pair<int, int>, char> &mazeMap)
{
    int width = 0, height = 0;
    for (auto &m : mazeMap)
    {
        if (m.first.first > width)
            width = m.first.first;
        if (m.first.second > height)
            height = m.first.second;
    }
    return {width, height};
}

std::pair<int, int> canMove(const std::pair<int, int> &pos, const std::pair<int, int> &move, std::map<std::pair<int, int>, char> &mazeMap)
{
    const std::pair<int, int> dest = {pos.first + move.first, pos.second + move.second};
    if (mazeMap.find(dest) == mazeMap.end() || mazeMap[dest] == 'W')
        return {-1, -1};
    else
        return dest;
}

bool path_finder(string maze)
{
    constexpr std::pair<int, int> moves[4] = {
        {0, -1}, // up
        {1, 0},  // right
        {0, 1},  // down
        {-1, 0}, // left
    };

    std::queue<pair<int, int>> que;
    std::vector<pair<int, int>> visited;

    std::map<std::pair<int, int>, char> mazeMap;
    makeMaze(maze, mazeMap);
    auto sz = getMazeSize(mazeMap);

    std::pair<int, int> start(0, 0);
    std::pair<int, int> finish(sz.first, sz.second);

    que.push(start);
    visited.push_back(start);
    std::pair<int, int> nextCell(-1, -1);

    while (!que.empty())
    {
        auto &current = que.front();
        for (int i = 0; i < 4; i++)
        {
            nextCell = canMove(current, moves[i], mazeMap);
            if (nextCell == finish)
                return true;

            auto isVisited = std::find(visited.begin(), visited.end(), nextCell) != visited.end();
            if (nextCell.first >= 0 && nextCell.second >= 0 && !isVisited)
            {
                que.push(nextCell);
                visited.push_back(nextCell);
            }
        }
        que.pop();
    }
    return std::find(visited.begin(), visited.end(), finish) != visited.end();
}

int main(int argc, char const *argv[])
{
    std::vector<string> mazes = {
        ".W.\n.W.\n...",                                  // true
        ".W.\n.W.\nW..",                                  // false
        "......\n......\n......\n......\n......\n......", // true
        "......\n......\n......\n......\n.....W\n....W.", // false
    };
    for (auto &maze : mazes)
    {
        fmt::print("{}\npath found:{}\n\n", maze, path_finder(maze));
    }
    return 0;
}
