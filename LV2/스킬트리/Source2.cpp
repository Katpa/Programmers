#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    unordered_map<char, int> m;
    const int maxNum = skill.size();

    for (int iter = 0; iter < maxNum; iter++)
        m[skill[iter]] = iter;

    for (int iter = 0; iter < skill_trees.size(); iter++)
    {
        int order = 0;
        bool isAnswer = true;

        for (int i = 0; i < skill_trees[iter].size(); i++)
        {
            if (order == maxNum)
                break;

            if (skill_trees[iter][i] == skill[order])
            {
                order++;
                continue;
            }

            if (m[skill_trees[iter][i]])
            {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer)
            answer++;
    }

    return answer;
}