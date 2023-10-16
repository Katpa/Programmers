int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

vector<string> bomberMan(int n, vector<string> grid)
{
    vector<string> board = grid;

    if (n == 1) return board;

    n -= 2;
    int cnt = n % 4;

    for (int loopCnt = 0; loopCnt < 2; loopCnt++)
    {
        vector<pair<int, int>> axis;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (board[i][j] == 'O') axis.push_back(make_pair(i, j));
                else board[i][j] = 'O';
            }
        }

        if (cnt == 0 || cnt == 2) break;

        for (pair<int, int> p : axis)
        {
            for (int iter = 0; iter < 4; iter++)
            {
                int i = p.first + di[iter];
                int j = p.second + dj[iter];

                if (i < 0 || i >= board.size()) continue;
                if (j < 0 || j >= board[0].size()) continue;

                board[i][j] = '.';
            }

            board[p.first][p.second] = '.';
        }

        if (cnt == 1 || cnt == 3 && loopCnt == 1) break;
    }

    return board;
}