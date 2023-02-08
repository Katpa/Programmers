#include <string>
#include <vector>

using namespace std;

vector<int> dp;

int DP(int num, int coin)
{
    if (coin > num) return dp[num];

    return dp[num] += dp[num - coin];
}


int solution(int n, vector<int> money)
{
    dp.resize(n + 1);
    dp[0] = 1;

    for (int num : money)
    {
        for (int i = 0; i <= n; i++)
            DP(i, num);
    }

    return dp[n];
}

int main()
{
    int n = 5;
    vector<int> money = { 1, 2, 5 };

    int answer = solution(n, money);

    return EXIT_SUCCESS;
}