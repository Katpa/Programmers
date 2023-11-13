#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

bool visited[501][501][4];
vector<string> G;
int sizeX, sizeY;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int Search(int dir, int x, int y, int cnt)
{
    if (visited[y][x][dir] == true) return cnt;
    visited[y][x][dir] = true;

    switch (G[y][x])
    {
    case 'L':
        dir--;
        if (dir < 0) dir += 4;
        break;
    case 'R':
        dir++;
        if (dir > 3) dir -= 4;
        break;
    }

    x += dx[dir];
    y += dy[dir];

    if (x < 0) x += sizeX;
    else if (x >= sizeX) x -= sizeX;
    if (y < 0) y += sizeY;
    else if (y >= sizeY) y -= sizeY;

    return Search(dir, x, y, cnt + 1);
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    G = grid;
    sizeX = grid[0].size();
    sizeY = grid.size();

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int cnt = Search(dir, x, y, 0);
                if (cnt != 0) answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}