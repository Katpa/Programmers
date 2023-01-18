#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dungeonList;
unsigned int maxDungeonCount = 0;

void EnterTheDungeon(int curFatigue, int nextDungeonNum, vector<int> remainDungeons)
{
    if (curFatigue >= dungeonList[nextDungeonNum][0])
    {
        curFatigue -= dungeonList[nextDungeonNum][1];

        for (int i = 0; i < remainDungeons.size(); i++)
        {
            if (remainDungeons[i] == nextDungeonNum)
            {
                remainDungeons.erase(remainDungeons.begin() + i);
                break;
            }
        }


        if (dungeonList.size() - remainDungeons.size() > maxDungeonCount)
        {
            maxDungeonCount = dungeonList.size() - remainDungeons.size();
        }

        for (int num : remainDungeons)
        {
            EnterTheDungeon(curFatigue, num, remainDungeons);
        }
    }
    else
    {
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonList = dungeons;
    vector<int> remainDungeons;
    for (int i = 0; i < dungeons.size(); i++)
        remainDungeons.push_back(i);

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (maxDungeonCount == dungeons.size())
            return maxDungeonCount;

        EnterTheDungeon(k, i, remainDungeons);
    }

    return maxDungeonCount;
}

int main()
{
    int k = 80;
    vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };

    int answer = solution(k, dungeons);

    return EXIT_SUCCESS;
}