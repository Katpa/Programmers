#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Island
{
    int food = 0;
    queue<pair<int, int>> heap;

    pair<int, int> PopOut()
    {
        pair<int, int> output = heap.front();
        heap.pop();
        return output;
    }

    void Push(int x, int y, char value)
    {
        food += value - '0';
        heap.push(make_pair(x, y));
    }
};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited;
    vector<Island> islands;

    const int sizeX = maps[0].size();
    const int sizeY = maps.size();

    for (int iter = 0; iter < sizeY; iter++)
    {
        vector<bool> tmp(sizeX, false);
        visited.push_back(tmp);
    }

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            if (maps[y][x] == 'X') continue;
            if (visited[y][x] == true) continue;

            visited[y][x] = true;
            Island island;
            island.Push(x, y, maps[y][x]);

            while (true)
            {
                if (island.heap.empty()) break;

                // first = x, second = y
                pair<int, int> axis = island.PopOut();

                if (axis.first + 1 < sizeX && visited[axis.second][axis.first + 1] == false && maps[axis.second][axis.first + 1] != 'X')
                {
                    island.Push(axis.first + 1, axis.second, maps[axis.second][axis.first + 1]);
                    visited[axis.second][axis.first + 1] = true;
                }

                if (axis.second + 1 < sizeY && visited[axis.second + 1][axis.first] == false && maps[axis.second + 1][axis.first] != 'X')
                {
                    island.Push(axis.first, axis.second + 1, maps[axis.second + 1][axis.first]);
                    visited[axis.second + 1][axis.first] = true;
                }

                if (axis.second - 1 >= 0 && visited[axis.second - 1][axis.first] == false && maps[axis.second - 1][axis.first] != 'X')
                {
                    island.Push(axis.first, axis.second - 1, maps[axis.second - 1][axis.first]);
                    visited[axis.second - 1][axis.first] = true;
                }
            }

            if (island.food > 0)
                islands.push_back(island);
        }
    }

    if (islands.size() == 0) return { -1 };

    for (Island island : islands)
        answer.push_back(island.food);

    sort(answer.begin(), answer.end());

    return answer;
}
