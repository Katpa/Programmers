#include <string>
#include <vector>

using namespace std;

int answer = 0;

bool IsPlace(int x, int y, vector<vector<bool>> isQueen)
{
    int size = isQueen.size();

    int slashX = x + y;
    int slashY = 0;
    int rSlashX = x - y;
    int rSlashY = 0;

    for (int i = 0; i < y; i++)
    {
        if (isQueen[i][x])
            return false;

        if (slashX >= 0 && slashX < size && isQueen[slashY][slashX])
            return false;

        if (rSlashX >= 0 && rSlashX < size && isQueen[rSlashY][rSlashX])
            return false;

        slashX--;
        slashY++;
        rSlashX++;
        rSlashY++;
    }

    return true;
}

void DFS(int y, vector<vector<bool>> isQueen)
{
    int size = isQueen.size();

    if (y == size)
    {
        answer++;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (IsPlace(i, y, isQueen))
        {
            isQueen[y][i] = true;
            DFS(y + 1, isQueen);
            isQueen[y][i] = false;
        }
    }
}

int solution(int size) {

    vector<vector<bool>> isQueen(size, vector<bool>(size, false));

    DFS(0, isQueen);

    return answer;
}

int main()
{
    int size = 4;

    int answer = solution(size);

    return EXIT_SUCCESS;
}