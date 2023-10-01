#include <string>
#include <vector>
#include <algorithm>

#define START 0
#define END 1

using namespace std;

bool Cmp(const vector<int> a, const vector<int> b) { return a[START] < b[START] ? true : false; }

int solution(vector<vector<int>> targets)
{
    int answer = 1;
    sort(targets.begin(), targets.end(), Cmp);

    int end = targets[0][END];

    for (int iter = 1; iter < targets.size(); iter++)
    {
        if (end > targets[iter][START])
            end = min(end, targets[iter][END]);
        else
        {
            end = targets[iter][END];
            answer++;
        }
    }

    return answer;
}