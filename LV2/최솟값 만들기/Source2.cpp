#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	priority_queue<int> pqA;
	priority_queue<int, vector<int>, greater<int>> pqB;

	for (int i = 0; i < A.size(); i++)
	{
		pqA.push(A[i]);
		pqB.push(B[i]);
	}

	for (int i = 0; i < A.size(); i++)
	{
		answer += pqA.top() * pqB.top();
		pqA.pop(); pqB.pop();
	}

	return answer;
}