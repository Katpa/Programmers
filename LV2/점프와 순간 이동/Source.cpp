#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    while (n)
    {
        if (n & 1)
        {
            answer++;
            n--;
        }
        else
            n >>= 1;
    }

    return answer;
}

int main()
{
    int n = 5;

    int answer = solution(n);

    return EXIT_SUCCESS;
}