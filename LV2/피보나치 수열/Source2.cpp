#include <string>
#include <vector>

using namespace std;

int dp[100001];

int DP(int n)
{
	if (dp[n] != 0) return dp[n];

	return dp[n] = (DP(n-1) + DP(n-2)) % 1234567;
}

int solution(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	return DP(n);
}