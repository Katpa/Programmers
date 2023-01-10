#include <string>

using namespace std;

bool solution(string s)
{
    int countNum = 0;

    for (char ch : s)
    {
        if (ch == '(')
            countNum++;
        else
            countNum--;

        if (countNum < 0)
            return false;
    }

    return countNum == 0;
}

int main()
{
    string s = "()()";
    bool answer = solution(s);

    return EXIT_SUCCESS;
}