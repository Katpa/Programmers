#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> strStack;

    for (char ch : s)
    {
        if (strStack.empty())
            strStack.push(ch);
        else if (ch == strStack.top())
            strStack.pop();
        else
            strStack.push(ch);
    }

    if (strStack.empty())
        return 1;
    else
        return 0;
}

int main()
{
    string s = "baabaa";
    int answer = solution(s);

    return EXIT_SUCCESS;
}