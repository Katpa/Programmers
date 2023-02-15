#include <iostream>

using namespace std;

void SetRound(int& num)
{
    num = (num + 1) >> 1;
}

int solution(int n, int a, int b)
{
    int answer = 1;

    while (true)
    {
        SetRound(a);
        SetRound(b);

        if (a == b) break;

        answer++;
    }

    return answer;
}

int main()
{
    int n = 8;
    int a = 4;
    int b = 7;

    int answer = solution(n, a, b);

    return EXIT_SUCCESS;
}