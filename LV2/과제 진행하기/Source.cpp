#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Plan
{
    string subject;
    int startTime;
    int playingTime;

    int GetEndTime() { return startTime + playingTime; }
    bool operator<(const Plan p) const { return this->startTime > p.startTime; }
};

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer(plans.size());
    priority_queue<Plan> pq;
    stack<Plan> s;
    int idx = 0;

    for (vector<string> vec : plans)
    {
        string subject = vec[0];
        int startTime = stoi(vec[1].substr(0, 2)) * 60 + stoi(vec[1].substr(3, 5));
        int playingTime = stoi(vec[2]);
        Plan plan = { subject, startTime, playingTime };
        pq.push(plan);
    }

    s.push(pq.top());
    pq.pop();

    while (!pq.empty())
    {
        if (s.empty() || s.top().GetEndTime() > pq.top().startTime)
        {
            s.push(pq.top());
            pq.pop();
        }
        else
        {
            answer[idx] = s.top().subject;
            int pt = s.top().playingTime;
            s.pop();
            idx++;

            if (!s.empty())
            {
                int& tmp = s.top().playingTime;
                tmp += pt;
            }
        }
    }

    while (!s.empty())
    {
        Plan sTop = s.top();
        s.pop();
        answer[idx] = sTop.subject;
        idx++;
    }

    return answer;
}