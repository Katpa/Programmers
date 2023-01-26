#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> onBridge;
    queue<int> startTime;
    int weightSum = 0;
    int truckIndex = 0;
    int time = 0;
    bool isLoop = true;

    while (isLoop)
    {
        time++;

        //�ٸ����� �������°� ���� �κ�
        if (!startTime.empty())
        {
            if (time == startTime.front() + bridge_length)
            {
                weightSum -= onBridge.front();
                onBridge.pop();
                startTime.pop();
            }
        }

        //�ٸ��� �ö󼭴� �κ�
        if (weightSum + truck_weights[truckIndex] <= weight)
        {
            weightSum += truck_weights[truckIndex];
            onBridge.push(truck_weights[truckIndex]);
            startTime.push(time);

            truckIndex++;
        }
        else
        {
            //���̻� Ʈ���� ���� �� ���� ���, �ð��� �մ���
            time = startTime.front() + bridge_length - 1;
        }

        //������ Ʈ���� ����ߴ��� üũ�ϴ� �κ�
        if (truckIndex == truck_weights.size())
            isLoop = false;
    }

    return time + bridge_length;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    int answer = solution(bridge_length, weight, truck_weights);

    return EXIT_SUCCESS;
}