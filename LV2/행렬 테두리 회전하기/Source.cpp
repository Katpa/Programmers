#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

void Swap(int y, int x, int& nextNum, int& minNum)
{
    int n = board[y][x];
    board[y][x] = nextNum;
    nextNum = n;

    if (minNum > board[y][x])
        minNum = board[y][x];
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    board.resize(rows);
    for (int iter = 0; iter < board.size(); iter++)
        board[iter].resize(columns);

    int num = 1;
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < columns; x++)
            board[y][x] = num++;

    for (vector<int> query : queries)
    {
        for (int& n : query)
            n--;

        int startX = query[1];
        int startY = query[0];
        int endX = query[3];
        int endY = query[2];

        int minNum = 10001;
        int nextNum = board[startY][startX];

        for (int x = startX + 1; x <= endX; x++)
            Swap(startY, x, nextNum, minNum);

        for (int y = startY + 1; y <= endY; y++)
            Swap(y, endX, nextNum, minNum);

        for (int x = endX - 1; x >= startX; x--)
            Swap(endY, x, nextNum, minNum);

        for (int y = endY - 1; y >= startY; y--)
            Swap(y, startX, nextNum, minNum);

        answer.push_back(minNum);
    }

    return answer;
}