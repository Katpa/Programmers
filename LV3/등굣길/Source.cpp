#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    vector<int> start = { 0, 0 };
    vector<vector<bool>> puddle;
    vector<vector<int>> map;
    map.resize(n + 1);
    puddle.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        map[i].resize(m + 1);
        puddle[i].resize(m + 1);
        for (int j = 0; j <= m; j++)
        {
            map[i][j] = 0;
            puddle[i][j] = false;
        }
    }

    for (vector<int> p : puddles)
        puddle[p[1]][p[0]] = true;

    map[1][0] = 1;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (puddle[y][x]) continue;
            map[y][x] = (map[y][x - 1] + map[y - 1][x]) % 1000000007;
        }
    }

    answer = map[n][m];

    return answer;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { {2, 2} };

    int answer = solution(m, n, puddles);

    return EXIT_SUCCESS;
}