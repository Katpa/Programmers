#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MAX_MAP_SIZE 101

int mapSizeX, mapSizeY;
bool isVisit[MAX_MAP_SIZE][MAX_MAP_SIZE] = { 0 };
int cost[MAX_MAP_SIZE][MAX_MAP_SIZE] = { 0 };

int directionX[4] = { 1, 0, -1, 0 };
int directionY[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    mapSizeX = maps.size();
    mapSizeY = maps[0].size();

    q.push(make_pair(0, 0));
    isVisit[0][0] = true;
    cost[0][0] = 1;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int tmpX = curX + directionX[i];
            int tmpY = curY + directionY[i];

            if (tmpX >= mapSizeX || tmpX < 0 || tmpY >= mapSizeY || tmpY < 0) continue;
            if (isVisit[tmpX][tmpY]) continue;
            if (maps[tmpX][tmpY] == 0) continue;

            isVisit[tmpX][tmpY] = true;
            q.push(make_pair(tmpX, tmpY));

            cost[tmpX][tmpY] = cost[curX][curY] + 1;
        }
    }

    if (isVisit[mapSizeX - 1][mapSizeY - 1])
        answer = cost[mapSizeX - 1][mapSizeY - 1];
    else
        answer = -1;

    return answer;
}

int main()
{
    vector<vector<int>> maps = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };

    int answer = solution(maps);

    return EXIT_SUCCESS;
}