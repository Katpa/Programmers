#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= (n >> 1); i++)
    {
        int sum = 0;
        int curNum = i;

        while (sum < n)
        {
            sum += curNum;
            curNum++;
        }

        if (sum == n)
        {
            answer++;
        }
    }

    return answer + 1;
}

int main()
{
    int n = 15;
    int answer = solution(n);

    return EXIT_SUCCESS;
}