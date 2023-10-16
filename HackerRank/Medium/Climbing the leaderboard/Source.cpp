vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> output(player.size());

    int rank = 1;
    int lastNum = ranked[0];
    int index = player.size() - 1;

    for (int r : ranked)
    {
        if (lastNum != r) rank++;

        while (r <= player[index])
        {
            output[index] = rank;
            index--;
        }

        lastNum = r;
    }

    rank++;

    while (index >= 0)
    {
        output[index] = rank;
        index--;
    }

    return output;
}