#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;                         //정답 제출용 벡터
    vector<bool> readyRelease;                  //배포 준비 완료 확인용 벡터
    int releasePointer = 0;                     //배포 지점 저장 변수
    int todayReleaseCount;

    bool isLoop = true;

    for (int i = 0; i < progresses.size(); i++)
        readyRelease.push_back(false);

    while (isLoop)
    {
        todayReleaseCount = 0;

        //진행도 더하기
        for (int i = releasePointer; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
            if (progresses[i] >= 100)
                readyRelease[i] = true;
        }

        //연속성 확인 및 배포 준비
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

        //배포
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