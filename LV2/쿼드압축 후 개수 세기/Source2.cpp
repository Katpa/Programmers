#include <string>
#include <vector>
using namespace std;

vector<vector<int>> board;

void DFS(int x, int y, int size, vector<int>& answer)
{
    bool isZero = true, isOne = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            board[i][j] ? isZero = false : isOne = false;
        }
    }

    if (isZero)
    {
        answer[0]++;
        return;
    }
    if (isOne)
    {
        answer[1]++;
        return;
    }

    int half = size >> 1;
    DFS(x, y, half, answer);
    DFS(x, y + half, half, answer);
    DFS(x + half, y, half, answer);
    DFS(x + half, y + half, half, answer);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2, 0);
    board = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}