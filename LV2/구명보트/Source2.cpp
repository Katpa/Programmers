#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.rbegin(), people.rend());
    int lastNum = people.size() - 1;

    for (int i = 0; i < people.size(); i++)
    {
        if (i > lastNum) break;
        if (i == lastNum)
        {
            answer++;
            break;
        }

        if (people[i] + people[lastNum] <= limit)
            lastNum--;

        answer++;
    }

    return answer;
}