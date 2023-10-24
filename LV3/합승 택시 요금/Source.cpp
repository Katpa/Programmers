//Floyd Warshall

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    vector<vector<int>> floyd(n + 1, vector<int>(n + 1, 0));

    for (vector<int> vec : fares)
    {
        floyd[vec[0]][vec[1]] = vec[2];
        floyd[vec[1]][vec[0]] = vec[2];
    }

    for (int iter = 1; iter < n + 1; iter++)
    {
        for (int start = 1; start < n + 1; start++)
        {
            if (iter == start) continue;

            for (int dest = 1; dest < n + 1; dest++)
            {
                if (dest == iter) continue;
                if (dest == start) continue;

                int a = floyd[start][dest];
                int b;
                if (floyd[start][iter] == 0 || floyd[iter][dest] == 0)
                    b = 0;
                else
                    b = floyd[start][iter] + floyd[iter][dest];

                if (a == 0 && b == 0)
                    floyd[start][dest] = 0;
                else
                {
                    if (a == 0)
                        floyd[start][dest] = b;
                    else if (b == 0)
                        floyd[start][dest] = a;
                    else
                        floyd[start][dest] = min(a, b);
                }
            }
        }
    }

    // 출발 지점에서 특정 노드로 이동 후에 계산해봐야함
    answer = floyd[s][a] + floyd[s][b];
    for (int nodeNum = 1; nodeNum < n + 1; nodeNum++)
    {
        if (nodeNum == s) continue;

        int sum = floyd[s][nodeNum] + floyd[nodeNum][a] + floyd[nodeNum][b];
        if (sum != 0)
            answer = min(answer, sum);
    }

    return answer;
}