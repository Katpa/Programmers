#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int f1 = 0, f2 = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int nextNum = (f1 + f2) % 1234567;
        f1 = f2;
        f2 = nextNum;
    }

    answer = f2;

    return answer;
}

int main()
{
    int n = 3;
    int answer = solution(n);

    return EXIT_SUCCESS;
}