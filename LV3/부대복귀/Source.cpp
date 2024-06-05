#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#define UNCONNECT -1

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> srcs, int dest)
{
	vector<int> answer;
	vector<int> distFromDest(n + 1, UNCONNECT);
	distFromDest[dest] = 0;
	queue<int> q;
	q.push(dest);

	unordered_map<int, vector<int>> um;
	vector<bool> visited(n + 1, false);
	visited[dest] = true;

	for (vector<int> vec : roads)
	{
		um[vec[0]].push_back(vec[1]);
		um[vec[1]].push_back(vec[0]);
	}

	while (q.size())
	{
		int checkNum = q.front();
		q.pop();

		for (int pos : um[checkNum])
		{
			if (visited[pos]) continue;

			q.push(pos);
			distFromDest[pos] = distFromDest[checkNum] + 1;
			visited[pos] = true;
		}
	}

	for (int agent : srcs)
	{
		answer.push_back(distFromDest[agent]);
	}

	return answer;
}