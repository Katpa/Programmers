#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();

    vector<int> answer(size);
    stack<int> times;

    for (int i = 0; i < size; i++)
    {
        //°¡°ÝÀÌ ¶³¾îÁü
        while (!times.empty() && prices[i] < prices[times.top()])
        {
            answer[times.top()] = i - times.top();
            times.pop();
        }

        times.push(i);
    }

    while (!times.empty())
    {
        answer[times.top()] = size - 1 - times.top();
        times.pop();
    }

    return answer;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };

    vector<int> answer = solution(prices);

    return EXIT_SUCCESS;
}