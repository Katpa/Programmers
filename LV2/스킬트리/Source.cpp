#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (string str : skill_trees)
    {
        bool isAnswer = true;
        int index = 0;

        for (char ch : str)
        {
            if (ch == skill[index])
            {
                index++;
                continue;
            }
            else
            {
                for (int i = index + 1; i < skill.size(); i++)
                {
                    if (skill[i] == ch)
                    {
                        isAnswer = false;
                        break;
                    }
                }
            }

            if (!isAnswer)
                break;
        }

        if (isAnswer)
            answer++;
    }

    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

    int answer = solution(skill, skill_trees);

    return EXIT_SUCCESS;
}