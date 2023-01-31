#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> candidate;
map<string, int> combList;
int maxCount[11] = { 0 };

void DFS(const int limit, int curLength, int curPos, string order, string curStr)
{
    if (order.size() <= curPos) return;

    curStr += order[curPos];
    curPos++;
    curLength++;

    if (limit == curLength)
    {
        sort(curStr.begin(), curStr.end());

        if (combList.find(curStr) != combList.end())
        {
            if (curStr == "AB")
                int q = 10;
            combList[curStr]++;
        }
        else
        {
            candidate.push_back(curStr);
            combList[curStr] = 1;
        }

        maxCount[limit] = max(maxCount[limit], combList[curStr]);

        return;
    }

    for (int i = curPos; i < order.size(); i++)
    {
        DFS(limit, curLength, i, order, curStr);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<int> newCourse;

    for (int num : course)
    {
        int count = 0;
        for (string str : orders)
        {
            if (str.length() >= num)
                count++;

            if (count == 2)
            {
                newCourse.push_back(num);
                break;
            }
        }
    }

    vector<string> answer;

    for (int limit : newCourse)
    {
        for (string order : orders)
        {
            if (limit > order.size()) continue;

            for (int i = 0; i < order.size(); i++)
            {
                DFS(limit, 0, i, order, "");
            }
        }
    }

    for (int limit : newCourse)
    {
        for (string comb : candidate)
        {
            if (maxCount[limit] == combList[comb] && comb.size() == limit && combList[comb] > 1)
                answer.push_back(comb);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };

    vector<string> answer = solution(orders, course);

    return EXIT_SUCCESS;
}