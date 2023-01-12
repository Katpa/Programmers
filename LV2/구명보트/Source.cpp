#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    vector<bool> usage;
    usage.resize(people.size());
    int lastNum = people.size() - 1;

    for (bool tmpVar : usage)
        tmpVar = false;

    for (int i = 0; i < people.size(); i++)
    {
        if (usage[i]) continue;

        int sum = people[i];

        if (sum + people[lastNum] <= limit)
        {
            usage[lastNum] = true;
            lastNum--;
        }

        usage[i] = true;
        answer++;

        if (lastNum <= i)
            break;
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;
    int answer = solution(people, limit);

    return EXIT_SUCCESS;
}