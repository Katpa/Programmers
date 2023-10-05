#include <vector>

using namespace std;

void SetAnswer(int cnt, int& answer, int netSize)
{
    if (cnt <= 0) return;

    int tmpNum = cnt / netSize;
    if (cnt % netSize)
        tmpNum++;
    answer += tmpNum;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int p = 0;
    int netSize = w * 2 + 1;

    for (int num : stations)
    {
        int emptySize = num - w - p - 1;
        p = num + w;

        SetAnswer(emptySize, answer, netSize);
    }

    if (p < n)
    {
        int emptySize = n - p;
        SetAnswer(emptySize, answer, netSize);
    }

    return answer;
}

/*
Extra testcase
13 [3, 7, 11] 1 4
5 [3] 2 0
6 [3] 2 1
16 [1, 16] 2 2
6 [4] 2 1
11 [1, 4] 1 2
11 [1, 5] 1 3
*/