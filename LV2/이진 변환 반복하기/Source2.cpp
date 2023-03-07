#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(string s)
{
	int zero = 0; int loopCount = 0;
	
	while (s != "1")
	{
		vector<char> fix;
		stack<int> st;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0')
			{
				zero++;
				continue;
			}
			fix.push_back('1');
		}

		int num = fix.size();

		while (num > 0)
		{
			int r = num % 2;
			st.push(r);
			num /= 2;
		}

		s = "";
		while (!st.empty())
		{
			s.push_back(st.top() + '0');
			st.pop();
		}
		loopCount++;
	}

	return { loopCount, zero };
}