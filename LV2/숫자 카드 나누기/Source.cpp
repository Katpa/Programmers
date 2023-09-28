#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int GetGCD(vector<int> array)
{
    int num = array[0];
    for (int iter = 1; iter < array.size(); iter++)
    {
        num = GCD(num, array[iter]);
    }

    return num;
}

bool IsAnswer(vector<int>& array, int num)
{
    for (int n : array)
    {
        if (n % num == 0)
            return false;
    }

    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;
    int A = GetGCD(arrayA);
    int B = GetGCD(arrayB);

    if (A != 1 && IsAnswer(arrayB, A)) answer = A;
    if (B != 1 && IsAnswer(arrayA, B)) answer = max(answer, B);

    return answer;
}