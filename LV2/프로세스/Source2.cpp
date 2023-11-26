#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int order = 0;
    queue<int> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(priorities[i]);
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        int qNum = q.front();
        int pqNum = pq.top();

        q.pop();

        if (qNum == pqNum)
        {
            order++;
            pq.pop();

            if (location == 0)
                return order;
        }
        else
        {
            q.push(qNum);
        }

        location--;
        if (location < 0)
            location += q.size();
    }

    return order;
}