#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> s;

    for (int i = 0; i < numbers.size(); i++)
    {
        while (!s.empty() && s.top().second < numbers[i])
        {
            answer[s.top().first] = numbers[i];
            s.pop();
        }

        s.push(make_pair(i, numbers[i]));
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 2, 3, 3, 5 };

    vector<int> answer = solution(numbers);

    return 0;
}