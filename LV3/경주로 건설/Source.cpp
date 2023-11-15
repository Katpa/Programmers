#include <string>
#include <vector>
#include <queue>

#define CORNER 500
#define STRAIGHT 100

#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Node
{
    int x;
    int y;
    int cost;
    int dir;
};

int solution(vector<vector<int>> board)
{
    int sizeX = board[0].size();
    int sizeY = board.size();

    queue<Node> q;
    vector<vector<vector<int>>> costs(sizeY, vector<vector<int>>(sizeX, vector<int>(4, 2147483647)));

    if (board[0][1] != 1)
    {
        q.push({ 0, 0, 100, DOWN });
        costs[0][0][DOWN] = 100;
    }

    if (board[1][0] != 1)
    {
        q.push({ 0, 0, 100, RIGHT });
        costs[0][0][RIGHT] = 100;
    }

    while (!q.empty())
    {
        Node curRoad = q.front();
        int fromDir = (curRoad.dir + 2) % 4;
        q.pop();

        int nextX = curRoad.x + dx[curRoad.dir];
        int nextY = curRoad.y + dy[curRoad.dir];

        for (int nextDir = 0; nextDir < 4; nextDir++)
        {
            if (nextDir == fromDir)
            {
                if (costs[nextY][nextX][nextDir] > curRoad.cost)
                    costs[nextY][nextX][nextDir] = curRoad.cost;
                continue;
            }

            int dNextX = nextX + dx[nextDir];
            int dNextY = nextY + dy[nextDir];

            if (dNextX < 0 || dNextX >= sizeX) continue;
            if (dNextY < 0 || dNextY >= sizeY) continue;
            if (board[dNextX][dNextY] == 1) continue;

            int nextCost = curRoad.cost + STRAIGHT;

            if (nextDir != curRoad.dir)
                nextCost += CORNER;

            if (costs[nextY][nextX][nextDir] > nextCost)
            {
                q.push({ nextX, nextY, nextCost, nextDir });
                costs[nextY][nextX][nextDir] = nextCost;
            }
        }
    }

    return min(costs[sizeY - 1][sizeX - 1][LEFT], costs[sizeY - 1][sizeX - 1][UP]);
}