#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

pair<int, int> scale;
vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
map<pair<int, int>, int> visited;

void Visit(int x, int y) { visited[make_pair(x, y)] = 1; }
bool IsVisited(int x, int y) { return visited[make_pair(x, y)] == 1; }

struct Rico
{
    int x = 0;
    int y = 0;
    int cnt = 0;

    bool operator==(const Rico& rico) { return this->x == rico.x && this->y == rico.y; }
};

bool Move(Rico curRico, Rico& next, int dir, vector<string>& board)
{
    while (true)
    {
        next.x += dx[dir];
        next.y += dy[dir];

        if (next.x < 0 || next.x >= scale.first ||
            next.y < 0 || next.y >= scale.second ||
            board[next.y][next.x] == 'D')
        {
            next.x -= dx[dir];
            next.y -= dy[dir];
            if (IsVisited(next.x, next.y)) return false;
            Visit(next.x, next.y);
            next.cnt = curRico.cnt + 1;
            return true;
        }
    }

    return false;
}

int BFS(Rico start, vector<string>& board)
{
    queue<Rico> ricos;

    ricos.push(start);

    while (!ricos.empty())
    {
        Rico rico = ricos.front();
        ricos.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            Rico nextRico = rico;
            if (!Move(rico, nextRico, dir, board)) continue;

            if (board[nextRico.y][nextRico.x] == 'G')
            {
                return nextRico.cnt;
            }
            ricos.push(nextRico);
        }
    }

    return -1;
}

int solution(vector<string> board)
{
    int answer = 0;
    bool isLoop = true;
    Rico start;
    scale.first = board[0].size();
    scale.second = board.size();

    for (int y = 0; y < scale.second; y++)
    {
        for (int x = 0; x < scale.first; x++)
        {
            if (board[y][x] != 'R') continue;

            start.x = x;
            start.y = y;
            Visit(start.x, start.y);
            isLoop = false;
            break;
        }

        if (!isLoop) break;
    }

    answer = BFS(start, board);

    return answer;
}