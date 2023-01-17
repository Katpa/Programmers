#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    map<int, int> countMap;     //<size, count>
    int maxSize = 0;
    int count = 0;

    for (int num : tangerine)
    {
        countMap[num]++;
        if (maxSize < num)
            maxSize = num;
    }

    vector<int> vec;        // 사이즈만 담는다
    for (pair<int, int> m : countMap)
        vec.emplace_back(m.second);
    sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < maxSize; i++)
    {
        int remain = k - count;

        if (remain > vec[i])
        {
            count += vec[i];
            answer++;
        }
        else
        {
            answer++;
            break;
        }

        if (k == count)
            break;
    }

    return answer;
}

int main()
{
    int k = 6;
    vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };

    int answer = solution(k, tangerine);

    return EXIT_SUCCESS;
}