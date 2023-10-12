#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    map<int, int> cnt;
    int size = 0;
    string numStr = "";

    for (int iter = 1; iter < s.size() - 1; iter++)
    {
        if (s[iter] >= '0' && s[iter] <= '9')
        {
            numStr += s[iter];
        }
        else if (numStr.size())
        {
            cnt[stoi(numStr)]++;
            numStr = "";
        }


        if (s[iter] == '}')
            size++;
    }

    answer.resize(size);

    for (pair<int, int> numSet : cnt)
        answer[size - numSet.second] = numSet.first;

    return answer;
}