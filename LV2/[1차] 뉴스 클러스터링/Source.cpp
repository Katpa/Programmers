#include <string>
#include <queue>
#include <map>

using namespace std;

const int GAP = 'a' - 'A';

void IsUsable(char& a)
{
    if (a >= 'a' && a <= 'z')
        a -= GAP;
    else if (a >= 'A' && a <= 'Z')
        a;
    else
        a = '0';
}

int solution(string str1, string str2) {
    int answer = 0;
    queue<char> q1, q2;
    map<string, int> m1, m2;

    int overlap = 0;
    int sum = 0;

    for (int i = 0; i < str1.size(); i++)
    {
        IsUsable(str1[i]);
        q1.push(str1[i]);
    }

    for (int i = 0; i < str2.size(); i++)
    {
        IsUsable(str2[i]);
        q2.push(str2[i]);
    }

    while (q1.size() > 1)
    {
        string tmpStr = "";
        char tmp = q1.front();
        q1.pop();
        tmpStr += tmp;
        tmpStr += q1.front();

        if (tmpStr[0] == '0' || tmpStr[1] == '0') continue;

        m1[tmpStr]++;
    }

    while (q2.size() > 1)
    {
        string tmpStr = "";
        char tmp = q2.front();
        q2.pop();
        tmpStr += tmp;
        tmpStr += q2.front();

        if (tmpStr[0] == '0' || tmpStr[1] == '0') continue;

        m2[tmpStr]++;
    }

    if (m1.size() == 0 && m2.size() == 0)
        return 65536;
    if (m1.size() == 0 && m2.size() > 0)
        return 0;

    for (pair<string, int> p1 : m1)
    {
        for (pair<string, int> p2 : m2)
        {
            if (p1.first != p2.first) continue;

            overlap += min(p1.second, p2.second);
            break;
        }

        sum += p1.second;
    }

    for (pair<string, int> p2 : m2)
        sum += p2.second;

    sum -= overlap;

    double tmp = static_cast<double>(overlap) / static_cast<double>(sum);
    answer = static_cast<int>(tmp * 65536.0f);

    return answer;
}

int main()
{
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";

    int answer = solution(str1, str2);

    return EXIT_SUCCESS;
}