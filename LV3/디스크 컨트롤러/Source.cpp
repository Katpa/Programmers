#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    sort(jobs.begin(), jobs.end());

    int idx = 0;
    int curTime = 0;
    int orderTime = 0;
    int endTime = -1;
    priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;

    while (true)
    {
        while (true)
        {
            if (idx == jobs.size()) break;
            if (jobs[idx][0] > curTime) break;

            pq.push(jobs[idx]);
            idx++;
        }

        // 진행중인 작업 완료
        if (endTime == curTime)
        {
            answer += curTime - orderTime;
        }

        // 새작업 착수
        if (endTime <= curTime && !pq.empty())
        {
            vector<int> work = pq.top();
            pq.pop();
            orderTime = work[0];
            endTime = curTime + work[1];
        }

        if (curTime == endTime && idx == jobs.size()) break;

        curTime++;
    }

    return answer / jobs.size();
}