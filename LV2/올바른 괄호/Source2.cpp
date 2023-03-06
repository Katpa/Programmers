#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (st.empty()) return false;

			st.pop();
			continue;
		}

		st.push(s[i]);
	}

	if(st.empty())
		return true;
	
	return false;
}

int main()
{
	string s = "(())()";

	bool answer = solution(s);

	return EXIT_SUCCESS;
}