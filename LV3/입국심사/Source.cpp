#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    int officers = times.size();
    sort(times.begin(), times.end());
    long long maxTime = times[officers - 1] * static_cast<long long>(n);
    long long minTime = 1;
    long long curTime;

    while (minTime <= maxTime)
    {
        curTime = (maxTime + minTime) >> 1;
        long totalPerson = 0;

        for (int iter = 0; iter < officers; iter++)
        {
            auto person = curTime / times[iter];
            totalPerson += person;
        }

        if (totalPerson >= n)
        {
            answer = curTime;
            maxTime = curTime - 1;
        }
        else
        {
            minTime = curTime + 1;
        }
    }

    return answer;
}