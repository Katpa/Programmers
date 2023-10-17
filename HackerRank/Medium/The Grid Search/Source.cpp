string gridSearch(vector<string> G, vector<string> P)
{
    int width = P[0].size(), height = P.size();
    pair<int, int> limitIndex = make_pair(G[0].size() - width, G.size() - height);

    for (int h = 0; h <= limitIndex.second; h++)
    {
        for (int w = 0; w <= limitIndex.first; w++)
        {
            if (G[h][w] != P[0][0]) continue;

            //if(Check(G, P, h, w) == true) return "YES";
            bool isLoop = true;

            for (int i = h; i < h + height && isLoop; i++)
            {
                for (int j = w; j < w + width && isLoop; j++)
                {
                    if (G[i][j] != P[i - h][j - w]) isLoop = false;
                }
            }

            if (isLoop == true) return "YES";
        }
    }

    return "NO";
}