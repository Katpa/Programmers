#include <string>
#include <vector>
#include <stack>

using namespace std;

bool Check(string str)
{
    //초기에 해본 방법
    //int small = 0, middle = 0, big = 0;

    //for (int i = 0; i < s.size(); i++)
    //{
    //    switch (s[i])
    //    {
    //    case '(':
    //        small++;
    //        break;
    //    case ')':
    //        small--;
    //        break;
    //    case '{':
    //        middle++;
    //        break;
    //    case '}':
    //        middle--;
    //        break;
    //    case '[':
    //        big++;
    //        break;
    //    case ']':
    //        big--;
    //        break;
    //    }
    //    if (small < 0 || middle < 0 || big < 0) return false;
    //}
    //
    //return true;

    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        switch (str[i])
        {
        case '(':
        case '{':
        case '[':
            s.push(str[i]);
            break;
        case ')':
            if (s.empty()) return false;
            if (s.top() != '(') return false;
            s.pop();
            break;
        case '}':
            if (s.empty()) return false;
            if (s.top() != '{') return false;
            s.pop();
            break;
        case ']':
            if (s.empty()) return false;
            if (s.top() != '[') return false;
            s.pop();
            break;
        }
    }

    if (s.empty())
        return true;

    return false;
}

int solution(string s) {
    int answer = 0;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        string tmpStr = "";

        for (int j = 0; j < s.size(); j++)
            tmpStr.push_back(s[(i + j) % size]);

        if (Check(tmpStr)) answer++;
    }

    return answer;
}

int main()
{
    string s = "[](){}";

    int answer = solution(s);

    return EXIT_SUCCESS;
}