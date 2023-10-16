vector<vector<vector<int>>> answers = { {{6,7,2}, {1,5,9}, {8,3,4}},
                                       {{4,9,2}, {3,5,7}, {8,1,6}},
                                       {{8,1,6}, {3,5,7}, {4,9,2}},
                                       {{6,1,8}, {7,5,3}, {2,9,4}},
                                       {{2,9,4}, {7,5,3}, {6,1,8}},
                                       {{8,3,4}, {1,5,9}, {6,7,2}},
                                       {{4,3,8}, {9,5,1}, {2,7,6}},
                                       {{2,7,6}, {9,5,1}, {4,3,8}} };

int formingMagicSquare(vector<vector<int>> s)
{
    int cost = INT32_MAX;

    for (int iter = 0; iter < answers.size(); iter++)
    {
        int curCost = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (answers[iter][i][j] == s[i][j]) continue;

                curCost += abs(s[i][j] - answers[iter][i][j]);
            }
        }

        if (cost > curCost) cost = curCost;
    }

    return cost;
}