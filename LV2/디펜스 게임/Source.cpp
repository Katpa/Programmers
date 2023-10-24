#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;
    priority_queue<int, vector<int>> pq;

    for (int e : enemy)
    {
        pq.push(e);

        if (n >= e)
        {
            n -= e;
        }
        else if (k)
        {
            k--;
            n += pq.top() - e;
            pq.pop();
        }
        else
            break;

        answer++;
    }

    return answer;
}