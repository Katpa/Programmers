#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;                         //���� ����� ����
    vector<bool> readyRelease;                  //���� �غ� �Ϸ� Ȯ�ο� ����
    int releasePointer = 0;                     //���� ���� ���� ����
    int todayReleaseCount;

    bool isLoop = true;

    for (int i = 0; i < progresses.size(); i++)
        readyRelease.push_back(false);

    while (isLoop)
    {
        todayReleaseCount = 0;

        //���൵ ���ϱ�
        for (int i = releasePointer; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
            if (progresses[i] >= 100)
                readyRelease[i] = true;
        }

        //���Ӽ� Ȯ�� �� ���� �غ�
        while (true)
        {
            if (readyRelease[releasePointer])
            {
                todayReleaseCount++;
                releasePointer++;
                if (releasePointer == progresses.size())
                {
                    isLoop = false;
                    break;
                }
            }
            else
            {
                break;
            }
        }

        //����
        if (todayReleaseCount > 0)
            answer.push_back(todayReleaseCount);
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    vector<int> answer = solution(progresses, speeds);

    return EXIT_SUCCESS;
}