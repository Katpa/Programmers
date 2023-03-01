#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> vec;

    long long lq = left / n + 1;
    long long lr = left % n;

    long long rq = right / n + 1;
    long long rr = right % n + 1;

    for (int i = lq; i <= rq; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            vec.push_back(i);
        }

        j++;

        while (j <= n)
        {
            vec.push_back(j);
            j++;
        }
    }

    vector<int> answer(vec.begin() + lr, vec.begin() + (rq - lq) * n + rr);

    return answer;
}

int main()
{
    int n = 3;
    long long left = 2;
    long long right = 5;

    vector<int> answer = solution(n, left, right);

    return EXIT_SUCCESS;
}