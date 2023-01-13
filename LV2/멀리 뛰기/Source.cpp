#include <string>
#include <vector>

using namespace std;

long long fibonacci[2001] = { 0 };

long long solution(int n)
{
    fibonacci[0] = 1;
    fibonacci[1] = 2;

    for (int i = 2; i < n; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;

    return fibonacci[n - 1];
}

int main()
{
    int n = 4;
    long long answer = solution(n);

    return EXIT_SUCCESS;
}