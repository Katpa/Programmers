#include <string>
#include <queue>
#include <vector>

using namespace std;

string solution(string s)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	string tmpStr = "";
	s.push_back(' ');

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			pq.push(stoi(tmpStr));
			tmpStr = "";
			continue;
		}

		tmpStr.push_back(s[i]);
	}

	string answer = to_string(pq.top()) + " ";
	while (pq.size() > 1)
		pq.pop();

	answer += to_string(pq.top());

	return answer;
}

int main()
{
	string s = "1 2 3 4";

	string answer = solution(s);

	return EXIT_SUCCESS;
}