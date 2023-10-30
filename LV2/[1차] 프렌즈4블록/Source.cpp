#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (true)
    {
        vector<pair<int, int>> dels;

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == '-') continue;

                if (board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 1][j + 1])
                {
                    dels.push_back({ j, i });
                }
            }
        }

        if (dels.size() == 0) break;

        for (pair<int, int> p : dels)
        {
            for (int i = 0; i < 4; i++)
            {
                if (board[p.second + dy[i]][p.first + dx[i]] != '-')
                    answer++;
                board[p.second + dy[i]][p.first + dx[i]] = '-';
            }
        }

        for (int x = 0; x < n; x++)
        {
            int emptyY = -1;
            for (int y = m - 1; y >= 0; y--)
            {
                if (emptyY == -1 && board[y][x] == '-')
                    emptyY = y;
                else if (emptyY != -1 && board[y][x] != '-')
                {
                    board[emptyY][x] = board[y][x];
                    board[y][x] = '-';
                    emptyY--;
                }
            }
        }
    }

    return answer;
}