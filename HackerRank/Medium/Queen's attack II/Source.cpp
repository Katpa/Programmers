int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int cnt = 0;
    int r = n + 1, l = 0, ru = n + 1, rd = 0, ld = 0, lu = n + 1, u = n + 1, d = 0;
    for (int i = 0; i < obstacles.size(); i++)
    {
        int y = obstacles[i][0];
        int x = obstacles[i][1];
        if (y == r_q)
        {
            if (x > c_q)
                r = min(r, x);
            else
                l = max(l, x);
        }
        else if (x == c_q)
        {
            if (y > r_q)
                u = min(u, y);
            else
                d = max(d, y);
        }
        else if (r_q + c_q == x + y)
        {
            if (y > r_q)
                lu = min(lu, y);
            else
                rd = max(rd, y);
        }
        else if (r_q - c_q == y - x)
        {
            if (y > r_q)
                ru = min(ru, y);
            else
                ld = max(ld, y);
        }
    }
    cnt += (r - c_q - 1);
    cnt += (c_q - l - 1);

    cnt += (u - r_q - 1);
    cnt += (r_q - d - 1);

    cnt += min(c_q - 1, lu - r_q - 1);
    cnt += min(c_q - 1, r_q - ld - 1);
    cnt += min(n - c_q, r_q - rd - 1);
    cnt += min(n - c_q, ru - r_q - 1);
    return cnt;
}