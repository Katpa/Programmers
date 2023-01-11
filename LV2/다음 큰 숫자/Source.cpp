#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> binary;
    int startPos = 0;
    int endPos = 0;
    bool isEnd = false;
    int addNum = 1;
    int startToEnd;
    int startGap;

    while (n != 0)
    {
        if (n & 1)
            binary.push_back(1);
        else
            binary.push_back(0);

        n >>= 1;
    }

    endPos = binary.size() - 1;

    for (int i = 0; i < binary.size(); i++)
    {
        if (!isEnd)
        {
            if (binary[i])
            {
                isEnd = true;
                startPos = i;
            }
        }
        else
        {
            if (!binary[i])
            {
                endPos = i - 1;
                break;
            }
        }
    }

    startToEnd = endPos - startPos;
    startGap = startPos;

    if (endPos == binary.size() - 1)
        binary.push_back(0);

    if (startGap)
    {
        for (int i = 0; i < startToEnd; i++)
        {
            binary[startPos + i] = 0;
            binary[i] = 1;
        }
    }

    binary[endPos + 1] = 1;
    binary[endPos] = 0;

    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i])
            answer += addNum;

        addNum <<= 1;
    }

    return answer;
}

int main()
{
    int n = 78;
    int answer = solution(n);

	return EXIT_SUCCESS;
}