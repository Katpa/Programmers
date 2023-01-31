#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long Calculator(long long num1, long long num2, char ch)
{
    switch (ch)
    {
    case '+':
        return num1 + num2;
    case '*':
        return num1 * num2;
    case '-':
        return num1 - num2;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> cal;
    string str = "";
    map<char, char> m;
    vector<char> calOrder;

    for (char ch : expression)
    {
        if (ch == '-' || ch == '*' || ch == '+')
        {
            cal.push_back(ch);
            nums.push_back(stoi(str));
            str = "";
            m[ch] = ch;
        }
        else
            str += ch;
    }
    nums.push_back(stoi(str));

    for (pair<char, char> ch : m)
        calOrder.push_back(ch.second);

    do
    {
        vector<long long> tmpVec = nums;
        vector<char> tmpCal = cal;

        for (int i = 0; i < calOrder.size(); i++)
        {
            for (int j = 0; j < tmpCal.size(); j++)
            {
                if (tmpCal[j] != calOrder[i]) continue;

                tmpVec[j] = Calculator(tmpVec[j], tmpVec[j + 1], tmpCal[j]);
                tmpVec.erase(tmpVec.begin() + j + 1);
                tmpCal.erase(tmpCal.begin() + j);
                j--;
            }
        }
        if (tmpVec[0] < 0)
            tmpVec[0] *= -1;

        if (tmpVec[0] > answer)
            answer = tmpVec[0];

    } while (next_permutation(calOrder.begin(), calOrder.end()));

    return answer;
}

int main()
{
    string expression = "100-200*300-500+20";

    long long answer = solution(expression);

    return EXIT_SUCCESS;
}