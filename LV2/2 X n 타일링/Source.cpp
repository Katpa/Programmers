#include <string>
#include <vector>

using namespace std;

vector<long long int> dp;

int TopDown(int n)
{
    if (n < 2)
    {
        dp[n] = 1;
        return dp[n];
    }

    if (dp[n] > 1) return dp[n];

    dp[n] = (TopDown(n - 1) + TopDown(n - 2)) % 1000000007;

    return dp[n];
}

int solution(int n)
{
    dp.resize(n + 1);
    long long int answer = TopDown(n);

    answer %= 1000000007;

    return answer;
}

int main()
{
    int n = 4;

    int answer = solution(n);

    return EXIT_SUCCESS;
}