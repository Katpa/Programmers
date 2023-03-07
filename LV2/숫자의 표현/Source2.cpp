#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;

	for (int i = 1; i <= (n >> 1); i++)
	{
		int sum = 0;
		int curNum = i;

		while (sum < n)	sum += curNum++;

		if (sum == n) answer++;
	}

	return answer + 1;
}