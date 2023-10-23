#include <string>

using namespace std;
string str;

bool IsPalin(int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end]) return false;

        start++;
        end--;
    }

    return true;
}

int solution(string s)
{
    int answer = 0;
    int size = s.size();
    str = s;

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++)
        {
            int start = j;
            int end = j + i;
            if (IsPalin(start, end)) return i + 1;
        }
    }

    return answer + 1;
}