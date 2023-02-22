#include <string>
#include <vector>
#include <stack>

using namespace std;

const string nullStr = "";

void Seperate(string str, string& u, string& v);
int Func(char c);
string A(string str);
bool IsCorrect(string str);

string solution(string p)
{
    string answer = "";

    if (p.size() == 0) return answer;
    if (IsCorrect(p)) return p;

    answer = A(p);

    return answer;
}

bool IsCorrect(string str)
{
    stack<int> s;

    for (char c : str)
    {
        if (c == '(')
            s.push(1);
        else
        {
            if (s.empty()) return false;

            s.pop();
        }
    }

    return true;
}

string A(string str)
{
    if (str == nullStr) return nullStr;

    string output = "";
    string u = "", v = "";
    Seperate(str, u, v);

    if (IsCorrect(u))
    {
        output = u + A(v);
    }
    else
    {
        string tmp = "(" + A(v) + ")";
        u = string(u.begin() + 1, u.end() - 1);
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        output = tmp + u;
    }

    return output;
}

int Func(char c)
{
    if (c == '(')
        return 1;

    return -1;
}

void Seperate(string str, string& u, string& v)
{
    int i;
    int cnt = Func(str[0]);
    u.push_back(str[0]);

    for (i = 1; i < str.size(); i++)
    {
        if (cnt == 0) break;
        cnt += Func(str[i]);
        u.push_back(str[i]);
    }

    for (; i < str.size(); i++)
        v.push_back(str[i]);
}

int main()
{
    string p = "(()())()";

    string answer = solution(p);

    return EXIT_SUCCESS;
}