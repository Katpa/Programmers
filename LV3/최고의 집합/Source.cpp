#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    answer.resize(n);

    int tmpNum = s / n;
    int tmpRem = s % n;
    for (int i = 0; i < n; i++)
    {
        answer[i] = tmpNum;
        if (tmpRem)
        {
            answer[i]++;
            tmpRem--;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    int n = 2;
    int s = 9;

    vector<int> answer = solution(n, s);

    return EXIT_SUCCESS;
}