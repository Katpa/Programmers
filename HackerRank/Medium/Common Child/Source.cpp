int commonChild(string s1, string s2)
{
    vector<vector<int>> vec(s1.size() + 1, vector<int>(s2.size() + 1));

    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if (i == 0 || j == 0)
                vec[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                vec[i][j] = vec[i - 1][j - 1] + 1;
            else
                vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
        }
    }

    return vec[s1.size()][s2.size()];
}