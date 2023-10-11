#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    map<int, int> comb;
    int size = 0;

    for (int iter = 1; iter < s.size() - 1; iter++)
    {
        if (s[iter] != '{') continue;

        bool isLoop = true;
        string numStr = "";
        size++;
        while (isLoop)
        {
            iter++;
            if (s[iter] == '}')
            {
                isLoop = false;

                if (numStr.size() == 0) continue;
                int num = stoi(numStr);
                numStr = "";
                comb[num]++;
            }
            else if (s[iter] == ',')
            {
                int num = stoi(numStr);
                numStr = "";
                comb[num]++;
            }
            else
            {
                numStr += s[iter];
            }
        }
    }

    answer.resize(size);

    for (pair<int, int> numSet : comb)
        answer[size - numSet.second] = numSet.first;

    return answer;
}