#include <string>
#include <vector>

using namespace std;

int keySize;
int lockSize;

void RotateBoard(vector<vector<int>>& board)
{
    vector<vector<int>> swapBoard = board;

    for (int y = 0; y < lockSize; y++)
        for (int x = 0; x < lockSize; x++)
            board[x][lockSize - 1 - y] = swapBoard[y][x];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    keySize = key.size();
    lockSize = lock.size();

    int subboardSize = keySize + (lockSize - 1) * 2;
    vector<vector<int>> extendedKey(subboardSize, vector<int>(subboardSize, 0));
    for (int y = 0; y < keySize; y++)
        for (int x = 0; x < keySize; x++)
            extendedKey[y + lockSize - 1][x + lockSize - 1] = key[y][x];

    int searchSize = keySize + lockSize - 1;
    for (int loop = 0; loop < 4; loop++)
    {
        for (int y = 0; y < searchSize; y++)
        {
            for (int x = 0; x < searchSize; x++)
            {
                bool isContinue = true;
                for (int cy = 0; isContinue && cy < lockSize; cy++)
                {
                    for (int cx = 0; isContinue && cx < lockSize; cx++)
                    {
                        if (lock[cy][cx] != extendedKey[y + cy][x + cx]) continue;

                        isContinue = false;
                    }
                }
                if (isContinue == true) return true;
            }
        }

        RotateBoard(lock);
    }

    return false;
}