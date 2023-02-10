#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    map<string, int> m;

    for (int i = 0; i < gems.size(); i++)
        m[gems[i]]++;

    int cnt = m.size();
    bool isLoop = true;
    int curStart = 0, curEnd = cnt - 1;
    int start = curStart, end = gems.size();

    // while문 안에서 erase가 시간 복잡도 높아서 안쓰려고 매번 map을 재생성해서 썼는데
    // 오히려 이럴 때에는 erase 쓰는게 효율이 더 높음
    map<string, int> curArray;
    for (int i = curStart; i <= curEnd; i++)
        curArray[gems[i]]++;

    while (isLoop)
    {
        if (curArray.size() == cnt)
        {
            if (curEnd - curStart < end - start)
            {
                start = curStart;
                end = curEnd;
            }
            if (--curArray[gems[curStart]] == 0)
                curArray.erase(gems[curStart]);
            curStart++;
        }
        else
        {
            curEnd++;
            if (curEnd != gems.size())
                curArray[gems[curEnd]]++;
        }

        if (curEnd == gems.size())
            isLoop = false;
    }

    answer.push_back(start + 1);
    answer.push_back(end + 1);

    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };

    vector<int> answer = solution(gems);

    return EXIT_SUCCESS;
}