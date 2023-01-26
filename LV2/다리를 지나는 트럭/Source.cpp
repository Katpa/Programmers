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

        //다리에서 내려오는거 구현 부분
        if (!startTime.empty())
        {
            if (time == startTime.front() + bridge_length)
            {
                weightSum -= onBridge.front();
                onBridge.pop();
                startTime.pop();
            }
        }

        //다리에 올라서는 부분
        if (weightSum + truck_weights[truckIndex] <= weight)
        {
            weightSum += truck_weights[truckIndex];
            onBridge.push(truck_weights[truckIndex]);
            startTime.push(time);

            truckIndex++;
        }
        else
        {
            //더이상 트럭이 오를 수 없는 경우, 시간을 앞당긴다
            time = startTime.front() + bridge_length - 1;
        }

        //마지막 트럭이 출발했는지 체크하는 부분
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