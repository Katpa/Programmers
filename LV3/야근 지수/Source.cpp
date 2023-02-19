#include <string>
#include <vector>
#include<queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());

    while (n > 0)
    {
        if (q.top() > 0)
        {
            int tmp = q.top();
            q.pop();
            q.push(tmp - 1);

            n--;
        }
        else
        {
            break;
        }
    }

    while (q.size() > 0)
    {
        answer += q.top() * q.top();
        q.pop();
    }

    return answer;
}

int main()
{
    vector<int> works = { 4, 3, 3 };
    int n = 4;

    long long answer = solution(n, works);

    return EXIT_SUCCESS;
}